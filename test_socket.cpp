#include "test_socket.h"

extern const unsigned int SERVER_PORT = 200;
unsigned int test_socket::current_connection = 0;
shared_ptr<server> test_socket::m_server = make_shared<server>(AF_INET, SOCK_STREAM, IPPROTO_TCP, SERVER_PORT);
shared_ptr<list<int>> test_socket::clients = make_shared<list<int>>();
shared_ptr<list<shared_ptr<pthread_t>>> test_socket::work_threads = make_shared<list<shared_ptr<pthread_t>>>();
pthread_mutex_t test_socket::clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void test_socket::test_socket_fun()
{	
	cout << "Server socket created sucessfully..." << endl;
	if( m_server->initialize() == 0 )
	{
		pthread_t pick_up_thread;
		pthread_create(&pick_up_thread, NULL, test_socket::pick_up_clients, NULL);
		pthread_t listen_thread;
		pthread_create(&listen_thread, NULL, test_socket::accept_clients, NULL);
		pthread_join(pick_up_thread, NULL);
		pthread_join(listen_thread, NULL);
	}

}

void* test_socket::accept_clients(void* data)
{
	while(true)
	{
		cout << "Waiting for connection..." << endl;
		int client = m_server->accept_connection();
		cout << "Accepted a new client..." << endl;
		if ( client >= 0 )
		{
			if( current_connection < max_connection )
			{
				cout << "One client connected successfully." << endl;
				pthread_mutex_lock(&test_socket::clients_mutex);
				test_socket::clients->push_back(client);
				pthread_mutex_unlock(&test_socket::clients_mutex);
			}
			else
			{
				cout << "One client is connecting, but the connection count is the max value." <<endl;
				process_max_connection(client);
			}
		}
	}
	return NULL;
}

int test_socket::release_resource()
{
	int release_result = pthread_mutex_destroy(&test_socket::clients_mutex);
	return release_result;
}

void* test_socket::pick_up_clients(void* data)
{
	fd_set fds;
	int max_socket = 0;
	struct timeval time_vl;
	time_vl.tv_sec = 30;
	time_vl.tv_usec = 0;
	while(true)
	{
		if(test_socket::clients->empty())
		{
			continue;
		}
		FD_ZERO(&fds);
		for(int sock : *test_socket::clients)
		{
			if(sock > max_socket)
			{
				max_socket = sock;
			}
			FD_SET(sock, &fds);
		}
		cout << "Watching all client sockets..." << endl;
		int result = select(max_socket + 1, &fds, NULL, NULL, &time_vl);
		switch(result)
		{
			case -1:
				cout << "Select clients error : " << errno << endl;
				break;
			case 0:
				cout << "Watching time out..." << endl;
				break;
			default:
				cout << "Some client may sent message, ready to process..." << endl;
				test_socket::process_message(&fds);
				break;
		}
	}
}

void test_socket::process_message(const fd_set* const fds)
{
	pthread_t process_message_thread;
	pthread_create(&process_message_thread, NULL, test_socket::process_client_msg, (void*)fds);
}

void* test_socket::process_client_msg(void* data)
{
	fd_set *pfds = static_cast<fd_set*>(data);
	for(auto client : *test_socket::clients)
	{
		if ( FD_ISSET(client, pfds ) )
		{
			char msg_buff[test_socket::max_msg_length];
			memset(msg_buff, 0, test_socket::max_msg_length);
			if(recv(client, msg_buff, test_socket::max_msg_length,0) < 0)
			{
				cout << "Recieve message error." << endl;
			}
			else
			{
				test_socket::process_single_msg(msg_buff);
			}
		}
	}
}

void test_socket::process_single_msg(const char* msg)
{
	cout << msg << endl;
}

void test_socket::process_max_connection(int client)
{
	
}

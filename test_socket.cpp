#include "test_socket.h"

extern const unsigned int SERVER_PORT = 200;
shared_ptr<server> test_socket::m_server = make_shared<server>(AF_INET, SOCK_STREAM, IPPROTO_TCP, SERVER_PORT);
shared_ptr<vector<int>> test_socket::clients = make_shared<vector<int>>();
shared_ptr<vector<shared_ptr<pthread_t>>> test_socket::work_threads = make_shared<vector<shared_ptr<pthread_t>>>();
pthread_mutex_t test_socket::clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void test_socket::test_socket_fun()
{	
	//m_server = make_shared<server>(AF_INET, SOCK_STREAM, IPPROTO_TCP, SERVER_PORT);
    	//server local_server{AF_INET, SOCK_STREAM, IPPROTO_TCP, SERVER_PORT};
	cout << "Server socket created sucessfully..." << endl;
	if( m_server->initialize() == 0 )
	{
		pthread_t listen_thread;
		pthread_create(&listen_thread, NULL, test_socket::accept_clients, NULL);
		pthread_join( listen_thread, NULL );
		//this->accept_clients();
	}

}

void* test_socket::accept_clients(void* data)
{
	while(true)
	{
		cout << "Server initialized sucessfully..." << endl;
		int client = m_server->accept_connection();
		cout << "Accept finished..." << endl;
		if ( client >= 0 )
		{
			cout << "One client connected successfully." << endl;
			pthread_mutex_lock(&test_socket::clients_mutex);
			test_socket::clients->push_back(client);
			pthread_mutex_unlock(&test_socket::clients_mutex);
		}
	}
	return NULL;
}

int test_socket::release_resource()
{
	int release_result = pthread_mutex_destroy(&test_socket::clients_mutex);
	return release_result;
}

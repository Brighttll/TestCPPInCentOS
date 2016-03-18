#pragma once
#include "header/server.h"
#include "Globals.h"
class test_socket
{
public:
	static void test_socket_fun();
	static int release_resource();
private:
	const static unsigned int max_msg_length = 500;
	const static unsigned int max_connection = 500;
	static unsigned int current_connection;
	static shared_ptr<server> m_server;
	static void* accept_clients(void*);
	static shared_ptr<list<int>> clients;
	static pthread_mutex_t clients_mutex;
	static shared_ptr<list<shared_ptr<pthread_t>>> work_threads;
	static void* process_client_msg(void*);
	static void* pick_up_clients(void*);
	static void process_max_connection(int client);
	static void process_message(const fd_set* const fds);
	static void process_single_msg(const char* msg); 
};

#pragma once
#include "header/server.h"
#include "Globals.h"
class test_socket
{
public:
	static void test_socket_fun();
	static int release_resource();
private:
	static shared_ptr<server> m_server;
	static void* accept_clients(void*);
	static shared_ptr<vector<int>> clients;
	static pthread_mutex_t clients_mutex;
	static shared_ptr<vector<shared_ptr<pthread_t>>> work_threads;
};

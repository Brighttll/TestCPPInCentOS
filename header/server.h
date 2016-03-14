#pragma once
#include "../Globals.h"
#include "server_sock.h"

class server
{
private:
	server_sock server_socket;
//	shared_ptr<server_sock> server_socket = nullptr;
public:
	server(int af, int type, int protocol, unsigned int port):server_socket(af, type, protocol, port)
	{
//		this->server_socket = make_shared<server_sock>(af, type, protocol, port);
	};
	virtual ~server()
	{
		
	};
	int initialize();
	int accept_connection();
};

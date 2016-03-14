#include "../header/server.h"

int server::initialize()
{
	return this->server_socket.initialize();
}

int server::accept_connection()
{
	return this->server_socket.accept_connection();
}


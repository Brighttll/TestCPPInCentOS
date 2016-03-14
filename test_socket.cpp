#include "test_socket.h"

extern const unsigned int SERVER_PORT = 200;
void test_socket::test_socket_fun()
{
    	server local_server{AF_INET, SOCK_STREAM, IPPROTO_TCP, SERVER_PORT};
	if( local_server.initialize() == 0 )
	{
		int client = local_server.accept_connection();
		if ( client >= 0 )
		{
			cout << "Accept connection successfully." << endl;
		}
	}

}

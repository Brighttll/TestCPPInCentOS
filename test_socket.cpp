#include "test_socket.h"

extern const unsigned int SERVER_PORT = 200;
void test_socket::test_socket_fun()
{
    	server local_server{AF_INET, SOCK_STREAM, IPPROTO_TCP, SERVER_PORT};
	cout << "Server socket created sucessfully..." << endl;
	if( local_server.initialize() == 0 )
	{
		cout << "Server initialized sucessfully..." << endl;
		int client = local_server.accept_connection();
		cout << "Accept finished..." << endl;
		if ( client >= 0 )
		{
			cout << "Accept connection successfully." << endl;
		}
	}

}

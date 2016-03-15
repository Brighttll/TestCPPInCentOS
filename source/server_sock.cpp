#include "../header/server_sock.h"
#include "../header/exception_ex.h"
int server_sock::initialize ()
{
    close(0);
    if(this->m_socket = socket(AF_INET, type, 0) < 0)
    {
	throw exception_ex(string("Create socket failed"), error_code::SOCKET_CREATED_ERROR, __FILE__, __func__, __LINE__);
    }
    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = af;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    //local_server.sin_port = 0;

    if(bind(this->m_socket, (sockaddr*)&server_addr, sizeof(server_addr)) < 0 )
    {
	close (this->m_socket);
	throw exception_ex(string("Bind server socket failed."), error_code::SOCKET_BINDED_ERROR, __FILE__, __func__, __LINE__);
    }
    if(listen(this->m_socket,10) < 0)
    {
	close (this->m_socket);
	throw exception_ex(string("Listen failed."), error_code::SOCKET_LISTENED_ERROR, __FILE__, __func__, __LINE__);
    }
    return 0;
}

int server_sock::accept_connection()
{
    cout << "Begin accepting..." << endl;
    int client = -1;
    sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    if( client = accept(this->m_socket, (sockaddr*)(&client_addr), &length) < -1)
    {
	close( this->m_socket );
	throw exception_ex(string("Accept connection failed."), error_code::SOCKET_ACCEPT_ERROR, __FILE__, __func__, __LINE__);
    }
    
    return client;
}

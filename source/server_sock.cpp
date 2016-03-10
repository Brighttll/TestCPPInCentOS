#include "../header/server_sock.h"
#include "../header/exception_ex.h"
server_sock::server_sock (int af, int type, int protocol, const unsigned int port)
{
    if(this->m_socket = socket(PF_INET, type, protocol) < 0)
    {
	throw exception_ex(string("Create socket failed"), error_code::SOCKET_CREATED_ERROR, __FILE__, __func__, __LINE__);
    }
	
    sockaddr_in local_server;
    sockaddr_in remote_client;
    memset(&local_server, 0, sizeof(local_server));
    local_server.sin_family = af;
    local_server.sin_addr.s_addr = htonl(INADDR_ANY);
    local_server.sin_port = htons(port);

    if(bind(this->m_socket, (sockaddr*)&local_server, sizeof(local_server)) < 0 )
    {
	throw exception_ex(string("Bind server socket failed."), error_code::SOCKET_BINDED_ERROR, __FILE__, __func__, __LINE__);
    }
    if(listen(this->m_socket,10) < 0)
    {
	throw exception_ex(string("Listen failed."), error_code::SOCKET_LISTENED_ERROR, __FILE__, __func__, __LINE__);
    }
}

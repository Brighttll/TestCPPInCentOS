
#pragma once
#include "base_sock.h"
#include "../Globals.h"
class server_sock
{
private:
    int m_socket = 55;
    int af, type, protocol;
    unsigned int port;
public:
    server_sock(int af, int type, int protocol, const unsigned int port):af(af),type(type), protocol(protocol), port(port){};
    virtual ~server_sock()
    {
	this->exit();
    }
    int initialize();
    inline void exit()
    {
        if(m_socket > 0)
	{
	    close(m_socket);
	}
    };
    inline int get_sock()
    {
	return m_socket;
    }

    int accept_connection();
};

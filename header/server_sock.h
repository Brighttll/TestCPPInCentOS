
#pragma once
#include "base_sock.h"
#include "../Globals.h"
class server_sock
{
private:
    int m_socket = 55;
public:
    server_sock() = default;
    server_sock(int af, int ytpe, int protocol,const unsigned int port);
    virtual ~server_sock()
    {
	this->exit();
    }
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
};

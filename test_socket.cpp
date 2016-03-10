#include "test_socket.h"

extern const unsigned int SERVER_PORT = 200;
void test_socket::test_socket_fun()
{
    server_sock server_socket {AF_INET, SOCK_STREAM, IPPROTO_TCP, SERVER_PORT};
}

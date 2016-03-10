#include "Globals.h"
#include "TestStl.h"
#include "test_socket.h"
#include "header/exception_ex.h"
#include <errno.h>

int main()
{
	cout << ""Test pull" << endl;
    cout << "Enter main function" << endl;
    try
    {
    	TestStl stlTester;
    	stlTester.MainFun();
    	test_socket sock_tester;
    	sock_tester.test_socket_fun();
    }
    catch(exception &e)
    {
	int exit_code = -1;
	extern int errno;
      	cout << "Got an unexpected exception!" << endl;
	if(typeid(e) == typeid(exception_ex))
	{
	    exception_ex &ex = static_cast<exception_ex&>(e);
	    cout << "Error located in " << ex.to_string() << endl;
	    cout << "Error message:\t\t\t" << ex.get_msg() << endl;
	    exit_code = ex.get_code();
	}
	cout << "System error number is : " << errno << endl;
	return exit_code;
    }
    return 0;
}

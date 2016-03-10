#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <exception>
#include <memory.h>

#include "base_operation.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::exception;

enum error_code
{
    UNKNOW_ERROR = -1,
    SOCKET_CREATED_ERROR = -2,
    SOCKET_BINDED_ERROR = -3,
    SOCKET_LISTENED_ERROR = -4
};


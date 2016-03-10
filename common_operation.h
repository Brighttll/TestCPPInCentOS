#pragma once
#include "Globals.h"
#include <sstream>

using std::stringstream;
class common_operation
{
public:
	static inline string itos(int i)
	{	
		stringstream s;
		s << i;
		return s.str();   
	}
};

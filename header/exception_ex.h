#pragma once
#include "../Globals.h"
#include "i_to_string.h"
#include "../common_operation.h"
class exception_ex : public exception, public i_to_string
{
public:
    exception_ex() : exception(){};
    exception_ex(const string &msg, error_code code):msg(msg), code(code){};
    exception_ex(const string &msg, error_code code, const string &file_name, const string &function_name, unsigned int line_no) :msg(msg), code(code), file_name(file_name), line_no(line_no), function_name(function_name){};
    string get_msg() const
    {
	return this->msg;
    };

    error_code get_code() const
    {
	return this->code;
    };

    string get_file_name() const
    {
	return this->file_name;
    }
    
    unsigned int get_line_no() const
    {
	return this->line_no;
    }

    string get_function_name() const
    {
	return this->function_name;
    }

    string to_string() override
    {
	return string("file:") + this->file_name + string(" function:") + this->function_name + string(" line no:") + common_operation::itos(this->line_no);
    } 
private:
    error_code code;
    string msg;
    string file_name;
    unsigned int line_no;
    string function_name;
};

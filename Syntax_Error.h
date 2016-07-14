#ifndef SYNTAX_ERROR_H_
#define SYNTAX_ERROR_H_
#include <stdexcept>
using namespace std;

class Syntax_Error : public invalid_argument {
public:
	Syntax_Error(string msg, int possition) : invalid_argument(msg) {}
};
#endif

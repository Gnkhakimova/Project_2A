#ifndef TOKENIZER_H
#define TOKENIZER_H

#include<string>
#include<iostream>
#include <sstream>
#include <cctype>
#include<locale>
#include<algorithm>
#include<iomanip>

#include"Syntax_Error.h"
#include"Token.h"

using namespace std;



class Tokenizer
{
public:
	
	Tokenizer(string expression);
	bool check_for_errors(string expression);
	Token next_token();
	
	
private:
	
	
};
#endif
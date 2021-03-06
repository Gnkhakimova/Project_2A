#pragma once
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


// define Tokenizer class
class Tokenizer
{
	int ind;
public:
	// when tokenizer constructor gets called expression should be passes as a parameter
	Tokenizer(string& expression);
	Token next_token();
	bool check_for_errors(string expression);
	bool has_more_tokens();
	string get_expression()const;
	int num_digits(int int_val);
    void error_handler(string msg, int error_possition, string expression);
	
	
private:
	string expression;
	Token item;
	
};
#endif
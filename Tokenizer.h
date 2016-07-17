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



class Tokenizer
{
	int ind;
public:
	
	Tokenizer(string& expression);
	Token next_token();
	bool check_for_errors(string expression);
	bool has_more_tokens();
	string get_expression()const;
	
	
private:
	string expression;
	Token item;
	
};
#endif
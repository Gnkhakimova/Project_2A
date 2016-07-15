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

int index;

class Tokenizer
{
public:
	
	Tokenizer(string& expression);
	Token next_token();
	bool check_for_errors(string expression);
	bool has_more_tokens();
	
	
private:
	string expression;
	Token item;
	
};
#endif
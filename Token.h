#ifndef TOKEN_H
#define TOKEN_H
#pragma once

#include<string>
#include<iostream>
#include <sstream>
#include <cctype>
#include<locale>
#include<algorithm>
#include<iomanip>
#include <type_traits>
#include"Syntax_Error.h"
#include"Tokenizer.h"

using namespace std;
// not sure if i need it
//enum token_type { unary, binary, operand, EOL };
//enum Operators { plus, minus, dev, mult, not, preincr, predecr, negative, power, mod, more, less, moreeq, lesseq, equal, notequal, and, or , oparen, cparen };

class Token
{
public:
	Token();

	int check_presedece(char op);
	Token token_attributes(char ch);
	string get_type() const;
	int get_operator_value() const;
	string get_operator_type() const;
	char get_next_var() const;
	
	bool is_unary_operator(char ch) const
	{
		return unary_operators.find(ch) != string::npos;
	}
	bool is_binary_operator(char ch) const
	{
		return binary_operators.find(ch) != string::npos;
	}

private:
	// can use enum type
	char next_var;
	string type;
	int operator_value;
	string operator_type;

	static const string unary_operators;
	static const string binary_operators;

	
};
#endif#pragma once

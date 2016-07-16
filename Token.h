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
//enum Operators { preincr,predecr,negative,OR,AND, };
int index = 0;

class Token
{
public:
	Token();

	int assign_precedece(char op);
	// changint it to string it was char
	Token token_attributes(const string the_expression);

	string get_type() const;

	int get_operator_precedence() const;

	string get_operator_type() const;

	int get_int_val() const;

	string get_str_val()const;

	char get_next_var() const;

	
	
	bool is_unary_operator(char ch) const
	{
		return unary_operators.find(ch) != string::npos;
	}
	bool is_binary_operator(char ch) const
	{
		return binary_operators.find(ch) != string::npos;
	}
	bool is_operators(char ch) const
	{
		return operators.find(ch) != string::npos;
	}

private:
	// can use enum type
	char next_var;
	string type;
	int operator_precedence;
	string operator_type;
	int int_val;
	string str_val;

	static const string unary_operators;
	static const string binary_operators;
	static const string operators;

	
};
#endif#pragma once

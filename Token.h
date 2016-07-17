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
#include"vector"

using namespace std;
// not sure if i need it



class Token
{
	int indx;
public:
	Token();

	int assign_precedece(string op, string op_type);
	// changint it to string it was char
	Token token_attributes(const string the_expression);

	string get_type() const;

	int get_operator_precedence() const;

	string get_operator_type() const;

	int get_int_val() const;

	string get_str_val()const;

	//char get_next_var() const;

	
	
	bool is_unary_operator(string ch) const
	{
		return find(unary_operators.begin(), unary_operators.end(), ch) != unary_operators.end();
		
	}
	bool is_binary_operator(string ch) const
	{
		return find(binary_operators.begin(), binary_operators.end(), ch) != binary_operators.end();
	}
	bool is_operators(char ch) const
	{
		return operators.find(ch) != string::npos;
	}

private:
	// can use enum type
	//char next_var;
	string type;
	int operator_precedence;
	string operator_type;
	int int_val;
	string str_val;

	static const vector<string> unary_operators;
	static const vector<string> binary_operators;
	static const string operators;

	
};
#endif

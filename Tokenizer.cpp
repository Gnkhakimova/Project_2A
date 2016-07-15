#include"Tokenizer.h"

// constructor of tokenizer class that get as a parameter string(expression) and does error checking, if no errors were found ot will remove spaces
// so user do not have to worry about input format
Tokenizer::Tokenizer(string& the_expression)

{
	index = 0;
	//expression = the_expression;
	if (check_for_errors(the_expression))
		
	{
		the_expression.erase(remove_if(the_expression.begin(), the_expression.end(), isspace), the_expression.end());
		expression = the_expression;
	}
	
}
// checks expression for the error gets called when object of tokenizer class id called
bool Tokenizer::check_for_errors(string expression)
{
	Token item;
	for (int i = 0; i <= expression.length(); i++)
	{
		int error_possition = i;
		char first = expression[0];
		if (item.is_binary_operator(first))
		{
			throw Syntax_Error("Expression can’t start with a binary operator @ char: ",error_possition);
		}
		if (first == ')')
		{
			throw Syntax_Error("Expression can’t start with a closing parenthesis @ char: ",error_possition);
		}
		if (item.is_binary_operator(expression[i]) && item.is_binary_operator(expression[i++]))
		{
			throw Syntax_Error("Two binary operators in a row @ char ",error_possition++);
		}
		if (isdigit(expression[i]) && isspace(expression[i++]) && isdigit(expression[i + 2]))
		{
			throw Syntax_Error("Two operands in a row @ char ", error_possition+2);
		}
		if (item.is_unary_operator(expression[i]) && item.is_binary_operator(expression[i++]))
		{
			throw Syntax_Error("A unary operand can’t be followed by a binary operator @ char ", error_possition++ );
		}
		if (expression[i] == '/' && expression[i++] == '0')
		{
			throw Syntax_Error("Division by zero @ char ", error_possition++);
		}
	}
	return true;
}

bool Tokenizer::has_more_tokens()
{
	return index != string::npos;
}

// should return object of token class
Token Tokenizer::next_token()
{
	// temp token to save the object
	
	Token tmp;
	if (has_more_tokens())
	{
		
		tmp = item.token_attributes(expression[index]);
		// increment the index
		index++;
		return tmp;
	}
	
}

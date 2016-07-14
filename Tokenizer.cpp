#include"Tokenizer.h"


Tokenizer::Tokenizer(string the_expression)

{
	check_for_errors(the_expression);
	// need to work on this one there should be spaces between them
	the_expression.erase(remove_if(the_expression.begin(), the_expression.end(), isspace), the_expression.end());
	

}

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

//bool Tokenizer::has_more_tokens()
//{
//	return start != string::npos;
//}

// work on this one

Token Tokenizer::next_token()
{

	// should retrun an object of type Token
	/*char ch;
	if (in.good() && ch != '\n' && ch != '\n')
	{

	}*/
	
	//return next_char.token_attributes;

}

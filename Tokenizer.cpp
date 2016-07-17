#include"Tokenizer.h"

// constructor of tokenizer class that get as a parameter string(expression) and does error checking, if no errors were found ot will remove spaces
// so user do not have to worry about input format
Tokenizer::Tokenizer(string& the_expression)

{
	ind = 0;
	
	if (check_for_errors(the_expression))
		
	{
		the_expression.erase(remove_if(the_expression.begin(), the_expression.end(), isspace), the_expression.end());
		expression = the_expression;
	}

}

string Tokenizer::get_expression()const
{
	return expression;
}

// checks expression for the error gets called when object of tokenizer class id called
bool Tokenizer::check_for_errors(string expression)
{
	string opr;
	Token item;
	for (size_t i = 0; i <= expression.length(); i++)
	{
		
		
		int error_possition = i;
	  
		char first = expression[0];
		
		if (item.is_operators(first) && item.is_operators(expression[1]))
		{
			string oper;
			oper = first + expression[1];
			if (item.is_binary_operator(oper))
			{
				throw Syntax_Error("Expression can�t start with a binary operator @ char: ", error_possition);
			}
		}
		else if (item.is_operators(first))
		{
			string firstletter(1, expression[0]);
			if (item.is_binary_operator(firstletter))
			{
				throw Syntax_Error("Expression can�t start with a binary operator @ char: ", error_possition);
			}
		}
	
		if (first == ')')
		{
			throw Syntax_Error("Expression can�t start with a closing parenthesis @ char: ",error_possition);
		}

		if (i < expression.length())
		{
			//string tmp;
			string one(1, expression[i]);
			string two(1, expression[i + 1]);
			
			
			if (item.is_operators(expression[i]) && item.is_operators(expression[i + 1]))
			{
				string tmp = one+two;
				if (item.is_binary_operator(tmp))
				{
					if (i < expression.length() - 1)
					{
						string three(1, expression[i + 2]);
						if (item.is_binary_operator(three))
						{
							throw Syntax_Error("Two binary operators in a row @ char ", error_possition + 1);
						}
						if (i < expression.length() - 2)
						{
							string four(1, expression[i + 3]);
							if (item.is_operators(expression[i + 2]) && item.is_operators(expression[i + 3]))
							{
								string tmp = three + four;
								if (item.is_binary_operator(tmp))
								{
									throw Syntax_Error("Two binary operators in a row @ char ", error_possition + 1);
								}
							}
						}
					}
				}
			}

			// need to add what of 2+++2
			if (item.is_binary_operator(one) && expression[i + 1] != '-' && item.is_binary_operator(two))
			{
				throw Syntax_Error("Two binary operators in a row @ char ", error_possition + 1);
			}
			
			if (i < expression.length() - 1)
			{
				string three(1, expression[i + 2]);
				if (expression[i] == '+' && expression[i + 1] == '+' && item.is_binary_operator(three) || expression[i] == '-' && expression[i + 1] == '-'
					&& item.is_binary_operator(three) || expression[i] == '!' && expression[i + 1] != '=' && item.is_binary_operator(three))
				{
					throw Syntax_Error("A unary operand can�t be followed by a binary operator @ char ", error_possition + 1);
				}
			}

		}
		

		if (isdigit(expression[i]) && isspace(expression[i+1]) && isdigit(expression[i + 2]))
		{
			throw Syntax_Error("Two operands in a row @ char ", error_possition+2);
		}

		

		if (expression[i] == '/' && expression[i+1] == '0')
		{
			throw Syntax_Error("Division by zero @ char ", error_possition+1);
		}
	}
	return true;
}

bool Tokenizer::has_more_tokens()
{
	return ind != string::npos;
}

// should return object of token class
Token Tokenizer::next_token()
{
	// temp token to save the object

	Token tmp;
	//string value;
	//if (has_more_tokens())
	//{
			tmp = item.token_attributes(expression);
			// increment the index
			ind++;
			return tmp;
	//}
	
}

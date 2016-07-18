#include"Tokenizer.h"

// constructor of tokenizer class that get as a parameter string(expression) and does 
//error checking, if no errors were found ot will remove spaces
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
                string msg = "Expression cannot start with a binary operator @ char: ";
                error_handler(msg, error_possition, expression);
			}
		}
		else if (item.is_operators(first))
		{
			string firstletter(1, expression[0]);
			if (item.is_binary_operator(firstletter))
			{
                string msg = "Expression cannot start with a binary operator @ char: ";
                error_handler(msg, error_possition, expression);
			}
		}
	
		if (first == ')')
		{
            string msg = "Expression cannot start with a closing parenthesis @ char: ";
            error_handler(msg, error_possition, expression);
		}
		if (expression[i] == '(')
		{
			bool answer = false;
			
			for (int j = i + 1; j < expression.length(); j++)
			{

				if (expression[j] == ')')

				{
					answer = true;
				}
			
							
			}
			if (answer == false)
			{
				string msg = "Expression does not have closing parenthesis @ char: ";
				error_handler(msg, error_possition, expression);
			}
				
			}

		

		if (i < expression.length())
		{
		
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
                            string msg = "Two binary operators in a row @ char ";
                            error_handler(msg, error_possition + 1, expression);
						}
						if (i < expression.length() - 2)
						{
							string four(1, expression[i + 3]);
							if (item.is_operators(expression[i + 2]) && item.is_operators(expression[i + 3]))
							{
								string tmp = three + four;
								if (item.is_binary_operator(tmp))
								{
                                    string msg = "Two binary operators in a row @ char ";
                                    error_handler(msg, error_possition + 1, expression);
								}
							}
						}
					}
				}
			}

		
			if (item.is_binary_operator(one) && expression[i + 1] != '-' && expression[i + 1] != '+' && item.is_binary_operator(two) && !isdigit(expression[i + 2]))
			{
                string msg = "Two binary operators in a row @ char ";
                error_handler(msg, error_possition + 1, expression);
			}

			if (i < expression.length() - 1)
			{
				string three(1, expression[i + 2]);
				if (expression[i] == '+' && expression[i + 1] == '+' && item.is_binary_operator(three) && expression[i + 2] != '+'
					|| expression[i] == '-' && expression[i + 1] == '-'	&& item.is_binary_operator(three) && three != "-"
					|| expression[i] == '!' && expression[i + 1] != '=' && item.is_binary_operator(two) && expression[i + 1] !='-')
				{
                    string msg = "A unary operand cannot be followed by a binary operator @ char ";
                    error_handler(msg, error_possition + 1, expression);
				}
			}

		}
		

		if (isdigit(expression[i]) && isspace(expression[i+1]) && isdigit(expression[i + 2]))
		{
            string msg = "Check expression. Two operands in a row @ char ";
            error_handler(msg, error_possition + 2, expression);
		}


		if (expression[i] == '/' && expression[i+1] == '0')
		{
            string msg = "Check expression. You have attempted to divide by zero.";
            error_handler(msg, error_possition + 1, expression);
		}
	}
	return true;
}

bool Tokenizer::has_more_tokens()
{
	return ind < expression.length();
}

int Tokenizer::num_digits(int x)
{
	int digits = 0; 
	do { x /= 10; digits++; } while (x != 0);
		return digits;
}
// should return object of token class
Token Tokenizer::next_token()
{
	// temp token to save the object

	Token tmp;
	
	if (has_more_tokens())
	{
		
			tmp = item.token_attributes(expression);
			int x = item.get_int_val();
			int dig_num = num_digits(x);
			// increment the index
			if (item.get_str_val() == "++" || item.get_str_val ()== "--"
				|| item.get_str_val ()== "&&" || item.get_str_val() == "||"
				|| item.get_str_val() == ">=" || item.get_str_val() == "<="
				|| item.get_str_val() == "==" || item.get_str_val() == "!=")
			{
			
				ind = ind + 2;
				return tmp;
			}
			else if (item.is_binary_operator(item.get_str_val()))
			{
				ind++;
				return tmp;
			}

			else if (dig_num>1)
			{
				ind = ind + dig_num;
				return tmp;
			}

			else
			{
				ind++;
				return tmp;
			}
			
	}
	
}

void Tokenizer::error_handler(string msg, int error_possition, string expression) {
    cout << expression << endl;
    cout << msg << error_possition << endl;
    cout << "Program terminating." << endl << endl;
    system("pause");
    quick_exit(EXIT_SUCCESS);
}

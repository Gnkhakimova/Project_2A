
#include"Token.h"

// defining unary and binary operator
const string Token::unary_operators = "+-*/%^!++--";
const string Token::binary_operators = "><>=<=&&||-";

// default consturctor set all values to the default 
Token::Token()
{
	// can change it to enum type
	next_var = ' ';
	// should change it to make eval while loop to know when the end is reached
	type = "";
	operator_type = "";
	operator_value = 0;
	
}

// getters
char Token::get_next_var() const
{
	return next_var;
}

string Token::get_type() const
{
	return type;
}

int Token::get_operator_precedence() const
{
	return operator_precedence;
}

string Token::get_operator_type() const
{
	return operator_type;
}
int Token::get_operator_precedence()const
{
	return operator_precedence;
}

// check presedences
int Token::check_precedece(char op)
{
	
	// need to modify it
	switch (op) {
	case '!': return 8;
	case '++': return 8;
	case '--': return 8;
	case '-': return 8; // negative operator need to check it
	case '^': return 7;
	case '*': return 6;
	case '/': return 6;
	case '%': return 6;
	case '+': return 5;
		//case '-': return 5; // minus operator 
	case '>': return 4;
	case '>=': return 4;
	case '<': return 4;
	case '<=': return 4;
	case '==': return 3;
	case '!=': return 3;
	case '&&': return 2;
	case '||': return 1;

		//default: error = true; return 0;
	}
}
int Token::get_int_val() const
{
	return int_val;
}
string Token::get_operator_value()const
{
	return operator_value;
}
Token Token::token_attributes(char next_char)
{
	Token item;

		// working on it
			if (isdigit(next_char))
			{
				
				int_val = (int)next_char;
				item.next_var = next_char;
				item.type = "operand";
				return item;
			}
			if (is_unary_operator(next_char))
			{
				// need to make it string that will allow to accep ++ or && operators
				operator_value = next_char;
				item.next_var = next_char;
				item.type = "operator";
				item.operator_type = "unary";
				operator_value = check_precedece(next_char);
				
				return item;
			}
			if (is_binary_operator(next_char))
			{

				item.next_var = next_char;
				item.type = "operator";
				item.operator_type = "binary";
				operator_value = check_precedece(next_char);
				
				return item;
			}
		}

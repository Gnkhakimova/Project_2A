
#include"Token.h"

const string Token::unary_operators = "+-*/%^!++--";
const string Token::binary_operators = "><>=<=&&||-";

Token::Token()
{
	// can change it to enum type
	next_var = ' ';
	type = "";
	operator_type = "";
	operator_value = 0;
	
}

char Token::get_next_var() const
{
	return next_var;
}

string Token::get_type() const
{
	return type;
}

int Token::get_operator_value() const
{
	return operator_value;
}

string Token::get_operator_type() const
{
	return operator_type;
}


int Token::check_presedece(char op)
{
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
Token Token::token_attributes(char next_char)
{
	Token item;

		// working on it
			if (isdigit(next_char))
			{
				item.type = "operand";
				item.next_var = next_char;
				return item;
			}
			if (is_unary_operator(next_char))
			{
				item.type = "operator";
				item.operator_type = "unary";
				item.operator_value = check_presedece(next_char);
				item.next_var = next_char;
				return item;
			}
			if (is_binary_operator(next_char))
			{
				item.type = "operator";
				item.operator_type = "binary";
				item.operator_value = check_presedece(next_char);
				item.next_var = next_char;
				return item;
			}
		}

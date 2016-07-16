
#include"Token.h"

// defining unary and binary operator
const string Token::unary_operators = "!++---";
const string Token::binary_operators = "><>=<=&&||-+*/%^==!=";

const string Token::operators = "+-*/%^!><=&|";

// default consturctor set all values to the default 
Token::Token()
{
	// can change it to enum type
	index = 0;
	next_var = ' ';
	// should change it to make eval while loop to know when the end is reached
	type = "";
	operator_type = "";
	
	
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


// check presedences
int Token::assign_precedece(char op)
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
string Token::get_str_val()const
{
	return str_val;
}

Token Token::token_attributes(const string expresstion)
{
	Token item;
	
	string result = "";
	while (isdigit(expresstion[index]))
	{

		result += expresstion[index];
		// convert strind int int
		int_val = atoi(result.c_str());
		
		item.type = "operand";
		index++;
		return item;
	}

	while (is_operators(expresstion[index]))
	{
		item.type = "operator";
		int tmpidx = index;
		if (expresstion[index] == '+' && expresstion[tmpidx++] == '+' && isdigit(expresstion[tmpidx++]))
		{
			str_val == "++";
			item.operator_type = "unary";
			index++;
			return item;
		}
		if (expresstion[index] == '-' && expresstion[tmpidx++] == '-' && isdigit(expresstion[tmpidx++]))
		{
			str_val = "--";
			item.operator_type = "unary";
			index++;
			return item;
		}
		if (expresstion[index] == '!' && isdigit(expresstion[tmpidx++]))
		{
			str_val = expresstion[index];
			item.operator_type = "unary";
			index++;
			return item;

		}
		if (expresstion[index] == '-' && isdigit(expresstion[tmpidx++]) || expresstion[index] == '-' && is_operators(expresstion[tmpidx++]))
		{
			str_val = "-";
			item.operator_type = "unary";
			index++;
			return item;
		}
		if (isdigit(expresstion[tmpidx--]) && expresstion[index] == '&' && expresstion[tmpidx + 2] == '&' && isdigit(expresstion[tmpidx++]))
		{
			str_val = "&&";
			item.operator_type == "binary";
			index++;
			return item;
		}
		if (isdigit(expresstion[tmpidx--]) && expresstion[index] == '|' && expresstion[tmpidx + 2] == '|' && isdigit(expresstion[tmpidx++]))
		{
			str_val = "||";
			item.operator_type = "binary";
			index++;
			return item;
		}
		if (expresstion[index] == '>' && expresstion[tmpidx++] == '=')
		{
			str_val = ">=";
			item.operator_type = "binary";
			index++;
			return item;
		}
		if (expresstion[index] == '<' && expresstion[tmpidx++] == '=')
		{
			str_val = "<=";
			item.operator_type = "binary";
			index++;
			return item;
		}
		if (expresstion[index] == '=' && expresstion[tmpidx++] == '=')
		{
			str_val = "==";
			item.operator_type = "binary";
			index++;
			return item;
		}
		if (expresstion[index] == '!' && expresstion[tmpidx++] == '=')
		{
			str_val = "!=";
			item.operator_type = "binary";
			index++;
			return item;
		}
		else
		{
			str_val = expresstion[index];
			item.operator_type = "binary";
			index++;
			return item;
		}
	}
}


				

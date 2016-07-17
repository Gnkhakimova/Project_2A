
#include"Token.h"

// defining unary and binary operator
const vector<string> Token::unary_operators = { "!","++","--", "-" };
const vector<string> Token::binary_operators = {">","<",">=","<=","&&","||","-","+","*","/","%","^", "==","!=","(",")"};

const string Token::operators = "+-*/%^!><=&|()";

// default consturctor set all values to the default 
Token::Token()
{
	// can change it to enum type
	indx = 0;
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


 //assign presedences
int Token::assign_precedece(string op, string op_type)
{
	if (op == "!" && op_type == "unary" || op == "++" && op_type == "unary" || op == "--" && op_type == "unary" || op == "-" && op_type == "unary")
	{
		return 8;
	}
	if (op == "^" && op_type == "binary")
	{
		return 7;
	}
	if (op == "*" || op=="/" || op=="%" && op_type == "binary")
	{
		return 6;
	}
	if (op == "+" || op=="-" && op_type == "binary")
	{
		return 5;
	}
	
	if (op == ">" || op == "<" || op == ">=" || op == "<=" && op_type == "binary")
	{
		return 4;
	}
	if (op == "==" || op=="!=" && op_type == "binary")
	{
		return 3;
	}
	if (op == "&&" && op_type == "binary")
	{
		return 2;
	}
	if (op == "||" && op_type == "binary")
	{
		return 1;
	}
	if (op == "(" && op_type == "binary")
	{
		return 0;
	}
	else
		return -1;

	//// need to modify it
	//switch (op) {
	//case "!": return 8;
	//case "++": return 8;
	//case "--": return 8;
	//case "-": return 8; // negative operator need to check it
	//case "^": return 7;
	//case "*": return 6;
	//case "/": return 6;
	//case "%": return 6;
	//case "+": return 5;
	//	//case '-': return 5; // minus operator 
	//case ">": return 4;
	//case ">=": return 4;
	//case "<": return 4;
	//case "<=": return 4;
	//case "==": return 3;
	//case "!=": return 3;
	//case "&&": return 2;
	//case "||": return 1;

	//	//default: error = true; return 0;
	//}
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
	while (isdigit(expresstion[indx]))
	{

		result += expresstion[indx];
		// convert strind int int
		int_val = atoi(result.c_str());
		
		item.type = "operand";
		indx++;
		//return type;
		return item;
	}

	while (is_operators(expresstion[indx]))
	{
		item.type = "operator";
		int tmpidx = indx;
		if (indx > expresstion.length() - 1)
		{
			if (expresstion[indx] == '+' && expresstion[tmpidx + 1] == '+' && isdigit(expresstion[tmpidx + 2]))
			{
				str_val == "++";

				item.operator_type = "unary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
			if (expresstion[indx] == '-' && expresstion[tmpidx + 1] == '-' && isdigit(expresstion[tmpidx + 2]))
			{
				str_val = "--";
				item.operator_type = "unary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
		}
		if (indx > expresstion.length())
		{
			if (expresstion[indx] == '!' && isdigit(expresstion[tmpidx + 1]))
			{
				str_val = expresstion[indx];
				item.operator_type = "unary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
			if (expresstion[indx] == '-' && isdigit(expresstion[tmpidx + 1]) || expresstion[indx] == '-' && is_operators(expresstion[tmpidx + 1]))
			{
				str_val = "-";
				item.operator_type = "unary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
		}
		if (indx > expresstion.length() - 1)
		{
			if (isdigit(expresstion[tmpidx - 1]) && expresstion[indx] == '&' && expresstion[tmpidx + 1] == '&' && isdigit(expresstion[tmpidx + 2]))
			{
				str_val = "&&";
				item.operator_type == "binary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
			if (isdigit(expresstion[tmpidx - 1]) && expresstion[indx] == '|' && expresstion[tmpidx + 1] == '|' && isdigit(expresstion[tmpidx + 2]))
			{
				str_val = "||";
				item.operator_type = "binary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
		}
		if (indx > expresstion.length())
		{
			if (expresstion[indx] == '>' && expresstion[tmpidx + 1] == '=')
			{
				str_val = ">=";
				item.operator_type = "binary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
			if (expresstion[indx] == '<' && expresstion[tmpidx + 1] == '=')
			{
				str_val = "<=";
				item.operator_type = "binary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
			if (expresstion[indx] == '=' && expresstion[tmpidx + 1] == '=')
			{
				str_val = "==";
				item.operator_type = "binary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
			if (expresstion[indx] == '!' && expresstion[tmpidx + 1] == '=')
			{
				str_val = "!=";
				item.operator_type = "binary";
				operator_precedence = assign_precedece(str_val, operator_type);
				indx++;
				return item;
			}
		}
		
		str_val = expresstion[indx];
		item.operator_type = "binary";
		operator_precedence = assign_precedece(str_val, operator_type);
		indx++;
		return item;
	}
}


				

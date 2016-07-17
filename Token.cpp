
#include"Token.h"

// defining unary and binary operator
const vector<string> Token::unary_operators = { "!","++","--", "-","(",")" };
const vector<string> Token::binary_operators = {">","<",">=","<=","&&","||","-","+","*","/","%","^", "==","!="};

const string Token::operators = "+-*/%^!><=&|()";

// default consturctor set all values to the default 
Token::Token()
{
	indx = 0;
	//next_var = ' ';
	operator_precedence = 0;
	int_val=0;
	str_val="";
	type = "";
	operator_type = "";
	
	
}

// getters
//char Token::get_next_var() const
//{
//	return next_var;
//}

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
	if (op == "(" && op_type == "unary")
	{
		return 0;
	}
	else
		return -1;

	
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
	if (isdigit(expresstion[indx]))
	{
		int t = indx;
		while (isdigit(expresstion[t]))
		{
			result += expresstion[t];
			t++;
		}
		
		// convert strind int int
		int_val = atoi(result.c_str());
		item.int_val = atoi(result.c_str());
		item.get_str_val() = "";
		str_val = "";
		item.type = "operand";
		int step = result.length();
		indx= indx+step;
		//return type;
		return item;
	}

	while (is_operators(expresstion[indx]))
	{
		//if(expre)
		item.type = "operator";
		int tmpidx = indx;
		if (indx < expresstion.length() - 1)
		{
		if (expresstion[indx] == '+' && expresstion[tmpidx + 1] == '+' && isdigit(expresstion[tmpidx + 2]))
		{
			item.str_val = "++";
			str_val = "++";
			item.operator_type = "unary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx = indx + 2;
			return item;
		}
		if (expresstion[indx] == '-' && expresstion[tmpidx + 1] == '-' && isdigit(expresstion[tmpidx + 2]))
		{
			item.str_val = "--";
			str_val = "--";
			item.operator_type = "unary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx++;
			return item;
		}
	}
		if (indx < expresstion.length())
		{
		if (expresstion[indx] == '!' && isdigit(expresstion[tmpidx + 1]) 
			|| expresstion[indx] == '!' && expresstion[tmpidx + 1] == '(')
		{
			item.str_val = expresstion[indx];
			item.operator_type = "unary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx++;
			return item;
		}
		if (expresstion[indx] == '-' && isdigit(expresstion[tmpidx + 1]) && indx == 0 
			|| expresstion[indx] == '-' && !isdigit(expresstion[tmpidx - 1]))
			
		{
			
			item.str_val = "-";
			item.operator_type = "unary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx++;
			return item;
		}
		}
		if (indx < expresstion.length() - 1 && indx !=0)
	{
		if (isdigit(expresstion[tmpidx - 1]) && expresstion[indx] == '&' && expresstion[tmpidx + 1] == '&' && isdigit(expresstion[tmpidx + 2]))
		{
			item.str_val = "&&";
			str_val = "&&";
			item.operator_type == "binary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx = indx + 2;
			return item;
		}
		if (isdigit(expresstion[tmpidx - 1]) && expresstion[indx] == '|' && expresstion[tmpidx + 1] == '|' && isdigit(expresstion[tmpidx + 2]))
		{
			item.str_val = "||";
			str_val = "||";
			item.operator_type = "binary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx = indx + 2;
			return item;
		}
		}
		if (indx < expresstion.length())
		{
		if (expresstion[indx] == '>' && expresstion[tmpidx + 1] == '=')
		{
			item.str_val = ">=";
			str_val = ">=";
			item.operator_type = "binary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx = indx + 2;
			return item;
		}
		if (expresstion[indx] == '<' && expresstion[tmpidx + 1] == '=')
		{
			item.str_val = "<=";
			str_val = "<=";
			item.operator_type = "binary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx = indx + 2;
			return item;
		}
		if (expresstion[indx] == '=' && expresstion[tmpidx + 1] == '=')
		{
			item.str_val = "==";
			str_val = "==";
			item.operator_type = "binary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx = indx + 2;
			return item;
		}
		if (expresstion[indx] == '!' && expresstion[tmpidx + 1] == '=')
		{
			item.str_val = "!=";
			str_val = "!=";
			item.operator_type = "binary";
			item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
			indx = indx + 2;
			return item;
		}
		}

		item.str_val = expresstion[indx];
		item.operator_type = "binary";
		item.operator_precedence = assign_precedece(item.str_val, item.operator_type);
		indx++;
		return item;
		}
	}



				

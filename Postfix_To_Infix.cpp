/** Implementation of the postfix_to_infix. */

#include "Postfix_To_Infix.h"
#include <sstream>
#include <cctype>
using std::stack;
using std::string;
using std::istringstream;
using std::isdigit;

const std::string Postfix_To_Infix::OPERATORS = "+-*/%";

/** Evaluates a postfix expression.
    @param expression The expression to be evaluated
    @return The value of the expression
    @throws Syntax_Error if a syntax error is detected
*/
string Postfix_To_Infix::convert(const std::string& expression) {
  // Be sure the stack is empty
  while (!operand_stack.empty())
    operand_stack.pop();

  // Process each token
  istringstream tokens(expression);
  char next_char;
  while (tokens >> next_char) {
    if (is_operator(next_char)) {
      string rhs = operand_stack.top();
      operand_stack.pop();
      string lhs = operand_stack.top();
      operand_stack.pop();
      string result = "(" + lhs + " "
	+ next_char + " " + rhs + ")";
      operand_stack.push(result);
    } else {
      tokens.putback(next_char);
      string operand;
      tokens >> operand;
      operand_stack.push(operand);
    }
  }
  if (!operand_stack.empty()) {
    string answer = operand_stack.top();
    operand_stack.pop();
    if (operand_stack.empty()) {
      return answer;
    } else {
      throw Syntax_Error("Stack should be empty");
    }
  } else {
    throw Syntax_Error("Stack is empty");
  }
}


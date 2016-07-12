#ifndef POSTFIX_TO_INFIX_H_
#define POSTFIX_TO_INFIX_H_

#include <stack>
#include <string>
#include "Syntax_Error.h"

class Postfix_To_Infix {
  // Public member functions
  public:
    /** Converts a Postfix expression into Infix
        @param expression The expression to be evaluated
        @return The value of the expression
        @throws Syntax_Error if a syntax error is detected
    */
    std::string convert(const std::string& expression);

  // Private member functions
  private:

    /** Determines whether a character is an operator.
        @param ch The character to be tested
        @return true if the character is an operator
    */
    bool is_operator(char ch) const {
      return OPERATORS.find(ch) != std::string::npos;
    }

    // Data fields
    static const std::string OPERATORS;
    std::stack<std::string> operand_stack;
};

#endif

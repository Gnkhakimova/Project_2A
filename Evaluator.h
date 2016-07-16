#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Token.h"
#include "Tokenizer.h"
#include "Syntax_Error.h"
#include <string>
#include <stack>
#include <iostream>

/******************************************************************************
An Evaluator object calculates and returns the value of an infix expression.
The class has two stacks -
operand_stack: holds operands (only integers in this implementation).
operator_stack: holds unary and binary operators.

The member function, eval, is called with a string parameter, which represents
a mathematical expression containing only integers, opening and closing
parentheses, and specific unary and binary operators listed in the code for
the unary_process and binary_process functions. Eval uses the two stacks to
calculate and return the value of the expression.

ALGORITHM :

Until the end of the expression is reached, get one token and perform
only one of the following:

* If the token is an operand, push it onto operand_stack.

* If the token is an operator AND operator_stack is empty, push it onto
operator_stack.

* If the token is an operator AND operator_stack is not empty AND the
token's precedence is greater than the precedence of the token at the
top of operator_stack, push the character onto operator_stack.

* If the token is "(", push it onto operator_stack.

* If the token is ")", perform unary_process or binary_process (see below)
until "(" is the top token in operator_stack. Pop operator_stack,
discarding "(".

* If none of the above apply, perform unary_process or binary_process.

When there are no more input characters, keep processing until the operator
stack becomes empty.The value left in the operand stack is the final
result of the expression.

The following definitions are used in the algorithm above:
binary_process: top() and pop() operand_stack twice to get the right hand and
left hand side operators respectively, then top() and pop() operator_stack and
compute: left hand operand, operator, right hand operand. Push the value
obtained onto operand_stack.

unary_process: top() and pop() operand_stack once to get the operand, then
top() and pop() operator_stack and compute: operator, operand. Push the value
obtained onto operand_stack.

******************************************************************************/

class Evaluator {
public:
    Evaluator();

    /** Evaluates an infix expression.
    @param the_expression The expression to be evaluated
    @return The value of the expression
    @throws Exception if error is detected
    */
    int eval(string the_expression);

    /** Applies a unary operator to an operand and updates stacks
        @return Pushes the result to operand_stack
    */
    void unary_process();

    /** Applies a binary operator to two operands and updates stacks
        @return Pushes the result to operand_stack
    */
    void binary_process();

    /** Checks type of operator and calls unary or binary process as indictated
    */
    void process();


private:
    stack<int> operand_stack;
    stack<Token> operator_stack;
};

#endif

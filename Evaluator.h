#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Token.h"
#include "Tokenizer.h"
#include "Syntax_Error.h"
#include <string>
#include <stack>
#include <iostream>

class Evaluator {
public:
    Evaluator();
    int eval(string the_expression);
    int unary_process(string unary_operator, int operand);
    int binary_process(string binary_operator, int operator_lhs, int operator_rhs);
    void process();


private:
    stack<int> operand_stack;
    stack<Token> operator_stack;
};




#endif

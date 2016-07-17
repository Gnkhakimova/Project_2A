#include "Evaluator.h"
#include "Token.h"
#include "Tokenizer.h"
#include <string>


Evaluator::Evaluator() {}

/** Evaluates an infix expression.
    @param the_expression The expression to be evaluated
    @return The value of the expression
    @throws Exception if error is detected
*/
int Evaluator::eval(string the_expression)
{
    Token current_item;
    
    Tokenizer Parser = Tokenizer(the_expression);
    while (Parser.has_more_tokens()) {

         current_item = Parser.next_token();

        string current_operator = current_item.get_str_val(); 
        int current_operand = current_item.get_int_val();
        string item_type = current_item.get_type();
        int precedence = current_item.get_operator_precedence();

        // all operands are pushed onto operand_stack
        if (item_type == "operand") {
            operand_stack.push(current_operand);
        }

        // operators are pushed onto the operator_stack if it's empty
        else if (item_type == "operator" && operator_stack.empty()) {
            operator_stack.push(current_item);
        }

        // an operator is pushed onto the stack if its precedence is higher 
        // than the operator currently at the top
        else if (item_type == "operator" && !operator_stack.empty() && precedence > operator_stack.top().get_operator_precedence()) {
            operator_stack.push(current_item);
        }

        // opening parentheses are always pushed onto the operator_stack
        else if (current_operator == "(") {
            operator_stack.push(current_item);
        }

        // when a closing parenthesis is encountered, process until its matching
        // opening parenthesis is at the top of the stack.
        else if (current_operator == ")") {
            while (operator_stack.top().get_str_val() != "(") {
                process();
            }
            operator_stack.pop();
        }
        
        // if none of the above apply, perform unary or binary process, depending
        // on the type of operator at the top of the operator_stack.
        else {
            process();
            operator_stack.push(current_item);
        }
    }

    // after end of expression, any operators remaining in operator_stack are 
    // processed.
    while (!operator_stack.empty()) {
        process();
    }
    // final result is the value remaining in the operand_stack.
    return operand_stack.top(); 
}

/** Checks type of operator and calls unary or binary process as indictated
*/
void Evaluator::process()
{
    if (operator_stack.top().get_operator_type() == "unary") {
        unary_process();
    }
    else if (operator_stack.top().get_operator_type() == "binary") {
        binary_process();
    }
}

/** Applies a unary operator to an operand and updates stacks
@return Pushes the result to operand_stack
*/
void Evaluator::unary_process() {

    // declare and initialize operator, operand, and result.
    // pop operator and operand from stacks.
    int result = 0;
    string op_val = operator_stack.top().get_str_val();
    operator_stack.pop();
    int the_operand = operand_stack.top();
    operand_stack.pop();
    
    // perform indicated operation on operand and assign its value to result.
    if (op_val == "!") {
        if (the_operand == 0)
            result = 0;
        else
            result = 1;
    }

    else if (op_val == "++") {
        result = the_operand + 1;
    }

    else if (op_val == "--") {
        result = the_operand - 1;
    }

    else if (op_val == "-") {
        result = the_operand * -1;
    }

    // push result onto operand stack
    operand_stack.push(result);
}

/** Applies a binary operator to two operands and updates stacks
@return Pushes the result to operand_stack
*/
void Evaluator::binary_process() {

    // declare and initialize operator, left and right operands, and result.
    // pop operands and operator from stacks.
    int result = 0;
    string op_val = operator_stack.top().get_str_val();
    operator_stack.pop();
    int rhs_op = operand_stack.top();
    operand_stack.pop();
    int lhs_op = operand_stack.top();
    operand_stack.pop();

    // perform indicated operation on operands and assign value to result.
    if (op_val == "^") {
        result = lhs_op;
        for (int i = 0; i < rhs_op; i++) {
            result *= lhs_op;
        }
    }

    else if (op_val == "*") {
        result = lhs_op * rhs_op;
    }

    else if (op_val == "/") {
        if (rhs_op == 0)
            throw std::exception("You cannot divide by zero.");
        result = lhs_op / rhs_op;
    }

    else if (op_val == "%") {
        result = lhs_op % rhs_op;
    }

    else if (op_val == "+") {
        result = lhs_op + rhs_op;
    }

    else if (op_val == "-") {
        result = lhs_op - rhs_op;
    }

    else if (op_val == ">") {
        result = lhs_op > rhs_op;
    }

    else if (op_val == ">=") {
        result = lhs_op >= rhs_op;
    }

    else if (op_val == "<") {
        result = lhs_op < rhs_op;
    }

    else if (op_val == "<=") {
        result = lhs_op <= rhs_op;
    }

    else if (op_val == "==") {
        result = lhs_op == rhs_op;
    }

    else if (op_val == "!=") {
        result = lhs_op != rhs_op;
    }

    else if (op_val == "&&") {
        result = lhs_op && rhs_op;
    }

    else if (op_val == "||") {
        result = lhs_op || rhs_op;
    }

    // push result onto stack
    operand_stack.push(result);
}

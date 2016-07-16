#include "Evaluator.h"
#include "Token.h"
#include "Tokenizer.h"
#include <string>


Evaluator::Evaluator()
{
}


/*

We will use two stacks :
Operand stack : to keep values(numbers) and
Operator stack : to keep operators(+, -, *, . and ^).

In the following, “process” means, (i)pop operand stack once(value1) (ii) pop 
operator stack once(operator) (iii) pop operand stack again(value2) (iv) compute 
value1 operator value2 (v) push the value obtained in operand stack.

Algorithm :

    Until the end of the expression is reached, get one character and perform 
    only one of the steps(a) through(f) :

    (a)If the character is an operand, push it onto the operand stack.

    (b)If the character is an operator, and the operator stack is empty then 
       push it onto the operator stack.

    (c)If the character is an operator and the operator stack is not empty, and 
       the character's precedence is greater than the precedence of the stack 
       top of operator stack, then push the character onto the operator stack.

    (d)If the character is "(", then push it onto operator stack.

    (e)If the character is ")", then "process" as explained above until the 
       corresponding "(" is encountered in operator stack.At this stage POP the 
       operator stack and ignore "(."

    (f)If cases(a), (b), (c), (d) and (e) do not apply, then process as 
       explained above.

    When there are no more input characters, keep processing until the operator 
    stack becomes empty.The value left in the operand stack is the final 
    result of the expression.
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
        int precedence = current_item.check_precedece();

        if (item_type == "operand") {
            operand_stack.push(current_operand);
        }
        else if (item_type == "operator" && operator_stack.empty()) {
            operator_stack.push(current_item);
        }
        else if (item_type == "operator" && !operator_stack.empty() && precedence > operator_stack.top().check_precedece()) {
            operator_stack.push(current_item);
        }
        else if (current_operator == "(") {
            operator_stack.push(current_item);
        }
        else if (current_operator == "(") {
            while (operator_stack.top().get_str_val() != "(") {
                process();
            }
            operator_stack.pop();
        }
        else {
            process();
        }
    }
    while (!operator_stack.empty()) {
        process();
    }
    return operand_stack.top();
}

int Evaluator::unary_process(string unary_operator, int operand)
{
    return 0;
}

int Evaluator::binary_process(string binary_operator, int operator_lhs, int operator_rhs)
{
    string op_val = operator_stack.top();
    operator_stack.pop();
    int rhs_op = operand_stack.top();
    operand_stack.pop();
    int lhs_op = operand_stack.top();
    operand_stack.pop();
    binary_process(operator_stack.top().get_str_val(), )

    return 0;
}

void Evaluator::process()
{
    if (operator_stack.top().get_operator_type == "unary") {
        unary_process();
    }
    else if (operator_stack.top().get_operator_type == "binary") {
        binary_process();
    }
}

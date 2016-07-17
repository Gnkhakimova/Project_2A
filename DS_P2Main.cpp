#include <iostream>
#include<string>
#include"Tokenizer.h"
#include"Token.h"
#include "Evaluator.h"


using namespace std;

//int main() {
//    Evaluator eval;
//    int result = eval.eval("!!!3+2");
//    return 0;
//}
int main()
{
    string expression = "++2*9%4";

 /*   Tokenizer parser(expression);

    do {
        parser.next_token();
    } while (parser.has_more_tokens());*/


    Evaluator eval;
    int result = eval.eval(expression);
    cout << "result is " << result << endl;


    system("pause");

}
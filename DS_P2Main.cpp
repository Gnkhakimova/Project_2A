#include <iostream>
#include<string>
#include"Tokenizer.h"
#include"Token.h"
#include "Evaluator.h"


using namespace std;

int main()
{
    string expression = "3&&5";

    Evaluator eval;
    int result = eval.eval(expression);
    cout << "result is " << result << endl;


    system("pause");

}
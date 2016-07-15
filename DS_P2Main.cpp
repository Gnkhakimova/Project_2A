#include <iostream>
#include<string>
#include"Tokenizer.h"
#include"Token.h"

using namespace std;

//int main() {
//    Evaluator eval;
//    int result = eval.eval("!!!3+2");
//    return 0;
//}
int main()
{
	Tokenizer obj(string("2+3+4"));
	
	while (obj.has_more_tokens())
	{
		obj.next_token();
	}


}
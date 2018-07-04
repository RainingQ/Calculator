// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Calculator.h"

int main()
{
	Calculator* calc = new Calculator();
	int i = 10;
	while (i--)
	{
		string question = calc->MakeFormula();
		//cout << question << endl;
		//string ret = calc->Solve("3+70*65+68");
		string ret = calc->Solve(question);
		cout << ret << endl;
	}

    return 0;
}


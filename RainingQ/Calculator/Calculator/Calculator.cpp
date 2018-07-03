// Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Calculator.h"

int main()
{
	Calculator* calc = new Calculator();
	string question = calc->MakeFormula();
	cout << question << endl;
	//string ret = calc->Solve("11+22");
	string ret = calc->Solve(question);
	cout << ret << endl;
	getchar();

    return 0;
}


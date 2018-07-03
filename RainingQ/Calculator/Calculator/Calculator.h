#pragma once

#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

class Calculator {
public:
	Calculator() {};
	string MakeFormula() {
		string formula = "";
		srand((unsigned int)time(NULL));
		//int count = random(1, 3);
		int count = random(1, 2);
		int start = 0;
		int number1 = random(1, 100);
		formula += to_string(number1);
		while (start <= count) {
			int operation = random(0, 3);
			//int number2;
			//if (operation == 3) {
			//	/*int tmp = random(1, 100);
			//	number2 = ((number1 % 2 == 0 ? tmp * 2 :
			//		(number1 % 3 == 0 ? tmp * 3 :
			//		(number1 % 5 == 0 ? tmp * 5 :
			//			tmp * 7)))) % number1;*/
			//	number2 = number1;
			//}
			//else {
			//	number2 = random(1, 100);
			//}
			int number2 = random(1, 100);
			formula += op[operation] + to_string(number2);
			number1 = number2;
			start++;
		}
		return formula;
	};

	string Solve(string formula) {
		vector<string>* tempStack = new vector<string>();
		stack<char>* operatorStack = new stack<char>();
		int len = formula.length();
		int k = 0;
		int numCount = 0;
		for (int j = -1; j < len - 1; j++) {
			char formulaChar = formula[j + 1];
			if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
				formulaChar == '*' || formulaChar == '/') {
				if (j == len - 2) {
					tempStack->push_back(formula.substr(k));
				}
				else {
					//if (k < j) {
					if (numCount != 0) {
						tempStack->push_back(formula.substr(k, numCount));
						numCount = 0;
					}
					if (operatorStack->empty()) {
						operatorStack->push(formulaChar);
					}
					else {
						char stackChar = operatorStack->top();
						if ((stackChar == '+' || stackChar == '-')
							&& (formulaChar == '*' || formulaChar == '/')) {
							operatorStack->push(formulaChar);
						}
						else {
							//tempStack->push_back(to_string(operatorStack->top()));
							string tmpChar;
							switch (operatorStack->top())
							{
								case '+' : tmpChar = "+"; break;
								case '-' : tmpChar = "-"; break;
								case '*' : tmpChar = "*"; break;
								case '/' : tmpChar = "/"; break;
								default : break;
							}
							tempStack->push_back(tmpChar);
							operatorStack->pop();
							operatorStack->push(formulaChar);
						}
					}
				}
				k = j + 2;
			}
			else {
				numCount++;
			}
		}
		while (!operatorStack->empty()) {
			tempStack->push_back(string(1, operatorStack->top()));
			operatorStack->pop();
		}
		stack<string>* calcStack = new stack<string>();
		for (int i = 0; i < tempStack->size(); i++) {
			string peekChar = tempStack->at(i);
			if (peekChar != "+" && peekChar != "-"
				&& peekChar != "/" && peekChar != "*") {
				calcStack->push(peekChar);
			}
			else {
				int a1 = 0;
				int b1 = 0;
				if (!calcStack->empty()) {
					b1 = stoi(calcStack->top());
					calcStack->pop();
				}
				if (!calcStack->empty()) {
					a1 = stoi(calcStack->top());
					calcStack->pop();
				}
				if (peekChar == "+") {
					calcStack->push(to_string(a1 + b1));
				}
				else if (peekChar == "-") {
					calcStack->push(to_string(a1 - b1));
				}
				else if (peekChar == "*") {
					calcStack->push(to_string(a1 * b1));
				}
				else if (peekChar == "/") {
					calcStack->push(to_string(a1 / b1));
				}
			}
		}
		return formula + "=" + calcStack->top();
	}
private:
	string op[4] = { "+", "-", "*", "/" };
};

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(countOperation)
		{
			Calculator* calc = new Calculator();
			string question = calc->MakeFormula();
			
			int count = 0;
			for (int i = 0; i < question.length(); i++)
			{
				if (question[i] == '+' || question[i] == '-'
					|| question[i] == '*' || question[i] == '/')
				{
					count++;
				}
			}

			Assert::IsTrue(count >= 2 && count <= 3);
		}

		TEST_METHOD(ret1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("88+17/17/17");
			Assert::AreEqual(ret, (string)"88+17/17/17=88");
		}

		TEST_METHOD(ret2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("3+70*65+68");
			Assert::AreEqual(ret, (string)"3+70*65+68=4621");
		}

		TEST_METHOD(ret3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("14/22+7");
			Assert::AreEqual(ret, (string)"14/22+7=7");
		}
	};
}
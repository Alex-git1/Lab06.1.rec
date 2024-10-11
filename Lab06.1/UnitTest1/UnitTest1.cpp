#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab06.1/Lab06.1(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int p[n] = { 12, 5, 6, 15, 18 };

			int expected_sum = 56;

			int actual_sum = SumElements(p, n, 0);

			Assert::AreEqual(expected_sum, actual_sum);
		}
	};
}

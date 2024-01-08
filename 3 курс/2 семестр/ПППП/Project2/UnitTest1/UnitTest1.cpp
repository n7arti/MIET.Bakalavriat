#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		void inputone(double& a, double& b, double& c, double& d, double& e, double& f) {
			a = 1; b = 1; c = 1; d = 1; e = 1; f = 1;
		}
		TEST_METHOD(inputtest) {

			double a, b, c, d, e, f;
			inputone(a, b, c, d, e, f);

			Assert::AreEqual(a, (double)1);
			Assert::AreEqual(b, (double)1);
			Assert::AreEqual(c, (double)1);
			Assert::AreEqual(d, (double)1);
			Assert::AreEqual(e, (double)1);
			Assert::AreEqual(f, (double)1);

		}
		TEST_METHOD(allzerotest)
		{
			double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

			Assert::IsTrue(allzero(a, b, c, d, e, f));
		}

		TEST_METHOD(test2) {
			double a = 3, b = 2, c = -6, d = 5, e = 1, f = 3;

			Assert::IsTrue(function2(a, b, c, d, e, f));
		}

		TEST_METHOD(test3_1) {
			double a = 0, b = 0, c = 2, d = 0, e = 0, f = 5;

			Assert::IsTrue(function3(a, b, c, d, e, f));
		}

		TEST_METHOD(test3_2) {
			double a = 0, b = 0, c = 0, d = 2, e = 0, f = 5;

			Assert::IsTrue(function3(a, b, c, d, e, f));
		}

		TEST_METHOD(test3_3) {
			double a = 0, b = 2, c = 0, d = 2, e = 1, f = 0;

			Assert::IsTrue(function3(a, b, c, d, e, f));
		}
		TEST_METHOD(test4) {
			double a = 0, b = 1, c = 0, d = 1, e = 0, f = 0;

			Assert::IsTrue(function4(a, b, c, d, e, f));
		}

		TEST_METHOD(test5) {
			double a = 3, b = 0, c = 3, d = 0, e = 0, f = 0;

			Assert::IsTrue(function5(a, b, c, d, e, f));
		}

		TEST_METHOD(test6) {
			double b = 0, c = 3, d = 3, e = 0, f = 0;

			Assert::IsTrue(function6(b, c, d, e, f));
		}

		TEST_METHOD(test7) {
			double a = 3, b = 3, d = 0, e = 0, f = 0;

			Assert::IsTrue(function7(a, b, d, e, f));
		}

		TEST_METHOD(test8) {
			double a = 0, c = 3, d = 0, e = 0, f = 0;

			Assert::IsTrue(function8(a, c, d, e, f));
		}

		TEST_METHOD(test9) {
			double a = 3, b = 3, c = 0, e = 0, f = 0;

			Assert::IsTrue(function9(a, b, c, e, f));
		}

		TEST_METHOD(test10) {
			double a = 10, b = 0, c = 10, d = 0, f = 3;

			Assert::IsTrue(function10(a, b, c, d, f));
		}
	};
}

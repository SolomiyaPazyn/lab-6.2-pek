#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.2 pek.cpp"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62pek
{
	TEST_CLASS(UnitTest62pek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 2, 4, 6, 8 }; 
			Assert::AreEqual(AverageMinMax(arr, 4) == 5.0);
		}
	};
}

	
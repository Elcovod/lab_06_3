#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_06_03_it\lab_06_03_it\lab_06_03_it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_FindMinOdd
{
	TEST_CLASS(FindMinOddTests)
	{
	public:

		// Тест 1: Стандартний випадок (пошук мінімуму серед непарних)
		TEST_METHOD(Test_FindMin_StandardCase)
		{
			const int SIZE = 5;
			// Масив: 10 (парне), 5 (непарне), 20 (парне), 3 (мін. непарне), 15 (непарне)
			int arr[SIZE] = { 10, 5, 20, 3, 15 };

			int expected_min_odd = 3;

			int actual_min = FindMin(arr, SIZE);

			Assert::AreEqual(expected_min_odd, actual_min, L"Функція FindMin не знайшла мінімальне непарне число.");
		}

		// Тест 2: Випадок, коли непарних чисел немає
		TEST_METHOD(Test_FindMin_NoOddNumbers)
		{
			const int SIZE = 4;
			int arr[SIZE] = { 10, 20, 4, 8 }; // Тільки парні числа

			// Функція має повернути початкове значення INT_MAX
			int expected = INT_MAX;

			int actual = FindMin(arr, SIZE);

			Assert::AreEqual(expected, actual, L"Функція FindMin не повернула INT_MAX, коли непарних чисел немає.");
		}

		// Тест 3: Тестування шаблонної функції (SecondFindMin) з типом long
		TEST_METHOD(Test_SecondFindMin_Long)
		{
			const int SIZE = 4;
			long arr[SIZE] = { 10L, 7L, 20L, 9L }; // L позначає тип long

			// Непарні: 7L, 9L. Мінімальне: 7L.
			long expected = 7L;

			long actual = SecondFindMin<long>(arr, SIZE);

			Assert::AreEqual(expected, actual, L"Шаблонна функція SecondFindMin<long> не знайшла мінімальне непарне число.");
		}
	};
}
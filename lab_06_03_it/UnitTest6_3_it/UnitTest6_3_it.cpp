#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_06_03_it\lab_06_03_it\lab_06_03_it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_FindMinOdd
{
	TEST_CLASS(FindMinOddTests)
	{
	public:

		// ���� 1: ����������� ������� (����� ������ ����� ��������)
		TEST_METHOD(Test_FindMin_StandardCase)
		{
			const int SIZE = 5;
			// �����: 10 (�����), 5 (�������), 20 (�����), 3 (��. �������), 15 (�������)
			int arr[SIZE] = { 10, 5, 20, 3, 15 };

			int expected_min_odd = 3;

			int actual_min = FindMin(arr, SIZE);

			Assert::AreEqual(expected_min_odd, actual_min, L"������� FindMin �� ������� �������� ������� �����.");
		}

		// ���� 2: �������, ���� �������� ����� ����
		TEST_METHOD(Test_FindMin_NoOddNumbers)
		{
			const int SIZE = 4;
			int arr[SIZE] = { 10, 20, 4, 8 }; // ҳ���� ���� �����

			// ������� �� ��������� ��������� �������� INT_MAX
			int expected = INT_MAX;

			int actual = FindMin(arr, SIZE);

			Assert::AreEqual(expected, actual, L"������� FindMin �� ��������� INT_MAX, ���� �������� ����� ����.");
		}

		// ���� 3: ���������� �������� ������� (SecondFindMin) � ����� long
		TEST_METHOD(Test_SecondFindMin_Long)
		{
			const int SIZE = 4;
			long arr[SIZE] = { 10L, 7L, 20L, 9L }; // L ������� ��� long

			// ������: 7L, 9L. ̳�������: 7L.
			long expected = 7L;

			long actual = SecondFindMin<long>(arr, SIZE);

			Assert::AreEqual(expected, actual, L"�������� ������� SecondFindMin<long> �� ������� �������� ������� �����.");
		}
	};
}
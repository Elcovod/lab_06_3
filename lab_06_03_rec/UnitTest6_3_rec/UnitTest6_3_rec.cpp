#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_06_03_rec\lab_06_03_rec\lab_06_03_rec.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_RecursiveFindMin
{
	TEST_CLASS(RecursiveFindMinTests)
	{
	public:

		// ���� 1: ����������� ������� (����� ������ ����� ��������)
		TEST_METHOD(Test_FindMin_StandardCase)
		{
			const int SIZE = 5;
			// �����: 10 (�����), 5 (�������), 20 (�����), 3 (��. �������), 15 (�������)
			int arr[SIZE] = { 10, 5, 20, 3, 15 };

			int expected_min_odd = 3;

			// ������ �������: (�����, �����, ���. ������, ���. �����)
			int actual_min = FindMin(arr, SIZE, 0, INT_MAX);

			Assert::AreEqual(expected_min_odd, actual_min, L"������� FindMin �� ������� �������� ������� �����.");
		}

		// ���� 2: �������, ���� �������� ����� ����
		TEST_METHOD(Test_FindMin_NoOddNumbers)
		{
			const int SIZE = 4;
			int arr[SIZE] = { 10, 20, 4, 8 }; // ҳ���� ���� �����

			// ������� �� ��������� ��������� �������� INT_MAX
			int expected = INT_MAX;

			int actual = FindMin(arr, SIZE, 0, INT_MAX);

			Assert::AreEqual(expected, actual, L"������� FindMin �� ��������� INT_MAX, ���� �������� ����� ����.");
		}

		// ���� 3: ���������� �������� ������� (SecondFindMin) � ����� long
		TEST_METHOD(Test_SecondFindMin_TemplateLong)
		{
			const int SIZE = 4;
			long arr[SIZE] = { 10L, 7L, 20L, 9L }; // L ������� ��� long

			// ������: 7L, 9L. ̳�������: 7L.
			long expected = 7L;

			long actual = SecondFindMin<long>(arr, SIZE, 0, LONG_MAX);

			Assert::AreEqual(expected, actual, L"�������� ������� SecondFindMin<long> �� ������� �������� ������� �����.");
		}
	};
}
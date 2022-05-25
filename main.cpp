//#include <fstream>
#include <iostream>
#include <string>

#include "process_nums.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	Nums g_nums;
	common_odd_t g_common_odd;

	//Nums* g_nums = new Nums; //��������� ������������ ������
	//common_odd_t* g_common_odd = new common_odd_t; //��������� ������������ ������

	// ��������� ��� ������ �����, ������������ ������ � 1-� �� ������, � ������� ������, ��� ��� ����������. 
	// ���������� ������ ������� ��� ��������� ��� {���������� ������ �����, ����� �����}.
	// ������� ���� ����� �� ������� �����, ����� �� �������. ����� ������������� �� ��������.
	unique_even_t* g_unique_even = new unique_even_t(
		[](pair<int, unsigned> p1, pair<int, unsigned> p2) {
			if (p1.second != p2.second) { return p1.second < p2.second; }
			return p1.first > p2.first;
		}
	);

	ifstream file1;

	do
	{
		string file1_path;
		cout << "������� ��� ������� ����� � ��������� �������: ";
		cin >> file1_path;

		file1.open(file1_path);

		if (!file1)
		{
			cerr << "�������� ��� �����. ���������� ��� ���.\n";
		}

	} while (!file1);


	ifstream file2;

	do
	{
		string file2_path;
		cout << "������� ��� ������� ����� � ��������� �������: ";
		cin >> file2_path;

		file2.open(file2_path);

		if (!file2)
		{
			cerr << "�������� ��� �����. ���������� ��� ���.\n";
		}
	} while (!file2);

	// ������ ������� ������ � ���������� ���������� �� process_nums
	g_nums.read_from(file1, file2);
	//(*g_nums).read_from(file1, file2);

	// ������� ����� ������� ������ ���������� ������ �����. �������� � ���������� ����������
	//get_unique_even(g_unique_even, g_nums);
	//get_unique_even(g_unique_even, *g_nums);
	get_unique_even(*g_unique_even, g_nums);

	// ������� ����� ������� ������ ����� �������� �����. �������� � ���������� ����������
	get_common_odd(g_common_odd, g_nums);
	//get_common_odd(*g_common_odd, *g_nums);

	// ��������� ������ ���� ��� �����������
	ofstream out1("out1.txt");
	if (!out1) 
	{
		cerr << "������ �������� ����� out1.txt ��� ������!\n";
		exit(1);
	}

	// ���������� � ���� ����������
	//write_unique_even_to(g_unique_even, out1);
	write_unique_even_to(*g_unique_even, out1);

	// ��������� ������ ���� ��� �����������
	ofstream out2("out2.txt");
	if (!out2)
	{
		cerr << "������ �������� ����� out2.txt ��� ������!\n";
		exit(1);
	}

	// ���������� � ���� ����������
	write_common_odd_to(g_common_odd, out2);
	//write_common_odd_to(*g_common_odd, out2);

	//delete g_nums; // ������������ ������, ���������� ����� ���������� new
	//delete g_common_odd; // ������������ ������, ���������� ����� ���������� new
	delete g_unique_even;

	cout << "���������� ������ ���������!\n";

	return 0;
}
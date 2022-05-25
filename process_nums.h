#ifndef PROCESS_NUMS_H
#define PROCESS_NUMS_H

//#include<utility>
#include <functional>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// ������� ������
struct Nums
{
	void read_from(ifstream& f1, ifstream& f2);

	vector<int> l1; // �����, ��������� �� ������� �����
	vector<int> l2; // �����, ��������� �� ������� �����
};

extern Nums g_nums; // ���������� ���������� ��� ������� ������


// ����� ������������ ������ ������� ��� ��������� ��� {���������� ������ �����, ����� �����}.

// ��� ���������� 1-� ������ ������� �������, ������� ������ �������.
using unique_even_t = set<pair<int, unsigned>, function<bool(const pair<int, unsigned>&, 
	const pair<int, unsigned>&)>>;

extern unique_even_t g_unique_even; //���������� ���������� (��������� 1-� ������)

// ��� ���������� 2-� ������. ������� ��� ����������
using common_odd_t = vector<int>;

// ������ �������� �����, ������������ ����� � ���� ������
extern common_odd_t g_common_odd; //���������� ���������� (��������� 2-� ������)

// ����� ���������� ������ �� ������� ������
void get_unique_even(unique_even_t& unique_even, const Nums& nums);

// ����� ����� �������� �� ������� ������
void get_common_odd(common_odd_t& common_odd, const Nums& nums);


// �������� ��������� � ����
void write_unique_even_to(const unique_even_t& unique_even, ofstream& out);

// �������� ��������� � ����
void write_common_odd_to(const common_odd_t& common_odd, ofstream& out);

#endif
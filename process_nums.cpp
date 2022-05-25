#include "process_nums.h"


void Nums::read_from(ifstream& f1, ifstream& f2)
{
	// �������� ����� �� ������ � �� ����� �� ����� 1 � ������� ��������� copy, ��������� ���������� � ���������
	copy(istream_iterator<int>(f1), istream_iterator<int>(), back_inserter(l1));

	// �������� ����� �� ������ � �� ����� �� ����� 2 � ������� ��������� copy, ��������� ���������� � ���������
	copy(istream_iterator<int>(f2), istream_iterator<int>(), back_inserter(l2));
}


void get_unique_even(unique_even_t& unique_even, const Nums& nums)
{
	// ��������� ��������������� ����� �� ������� ����� �� ��������
	set<int, greater<int>> s1(nums.l1.begin(), nums.l1.end());

	// ��������� ��������������� ����� �� ������� ����� �� ��������
	set<int, greater<int>> s2(nums.l2.begin(), nums.l2.end());

	// ���������� �� ������ �� ������� �����
	for (const auto& num : s1)
	{
		// ��� �� ����� ��������
		if (num % 2) { continue; }

		// ������� ������
		auto it = s2.find(num);
		if (it != s2.end())
		{
			// ������� ���, ����� �����, ����� ����� �������� ����� �� ������� ����� �� ��������� ���
			s2.erase(it);
			continue;
		}

		unique_even.insert({ num, 1 }); // ���� {�����, ����}
	}

	// ���������� �� ������ �� ������� �����
	for (const auto& num : s2)
	{
		// ��� �� ����� ��������
		if (num % 2) { continue; }

		// ��� ��� �� ������� �������, �� ����� �� ������ �� � 1-�

		unique_even.insert({ num, 2 }); // ���� {�����, ����}
	}
}

void get_common_odd(common_odd_t& common_odd, const Nums& nums)
{
	// ����� ����� �� ������� ����� ��� ���e��
	set<int> visited;

	// ��������� ��������������� ����� �� ������� �����
	set<int> s2(nums.l2.begin(), nums.l2.end());

	// ���������� �� ������ �� ������� ����� � ������� �� ����������
	for (const auto& num : nums.l1)
	{
		// ��� �� ����� ������
		if (num % 2 == 0) { continue; }

		// ��� �� ����� ����������
		if (s2.find(num) == s2.end()) { continue; }

		// ��� ������������ �����
		if (visited.find(num) == visited.end()) { visited.insert(num); }
		else { continue; }

		// ��������� � ����� �����
		common_odd.push_back(num);
	}
}


void write_unique_even_to(const unique_even_t& unique_even, ofstream& out)
{
	// ��� ������� ����� � ������ �����
	for (const auto& [num, file_num] : unique_even)
	{
		out << "{" << num << ": " << file_num << "}\n";
	}
}

void write_common_odd_to(const common_odd_t& common_odd, ofstream& out)
{
	// ��� ������� �����
	for (const auto& num : common_odd)
	{
		out << num << " ";
	}
}
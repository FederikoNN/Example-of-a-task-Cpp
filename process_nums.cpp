#include "process_nums.h"


void Nums::read_from(ifstream& f1, ifstream& f2)
{
	// Копируем числа от начала и до конца из файла 1 с помощью алгоритма copy, потоковых итераторов и инсертера
	copy(istream_iterator<int>(f1), istream_iterator<int>(), back_inserter(l1));

	// Копируем числа от начала и до конца из файла 2 с помощью алгоритма copy, потоковых итераторов и инсертера
	copy(istream_iterator<int>(f2), istream_iterator<int>(), back_inserter(l2));
}


void get_unique_even(unique_even_t& unique_even, const Nums& nums)
{
	// Множество неповторяющихся чисел из первого файла по убыванию
	set<int, greater<int>> s1(nums.l1.begin(), nums.l1.end());

	// Множество неповторяющихся чисел из второго файла по убыванию
	set<int, greater<int>> s2(nums.l2.begin(), nums.l2.end());

	// Проходимся по числам из первого файла
	for (const auto& num : s1)
	{
		// Нам не нужны нечётные
		if (num % 2) { continue; }

		// Находим повтор
		auto it = s2.find(num);
		if (it != s2.end())
		{
			// Удаляем его, чтобы потом, когда будем обходить числа из второго файла не встретить его
			s2.erase(it);
			continue;
		}

		unique_even.insert({ num, 1 }); // пара {число, файл}
	}

	// Проходимся по числам из второго файла
	for (const auto& num : s2)
	{
		// Нам не нужны нечётные
		if (num % 2) { continue; }

		// Так как мы удалили повторы, то можем не искать их в 1-м

		unique_even.insert({ num, 2 }); // пара {число, файл}
	}
}

void get_common_odd(common_odd_t& common_odd, const Nums& nums)
{
	// Какие числа из первого файла уже учтeны
	set<int> visited;

	// Множество неповторяющихся чисел из второго файла
	set<int> s2(nums.l2.begin(), nums.l2.end());

	// Проходимся по числам из первого файла в порядке их следования
	for (const auto& num : nums.l1)
	{
		// Нам не нужны чётные
		if (num % 2 == 0) { continue; }

		// Нам не нужны уникальные
		if (s2.find(num) == s2.end()) { continue; }

		// Уже обработанное число
		if (visited.find(num) == visited.end()) { visited.insert(num); }
		else { continue; }

		// Добавляем в конец число
		common_odd.push_back(num);
	}
}


void write_unique_even_to(const unique_even_t& unique_even, ofstream& out)
{
	// Для каждого числа и номера файла
	for (const auto& [num, file_num] : unique_even)
	{
		out << "{" << num << ": " << file_num << "}\n";
	}
}

void write_common_odd_to(const common_odd_t& common_odd, ofstream& out)
{
	// Для каждого числа
	for (const auto& num : common_odd)
	{
		out << num << " ";
	}
}
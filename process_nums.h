#ifndef PROCESS_NUMS_H
#define PROCESS_NUMS_H

//#include<utility>
#include <functional>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

// Входные данные
struct Nums
{
	void read_from(ifstream& f1, ifstream& f2);

	vector<int> l1; // Числа, считанные из первого файла
	vector<int> l2; // Числа, считанные из второго файла
};

extern Nums g_nums; // Глобальная переменная для входных данных


// Будем использовать лямбда функцию для сравнения пар {уникальное чётное число, номер файла}.

// Тип результата 1-й задачи слишком длинный, поэтому вводим синоним.
using unique_even_t = set<pair<int, unsigned>, function<bool(const pair<int, unsigned>&, 
	const pair<int, unsigned>&)>>;

extern unique_even_t g_unique_even; //Глобальная переменная (результат 1-й задачи)

// Тип результата 2-й задачи. Синоним для понятности
using common_odd_t = vector<int>;

// Список нечётных чисел, содержащихся сразу в двух файлах
extern common_odd_t g_common_odd; //Глобальная переменная (результат 2-й задачи)

// Найти уникальные чётные во входных данных
void get_unique_even(unique_even_t& unique_even, const Nums& nums);

// Найти общие нечётные во входных данных
void get_common_odd(common_odd_t& common_odd, const Nums& nums);


// Записать результат в файл
void write_unique_even_to(const unique_even_t& unique_even, ofstream& out);

// Записать результат в файл
void write_common_odd_to(const common_odd_t& common_odd, ofstream& out);

#endif
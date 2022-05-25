//#include <fstream>
#include <iostream>
#include <string>

#include "process_nums.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	Nums g_nums;
	common_odd_t g_common_odd;

	//Nums* g_nums = new Nums; //Выделение динамической памяти
	//common_odd_t* g_common_odd = new common_odd_t; //Выделение динамической памяти

	// Множество пар чётных чисел, содержащихся только в 1-м из файлов, и номеров файлов, где они содержатся. 
	// Используем лямбда функцию для сравнения пар {уникальное чётное число, номер файла}.
	// Первыми идут числа из первого файла, потом из второго. Числа отсортированы по убыванию.
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
		cout << "Введите имя первого файла с исходными данными: ";
		cin >> file1_path;

		file1.open(file1_path);

		if (!file1)
		{
			cerr << "Неверное имя файла. Попробуйте ещё раз.\n";
		}

	} while (!file1);


	ifstream file2;

	do
	{
		string file2_path;
		cout << "Введите имя второго файла с исходными данными: ";
		cin >> file2_path;

		file2.open(file2_path);

		if (!file2)
		{
			cerr << "Неверное имя файла. Попробуйте ещё раз.\n";
		}
	} while (!file2);

	// Читаем входные данные в глобальную переменную из process_nums
	g_nums.read_from(file1, file2);
	//(*g_nums).read_from(file1, file2);

	// Находим среди входных данных уникальные чётные числа. Помещаем в глобальную переменную
	//get_unique_even(g_unique_even, g_nums);
	//get_unique_even(g_unique_even, *g_nums);
	get_unique_even(*g_unique_even, g_nums);

	// Находим среди входных данных общие нечётные числа. Помещаем в глобальную переменную
	get_common_odd(g_common_odd, g_nums);
	//get_common_odd(*g_common_odd, *g_nums);

	// Открываем первый файл для результатов
	ofstream out1("out1.txt");
	if (!out1) 
	{
		cerr << "Ошибка открытия файла out1.txt для записи!\n";
		exit(1);
	}

	// Записываем в файл результаты
	//write_unique_even_to(g_unique_even, out1);
	write_unique_even_to(*g_unique_even, out1);

	// Открываем второй файл для результатов
	ofstream out2("out2.txt");
	if (!out2)
	{
		cerr << "Ошибка открытия файла out2.txt для записи!\n";
		exit(1);
	}

	// Записываем в файл результаты
	write_common_odd_to(g_common_odd, out2);
	//write_common_odd_to(*g_common_odd, out2);

	//delete g_nums; // Освобождение памяти, выделенной ранее оператором new
	//delete g_common_odd; // Освобождение памяти, выделенной ранее оператором new
	delete g_unique_even;

	cout << "Выполнение задачи завершено!\n";

	return 0;
}
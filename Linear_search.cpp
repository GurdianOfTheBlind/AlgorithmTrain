// Linear search
// Линейный поиск

#include <iostream>
#include <cassert>
#include <iomanip>
#include <random>
#include <ctime>


template <typename T>
size_t linear_search(const T* array, T x, size_t n);

template <typename T>
void print_arr(const T* array, size_t n);

int main()
{
	const size_t Array_len = 100;


	int i_array[Array_len];

	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> uid(0, 1000), aid(0, 100);
	for (size_t i = 0; i < Array_len; i++)
		i_array[i] = uid(gen);

	print_arr(i_array, Array_len);



	int search_val = i_array[aid(gen)];

	size_t index = linear_search(i_array, search_val, Array_len);

	if (index == -1)
		std::cout << "Value " << search_val << "not found.";
	else
		std::cout << "Value: " << search_val << ", index: " << index;

	std::cout << std::endl;


	return 0;
}

template <typename T>
size_t linear_search(const T* array, T x, size_t n)
{
	assert(n > 0);
	size_t index = -1;

	for (size_t i = 0; i < n; i++)
		if (array[i] == x)
			return i;

	return -1;
}

template <typename T>
void print_arr(const T* array, size_t n)
{
	assert(n > 0);
	for (size_t i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		std::cout << std::setw (5) << array[i] << "  ";
	}

	std::cout << std::endl;

	return;
}

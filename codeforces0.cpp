#include <iostream>
// #include <vector>


int main()
{

	int* temp = new int;
	std::cin >> *temp;
	
	const int perm = *temp;

	// delete temp;

	int** array = new int* [2];

	for (int i = 0; i < 2; i++)
		*(array + i) = new int[perm];

	for (int i = 0; i < perm; i++)
		*(*(array + 0) + i) = i+1;

	for (int i = 0; i < perm; i++)
	{
		std::cin >> *temp;

		*(*(array + 1) + i) = *temp;
	}

	delete temp;

	for (int i = 0; i < perm; i++)
	{

		for (int x = 0; x < perm; x++)
		{
			if (*(*(array + 1) + x) == i + 1)
				std::cout << *(*(array + 0) + x) << ' ';
		}
	}

	for (int i = 0; i < 2; i++)
		delete[] * (array + i);

	delete[] array;

}

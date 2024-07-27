#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	//std::ofstream fout("output.txt");
	//std::ifstream fin("input.txt");

	int n;
    std::cin >> n;
	//fin >> n;

	std::vector <int> indexes1;
	std::vector <int> indexes2;
	int* arr1 = new int[n];
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr1[i];
		//fin >> arr1[i];
	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr2[i];
		//fin >> arr2[i];
	}

	int** matrix = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		matrix[i] = new int[n + 1];
	}

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr1[i - 1] == arr2[j - 1])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			else
			{
				if (matrix[i - 1][j] > matrix[i][j - 1])
				{
					matrix[i][j] = matrix[i - 1][j];
				}
				else
				{
					matrix[i][j] = matrix[i][j - 1];
				}
			}
		}
	}

	
	for (int k = n, l = n; matrix[k][l] != 0; k--, l--)
	{
		if (arr1[k - 1] == arr2[l - 1])
		{
			indexes1.push_back(k - 1);
			indexes2.push_back(l - 1);
			continue;
		}
		else
		{
			if (matrix[k][l] == matrix[k - 1][l])
			{
				l++;
			}
			else if (matrix[k][l] == matrix[k][l - 1])
			{
				k++;
			}
		}
	}

	std::cout << matrix[n][n] << std::endl;

	for (int i = matrix[n][n] - 1; i >= 0; i--)
	{
		std::cout << indexes1.at(i) << " ";
	}
	std::cout << std::endl;

	for (int i = matrix[n][n] - 1; i >= 0; i--)
	{
		std::cout << indexes2.at(i) << " ";
	}
	
	delete[] arr1;
	delete[] arr2;

	for (int i = 0; i <= n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	//fin.close();
	return 0;
}
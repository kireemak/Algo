#include <fstream>
#include <iostream>

int main()
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	
	int n = 0;
	fin >> n;

	int** arrSize = new int*[n];
	int** matrixMin = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arrSize[i] = new int[2];
		fin >> arrSize[i][1] >> arrSize[i][2];
		matrixMin[i] = new int[n];
		matrixMin[i][i] = 0;
	}

	for (int j = 1; j < n; j++)
	{
		for (int i = j - 1, thisMin; i >= 0; i--)
		{
			thisMin = INT_MAX;

			for (int k = i, thisCount; k < j; k++)
			{
				thisCount = matrixMin[i][k] + matrixMin[k + 1][j] + arrSize[i][1]
					* arrSize[k][2] * arrSize[j][2];

				if (thisCount < thisMin)
					thisMin = thisCount;
			}

			matrixMin[i][j] = thisMin;
		}
	}

	fout << matrixMin[0][n - 1] << std::endl;
	std::cout << matrixMin[0][n - 1] << std::endl;

	for (int i = 0; i < n; i++)
	{
		delete[] matrixMin[i];
		//delete[] arrSize[i];
	}
	delete[] matrixMin;
	delete[] arrSize;

	fin.close();
	fout.close();

	return 0;
}
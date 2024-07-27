#include <iostream>
#include <fstream>

int main()
{
	int n, k;
	int mod = 1000000007;

	std::cin >> n >> k;

	int** results = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		results[i] = new int[k + 1];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k && j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				results[i][j] = 1;
				continue;
			}

			results[i][j] = (results[i - 1][j - 1] + results[i - 1][j]) % mod;
		}
	}

	std::cout << results[n][k] << std::endl;

	return 0;
}
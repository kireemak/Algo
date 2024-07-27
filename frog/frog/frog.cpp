#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	int* allPoints = new int[n];
	//int* indexes = new int[n];
	int* frogPoints = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> allPoints[i];
	}

	if (n == 1)
	{
		std::cout << allPoints[0] << std::endl;
		std::cout << 1 << std::endl;
		return 0;
	}
	if (n == 2)
	{
		std::cout << "-1\n";
		return 0;
	}

	frogPoints[0] = allPoints[0];
	frogPoints[1] = -1;
	frogPoints[2] = frogPoints[0] + allPoints[2];
	for (int i = 3; i < n; i++)
	{
		if (frogPoints[i - 3] > frogPoints[i - 2])
		{
			frogPoints[i] = frogPoints[i - 3] + allPoints[i];
		}
		else
		{
			frogPoints[i] = frogPoints[i - 2] + allPoints[i];
		}
	}

	std::cout << frogPoints[n - 1] << std::endl;

	std::vector <int> indexes;
	int k = n - 1;
	indexes.push_back(k);
	while (true)
	{
		if (k == 0)
		{
			break;
		}
		if (frogPoints[k] - allPoints[k] == frogPoints[k - 3])
		{
			indexes.push_back(k - 3);
			k -= 3;
		}
		else
		{
			indexes.push_back(k - 2);
			k -= 2;
		}
	}

	for (int i = indexes.size() - 1; i >= 0; i--)
		std::cout << indexes[i] + 1 << ' ';

	return 0;
}
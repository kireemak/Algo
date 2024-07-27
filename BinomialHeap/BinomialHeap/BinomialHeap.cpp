#include <iostream>
#include <fstream>
#include <vector>

std::vector <long long> getBinomialTreesHeights(unsigned long long n)
{
    std::vector <long long> heightsVector;

    unsigned long long remainingBits = n;
    unsigned long long currentTreeHeight = 0;
    unsigned long long checkSum = 0;

    while (remainingBits > 0)
    {
        if ((remainingBits & 1) == 1)
        {
            heightsVector.push_back(currentTreeHeight);
            checkSum += (1 << currentTreeHeight);
        }

        remainingBits >>= 1;
        currentTreeHeight++;
    }

    if (checkSum != n)
    {
        heightsVector.clear();
        heightsVector.push_back(-1);
    }

    return heightsVector;
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    unsigned long long n;
    //std::cin >> n;
    fin >> n;
    std::vector <long long> answer = getBinomialTreesHeights(n);

    for (unsigned long long i = 0; i < answer.size(); i++)
    {
        fout << answer[i] << std::endl;
        std::cout << answer[i] << std::endl;
    }

    fin.close();
    fout.close();

    return 0;
}
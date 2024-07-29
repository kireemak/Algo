#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ofstream fout("output.txt");
    std::ifstream fin("input.txt");

    int n;
    fin >> n;
    //std::cin >> n;

    std::vector <std::vector <int>> connectMatrix(n, std::vector <int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> connectMatrix[i][j];
            //std::cin >> connectMatrix[i][j];
        }
    }

    std::vector <int> marksVector(n, 0);
    for (int i = 0, thisNoteMark = 0, front = 0, back = 0; i < n; i++)
    {
        if (marksVector[i] == 0)
        {
            std::vector <int> buffVector(n, 0);
            marksVector[i] = ++thisNoteMark;
            buffVector[back++] = i;

            while (back != front)
            {
                for (int k = 0; k < n; k++)
                {
                    if (connectMatrix[buffVector[front]][k] == 1 && marksVector[k] == 0)
                    {
                        buffVector[back++] = k;
                        marksVector[k] = ++thisNoteMark;
                    }
                }
                front++;
            }
        }
        fout << marksVector[i] << ' ';
        std::cout << marksVector[i] << ' ';
    }

    fout << std::endl;
    std::cout << std::endl;

    fout.close();
    fin.close();

    return 0;
}
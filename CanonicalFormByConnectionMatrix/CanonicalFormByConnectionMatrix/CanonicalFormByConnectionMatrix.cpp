#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;
    //std::cin >> n;

    std::vector < std::vector <int>> connectMatrix(n, std::vector <int> (n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> connectMatrix[i][j];
            //std::cin >> connectMatrix[i][j];
        }
    }

    std::vector <int> canonForm(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (connectMatrix[i][j] == 1)
                canonForm[j] = i + 1;

    for (int i = 0; i < n; i++)
    {
        fout << canonForm[i] << ' ';
        //std::cout << canonForm[i] << ' ';
    }

    fout << std::endl;
    //std::cout << std::endl;

    fin.close();
    fout.close();

    return 0;
}

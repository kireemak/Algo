#include <iostream>
#include<fstream>
#include <vector>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    int m, n;
    fin >> n >> m;
    //std::cin >> n >> m;

    std::vector <std::vector <int>> connectMatrix(n, std::vector <int>(n, 0));
    for (int i = 0, pointA, pointB; i < m; i++)
    {
        fin >> pointA >> pointB;
        //std:: cin >> pointA >> pointB;
        pointA--;
        pointB--;
        connectMatrix[pointA][pointB]++;
        connectMatrix[pointB][pointA]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fout << connectMatrix[i][j] << (char)32;
            //std::cout << connectMatrix[i][j] << (char)32;
        }
        //std::cout << std::endl;
        fout << std::endl;
    }

    fin.close();
    fout.close();

    return 0;
}
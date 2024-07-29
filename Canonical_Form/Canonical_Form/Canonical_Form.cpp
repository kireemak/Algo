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

    std::vector <int> canonForm(n, 0);
    for (int i = 1, pointA, pointB; i < n; i++)
    {
        fin >> pointA >> pointB;
        //std::cin >> pointA >> pointB;
        pointB--;
        canonForm[pointB] = pointA;
    }

    for (int i = 0; i < n; i++)
    {
        fout << canonForm[i] << ' ';
        std::cout << canonForm[i] << ' ';
    }

    fout.close();
    fin.close();

    return 0;
}
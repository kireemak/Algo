#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;
    //std::cin >> n >> m;

    std::vector<std::vector<int>> adjList(n);
    for (int i = 0, pointA, pointB; i < m; i++)
    {
        fin >> pointA >> pointB;
        //std::cin >> pointA >> pointB;
        adjList[pointB - 1].push_back(pointA);
        adjList[pointA - 1].push_back(pointB);
    }

    for (int i = 0; i < n; i++)
    {
        fout << adjList[i].size();
        std::cout << adjList[i].size();

        for (auto it = adjList[i].rbegin(); it != adjList[i].rend(); it++)
        {
            fout << ' ' << *it;
            std::cout << ' ' << *it;
        }

        fout << std::endl;
        std::cout << std::endl;
    }

    fin.close();
    fout.close();

    return 0;
}

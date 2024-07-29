#include <iostream>
#include <fstream>
#include <vector>

class Node
{
    bool isVisited = false;
    int key = 0;

public:
    void setKey(int newKey)
    {
        this->key = newKey;
    }

    void visit()
    {
        this->isVisited = true;
    }

    int getKey()
    {
        return this->key;
    }

    int getVisited()
    {
        return this->isVisited;
    }
};

void dfsFunction(std::vector <std::vector <int>> connectMatrix, std::vector <Node>& graphNodes, int n, int& bufferKey, int index)
{
    graphNodes[index].visit();
    graphNodes[index].setKey(bufferKey++);

    for (int j = 0; j < n; j++)
        if (!graphNodes[j].getVisited() && connectMatrix[index][j] != 0)
            dfsFunction(connectMatrix, graphNodes, n, bufferKey, j);
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;
    //std::cin >> n;

    std::vector <Node> graphNodes(n);
    std::vector <std::vector <int>> connectMatrix(n, std::vector <int> (n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fin >> connectMatrix[i][j];
            //std::cin >> connectMatrix[i][j];
        }

    for (int i = 0, bufferKey = 1; i < n; i++)
    {
        if (!graphNodes[i].getVisited())
        {
            dfsFunction(connectMatrix, graphNodes, n, bufferKey, i);
        }

        fout << graphNodes[i].getKey() << ' ';
        std::cout << graphNodes[i].getKey() << ' ';
    }

    fin.close();
    fout.close();

    return 0;
}

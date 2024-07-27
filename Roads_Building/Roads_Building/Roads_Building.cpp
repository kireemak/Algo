#include <iostream>
#include <fstream>
//#include <vector>

class DSU
{
    //std::vector <int> parentVector, rankVector;
    int* parentArray;
    int* rankArray;

public:

    int componentsCount;

    DSU(int elementsCount)
    {
        componentsCount = elementsCount;
        parentArray = new int[elementsCount];
        rankArray = new int[elementsCount];

        for (int i = 0; i < elementsCount; i++)
        {
            rankArray[i] = 1;
            parentArray[i] = i;
        }
    }
    /*
    int findRoot(int element)
    {
        if (element == parentArray[element])
        {
            return element;
        }
        return parentArray[element] = findRoot(parentArray[element]);
    }
    */

    int findRoot(int node)
    {
        while (node != parentArray[node]) {
            parentArray[node] = parentArray[parentArray[node]];
            node = parentArray[node];
        }
        return node;
    }


    void unite(int elementA, int elementB)
    {
        int rootA = findRoot(elementA);
        int rootB = findRoot(elementB);
        if (rootA != rootB)
        {
            componentsCount--;
            if (rankArray[rootA] < rankArray[rootB])
            {
                int buffer = rootA;
                rootA = rootB;
                rootB = buffer;
            }
            parentArray[rootB] = rootA;
            if (rankArray[rootA] == rankArray[rootB])
            {
                rankArray[rootA]++;
            }
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int townsCount, roadsCount;
    std::cin >> townsCount >> roadsCount;
    //fin >> townsCount >> roadsCount;
    
    DSU townsDsu (townsCount);

    for (int i = 0; i < roadsCount; i++)
    {
        int town1, town2;
        std::cin >> town1 >> town2;
        //fin >> town1 >> town2;

        town1--;
        town2--;

        townsDsu.unite(town1, town2);
        std::cout << townsDsu.componentsCount << std::endl;
        //fout << townsDsu.componentsCount << std::endl;
    }

    fout.close();
    fin.close();

    return 0;
}
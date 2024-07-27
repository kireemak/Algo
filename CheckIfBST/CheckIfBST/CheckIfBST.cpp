#include <iostream>
#include <vector>
#include <fstream>

class Node
{
public:
    long long key;
    long long maxKey;
    long long minKey;
    char LorR;
    long long fatherI;
    
    Node()
    {    }
    /*
    Node(long long keyValue)
    {
        this->key = keyValue;
        this->maxKey = LLONG_MAX;
        this->minKey = LLONG_MIN;
    }*/
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::ofstream fout("bst.out");
    std::ifstream fin("bst.in");

    std::string answer = "YES";
    unsigned long long n;
    fin >> n;
    std::vector <Node> treeArray(n);
    fin >> treeArray[0].key;
    treeArray[0].minKey = LLONG_MIN;
    treeArray[0].maxKey = LLONG_MAX;

    for (unsigned long long i = 1; i < n; i++)
    {
        fin >> treeArray[i].key;
        fin >> treeArray[i].fatherI;
        treeArray[i].fatherI--;
        fin >> treeArray[i].LorR;

        if (treeArray[i].LorR == 'R')
        {
            treeArray[i].minKey = treeArray[treeArray[i].fatherI].key;
            treeArray[i].maxKey = treeArray[treeArray[i].fatherI].maxKey;
        }
        else if (treeArray[i].LorR == 'L')
        {
            treeArray[i].minKey = treeArray[treeArray[i].fatherI].minKey;
            treeArray[i].maxKey = treeArray[treeArray[i].fatherI].key;
        }

        if (treeArray[i].key >= treeArray[i].maxKey || treeArray[i].key < treeArray[i].minKey)
        {
            answer = "NO";
            break;
        }
    }

    std::cout << answer;// << std::endl;
    fout << answer;// << std::endl;

    fin.close();
    fout.close();

    return 0;
}
#include <iostream>
#include <fstream>
//#include <vector>

class DSU
{
    long* parent;
    long* rank;
    //std::vector<long> parent;
    //std::vector<long> rank;

public:
    DSU(long n)// : parent(n + 1), rank(n + 1, 0)
    {
        parent = new long[n + 1];
        rank = new long[n + 1] {0};
        for (long i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    /*
    long find(long x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    */

    long find(long x)
    {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(long x, long y)
    {
        long root_x = find(x);
        long root_y = find(y);

        if (root_x != root_y) {
            if (rank[root_x] < rank[root_y])
            {
                std::swap(root_x, root_y);
            }
            parent[root_y] = root_x;
            if (rank[root_x] == rank[root_y])
            {
                rank[root_x]++;
            }
        }
    }

    bool is_connected(long n)
    {
        long root = this->find(1);

        for (long i = 2; i <= n; i++)
        {
            if (this->find(i) != root)
            {
                return false;
            }
        }

        return true;
    }
};



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    long n, m, q;
    //std::cin >> n >> m >> q;
    fin >> n >> m >> q;

    //std::vector<std::pair<long, long>> roads(m);
    std::pair<long, long>* roads = new std::pair<long, long>[m];
    for (long i = 0; i < m; i++)
    {
        //std::cin >> roads[i].first >> roads[i].second;
        fin >> roads[i].first >> roads[i].second;
    }

    DSU dsu(n);
    
    //std::vector <long> earthquakesVector(q);
    long* earthquakesVector = new long[q];
    for (long i = 0; i < q; i++)
    {
        //std::cin >> earthquakesVector[i];
        fin >> earthquakesVector[i];
    }
    //std::vector <long> answerVector(q, 1);
    long* answerVector = new long [q];
    for (long i = q - 1; i >= 0; i--)
    {
        answerVector[i] = 1;
        long index = earthquakesVector[i];
        index--;
        long town1 = roads[index].first;
        long town2 = roads[index].second;

        if (!dsu.is_connected(n))
        {
            answerVector[i] = 0;
        }

        dsu.Union(town1, town2);
    }

    for (long i = 0; i < q; i++)
    {
        std::cout << answerVector[i];
        fout << answerVector[i];
    }

    //std::cout << std::endl;
    fout << std::endl;

    fin.close();
    fout.close();

    return 0;
}



// Что, если q != m ?
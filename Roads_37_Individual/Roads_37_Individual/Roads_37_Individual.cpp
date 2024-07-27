#include <iostream>
#include <fstream>
//#include <vector>

class DSU
{
    int* parent;
    int* rank;
    //std::vector<int> parent;
    //std::vector<int> rank;

public:
    DSU(int n)// : parent(n + 1), rank(n + 1, 0)
    {
        parent = new int [n + 1];
        rank = new int[n + 1] {0};
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    /*
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    */

    int find(int x)
    {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);

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

    bool is_connected(int n)
    {
        int root = this->find(1);

        for (int i = 2; i <= n; i++)
        {
            if (this->find(i) != root)
            {
                return false;
            }
        }

        return true;
    }
};



void main()
{
    std::ifstream fin("input.txt");
    //std::ofstream fout("output.txt");

    int n, m;
    std::cin >> n >> m;
    //fin >> n >> m;

    //std::vector<std::pair<int, int>> roads(m);

    std::pair <int, int>* roads = new std::pair <int, int>[m];

    for (int i = 0; i < m; i++)
    {
        std::cin >> roads[i].first >> roads[i].second;
        //fin >> roads[i].first >> roads[i].second;
    }

    DSU dsu(n);

    for (int i = m - 1; i >= 0; i--)
    {
        int town1 = roads[i].first;
        int town2 = roads[i].second;
        dsu.Union(town1, town2);

        if (dsu.is_connected(n))
        {
            //fout << i + 1 << std::endl;
            std::cout << i + 1 << std::endl;

            //fin.close();
            //fout.close();

            return;
        }
    }

    std::cout << -1 << std::endl;
    //fout << -1 << std::endl;

    //fin.close();
    //fout.close();

    return;
}
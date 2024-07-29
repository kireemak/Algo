/*#include <iostream>
#include <fstream>
#include <vector>

struct Edge {
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
    vector<int> parent, rank;
public:

    UnionFind(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};
*/

#include <iostream>
#include <fstream>
#include <vector>

class DSU
{
    int* parent;
    int* rank;
    //std::vector<int> parent;
    //std::vector<int> rank;

public:
    DSU(int n)// : parent(n + 1), rank(n + 1, 0)
    {
        parent = new int[n + 1];
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
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int x, int y)
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

std::vector <std::pair <int, int>> findMST(std::vector <std::pair <int, int>> edgesVector, int n)
{
    std::vector <std::pair <int, int>> answerVector;
    DSU dsu(n);

    for (std::pair <int, int> edge : edgesVector)
    {
        if (dsu.find(edge.first) != dsu.find(edge.second))
        {
            answerVector.push_back(edge);
            dsu.unite(edge.first, edge.second);
        }
    }

    return answerVector;
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    std::cin >> n;
    fin >> n;

    std::vector <std::pair <int, int>> edgesVector;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, isEdge; j < n; j++)
        {
            std::cin >> isEdge;
            fin >> isEdge;
            
            if (j < i && isEdge)
                edgesVector.emplace_back(i + 1, j + 1);
        }
    }

    std::vector <std::pair <int, int>> answerVector = findMST(edgesVector, n);

    if (answerVector.size() == n - 1)
    {
        std::cout << n - 1 << std::endl;
        fout << n - 1 << std::endl;
        
        for (std::pair <int, int> edge : answerVector)
        {
            std::cout << edge.first << ' ' << edge.second << std::endl;
            fout << edge.first << ' ' << edge.second << std::endl;
        }
    }
    else
    {
        std::cout << -1 << std::endl;
        fout << -1 << std::endl;
    }

    fin.close();
    fout.close();

    return 0;
}
/*
#include <iostream>
#include <fstream>
#include <vector>

class SegmentTreeNode
{
public:
    long long sum;
};

void DoBuild(const std::vector<long long>& A, std::vector<SegmentTreeNode>& tree, long long vertex, long long tl, long long tr)
{
    if (tr - tl == 1)
    {
        tree[vertex].sum = A[tl];
    }
    else
    {
        long long m = (tl + tr) / 2;
        DoBuild(A, tree, 2 * vertex, tl, m);
        DoBuild(A, tree, 2 * vertex + 1, m, tr);
        tree[vertex].sum = tree[2 * vertex].sum + tree[2 * vertex + 1].sum;
    }
}

std::vector<SegmentTreeNode> buildTree(const std::vector<long long>& A, long long n)
{
    std::vector<SegmentTreeNode> tree(4 * n);
    DoBuild(A, tree, 1, 0, n);
    return tree;
}

void DoAdd(std::vector<SegmentTreeNode>& tree, long long vertex, long long tl, long long tr, long long i, long long x)
{
    if (tr - tl == 1)
    {
        tree[vertex].sum += x;
        return;
    }

    long long m = (tl + tr) / 2;
    if (i < m)
    {
        DoAdd(tree, 2 * vertex, tl, m, i, x);
    }
    else
    {
        DoAdd(tree, 2 * vertex + 1, m, tr, i, x);
    }

    tree[vertex].sum = tree[2 * vertex].sum + tree[2 * vertex + 1].sum;
}

void updateTree(std::vector<SegmentTreeNode>& tree, long long n, long long i, long long x)
{
    DoAdd(tree, 1, 0, n, i, x);
}

long long DoFindSum(const std::vector<SegmentTreeNode>& tree, long long vertex, long long tl, long long tr, long long l, long long r)
{
    if (l == tl && r == tr)
    {
        return tree[vertex].sum;
    }

    long long m = (tl + tr) / 2;
    if (r <= m)
    {
        return DoFindSum(tree, 2 * vertex, tl, m, l, r);
    }
    if (m <= l)
    {
        return DoFindSum(tree, 2 * vertex + 1, m, tr, l, r);
    }

    return (DoFindSum(tree, 2 * vertex, tl, m, l, m) +
        DoFindSum(tree, 2 * vertex + 1, m, tr, m, r));
}

long long querySum(const std::vector<SegmentTreeNode>& tree, long long n, long long l, long long r)
{
    return DoFindSum(tree, 1, 0, n, l, r);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    //std::ifstream fin("input.txt");
    //std::ofstream fout("output.txt");

    long long n;
    std::cin >> n;
    //fin >> n;

    std::vector<long long> inputArray(n);
    for (long long i = 0; i < n; i++)
    {
        std::cin >> inputArray[i];
        //fin >> inputArray[i];
    }

    std::vector<SegmentTreeNode> tree;
    //buildTree(inputArray, tree, 0, 0, n - 1);
    tree = buildTree(inputArray, n);


    long long q;
    std::cin >> q;
    //fin >> q;

    for (long long i = 0; i < q; i++)
    {
        std::string queryType;
        std::cin >> queryType;
        //fin >> queryType;

        if (queryType == "Add")
        {
            long long index, x;
            std::cin >> index >> x;
            //fin >> index >> x;
            updateTree(tree, n, index, x);
        }
        else if (queryType == "FindSum")
        {
            long long l, r;
            std::cin >> l >> r;
            //fin >> l >> r;
            long long sum = querySum(tree, n, l, r);
            std::cout << sum << std::endl;
            //fout << sum << std::endl;
        }
    }

    return 0;
}
*/


#include <iostream>

class SegmentTreeNode
{
public:
    long long sum;
};

void DoBuild(const long long* A, SegmentTreeNode* tree, long long vertex, long long tl, long long tr)
{
    if (tr - tl == 1)
    {
        tree[vertex].sum = A[tl];
    }
    else
    {
        long long m = (tl + tr) / 2;
        DoBuild(A, tree, 2 * vertex, tl, m);
        DoBuild(A, tree, 2 * vertex + 1, m, tr);
        tree[vertex].sum = tree[2 * vertex].sum + tree[2 * vertex + 1].sum;
    }
}

SegmentTreeNode* buildTree(const long long* A, long long n)
{
    SegmentTreeNode* tree = new SegmentTreeNode[4 * n];
    DoBuild(A, tree, 1, 0, n);
    return tree;
}

void DoAdd(SegmentTreeNode* tree, long long vertex, long long tl, long long tr, long long i, long long x)
{
    if (tr - tl == 1)
    {
        tree[vertex].sum += x;
        return;
    }

    long long m = (tl + tr) / 2;
    if (i < m)
    {
        DoAdd(tree, 2 * vertex, tl, m, i, x);
    }
    else
    {
        DoAdd(tree, 2 * vertex + 1, m, tr, i, x);
    }

    tree[vertex].sum = tree[2 * vertex].sum + tree[2 * vertex + 1].sum;
}

void updateTree(SegmentTreeNode* tree, long long n, long long i, long long x)
{
    DoAdd(tree, 1, 0, n, i, x);
}

long long DoFindSum(const SegmentTreeNode* tree, long long vertex, long long tl, long long tr, long long l, long long r)
{
    if (l == tl && r == tr)
    {
        return tree[vertex].sum;
    }

    long long m = (tl + tr) / 2;
    if (r <= m)
    {
        return DoFindSum(tree, 2 * vertex, tl, m, l, r);
    }
    if (m <= l)
    {
        return DoFindSum(tree, 2 * vertex + 1, m, tr, l, r);
    }

    return (DoFindSum(tree, 2 * vertex, tl, m, l, m) +
        DoFindSum(tree, 2 * vertex + 1, m, tr, m, r));
}

long long querySum(const SegmentTreeNode* tree, long long n, long long l, long long r)
{
    return DoFindSum(tree, 1, 0, n, l, r);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    long long n;
    std::cin >> n;

    long long* inputArray = new long long[n];
    for (long long i = 0; i < n; i++)
    {
        std::cin >> inputArray[i];
    }

    SegmentTreeNode* tree = buildTree(inputArray, n);

    long long q;
    std::cin >> q;

    for (long long i = 0; i < q; i++)
    {
        std::string queryType;
        std::cin >> queryType;

        if (queryType == "Add")
        {
            long long index, x;
            std::cin >> index >> x;
            updateTree(tree, n, index, x);
        }
        else if (queryType == "FindSum")
        {
            long long l, r;
            std::cin >> l >> r;
            long long sum = querySum(tree, n, l, r);
            std::cout << sum << std::endl;
        }
    }

    delete[] inputArray;
    delete[] tree;

    return 0;
}

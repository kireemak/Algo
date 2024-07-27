#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;
    std::vector <long> arr(n);
    for (int c = 0; c < n; c++)
        fin >> arr[c];

    bool flag = true;
    for (int c = 0; (c <= n / 2 - 1) && flag; c++)
        if (((arr[2 * c + 1] < arr[c]) && (2 * c + 1 < n)) ||
            ((arr[2 * c + 2] < arr[c]) && (2 * c + 2 < n)))
            flag = false;

    if (flag)
    {
        std::cout << "YES" << std::endl;
        fout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
        fout << "NO" << std::endl;
    }

    fout.close();
    fin.close();

    return 0;
}
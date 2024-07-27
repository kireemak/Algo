#include <iostream>
#include <string>
#include <fstream> 
#include <set>

int main()
{
    std::ofstream fout;
    std::ifstream fin;
    std::set <int> arr;
    fin.open("input.txt", std::ios_base::in);
    fout.open("output.txt", std::ios_base::out);

    int x;
    long sum = 0;
    
    while (fin >> x)
    {
        arr.insert(x);
    }
    
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        sum += *it;
    }
    std::cout << sum << std::endl;
    fout << sum;

    fin.close();
    fout.close();

    return 0;
}


/*
    if (!fin.is_open())
    {
        throw - 1;
    }
    */

    /*
        while (!fin.eof())
        {
            fin >> x;
            sum += x;
        }
        */
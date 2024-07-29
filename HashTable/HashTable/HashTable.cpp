/*
#include <iostream>
#include <fstream>

int hashF(int key, int i, int m, int c)
{
    return ((key % m) + c * i) % m;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int hashTableSize, keysAmount, HASH_CONST;
    fin >> hashTableSize >> HASH_CONST >> keysAmount;

    //our table will be there (direct addresation method used, so it's 1D vector)
    //default values == -1 (empty)
    int* hashTable = new int[hashTableSize];

    for (int i = 0; i < hashTableSize; ++i)
    {
        hashTable[i] = -1;
    }

    for (int i = 0; i < keysAmount; ++i)
    {
        int key;
        int count = 0, j;  //iterations counters

        fin >> key;

        j = hashF(key, count, hashTableSize, HASH_CONST);
        ++count;

        if (hashTable[j] == -1)  //if the vault is empty, no problems with insertion
        {
            hashTable[j] = key;
        }
        else  //else there's a collision
        {
            if (hashTable[j] == key)  //if such element already exists, we don't do anything
            {
                continue;
            }
            else  //else there's a collision, => we move to the next iteration
            {
                do
                {
                    j = hashF(key, count, hashTableSize, HASH_CONST);
                    ++count;
                } while ((hashTable[j] != -1) && (hashTable[j] != key));

                if ((j < hashTableSize) && (hashTable[j] == -1))
                {
                    hashTable[j] = key;
                }
            }
        }
    }

    //hash table output
    for (int i = 0; i < hashTableSize; ++i)
    {
        fout << hashTable[i] << " ";
    }
    //fout << "\n";

    delete[] hashTable;
    fin.close();
    fout.close();

    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int m, c, n;
    fin >> m >> c >> n;
    //std::cin >> m >> c >> n;

    std::vector<int> hashTable(m, -1);

    for (int k = 0, x, index, i = 0; k < n; k++, i = 0)
    {
        fin >> x;
        //std::cin >> x;

        index = ((x % m) + c * i) % m;
        i++;

        if (hashTable[index] == -1)
            hashTable[index] = x;
        else
            if (hashTable[index] != x)
            {
                while ((hashTable[index] != -1) && (hashTable[index] != x))
                {
                    index = ((x % m) + c * i) % m;
                    i++;
                }
                hashTable[index] = x;
            }
            else
                continue;
    }

    for (int i = 0; i < m; i++)
    {
        fout << hashTable[i] << ' ';
        std::cout << hashTable[i] << ' ';
    }
    fout << std::endl;
    std::cout << std::endl;

    fout.close();
    fin.close();

    return 0;
}

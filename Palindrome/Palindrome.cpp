#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::string startString, revString;

    fin >> startString;
    int m = startString.size() + 1;

    revString = startString;
    reverse(revString.begin(), revString.end());

    std::string** Palindroms = new std::string*[m];
    for (int i = 0; i < m; i++)
    {
        Palindroms[i] = new std::string[m];
    }
    /*
    std::vector <std::vector <std::string>> Palindroms(m);
    for (int i = 0; i < m; i++)
    {
        std::vector <std::string> buffer(m);
        Palindroms[i].assign(buffer.begin(), buffer.end());
    }
    */
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (startString[i - 1] == revString[j - 1])
            {
                Palindroms[i][j] = Palindroms[i - 1][j - 1] + revString[j - 1];
            }
            else
            {
                if (Palindroms[i - 1][j].size() > Palindroms[i][j - 1].size())
                {
                    Palindroms[i][j] = Palindroms[i - 1][j];
                }
                else
                {
                    Palindroms[i][j] = Palindroms[i][j - 1];
                }
            }
        }
    }

    fout << Palindroms[m - 1][m - 1].length() << std::endl;
    fout << Palindroms[m - 1][m - 1];

    fin.close();
    fout.close();

    return 0;
}
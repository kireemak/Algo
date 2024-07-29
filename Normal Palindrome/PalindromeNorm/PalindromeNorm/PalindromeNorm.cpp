#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::ofstream fout ("output.txt");
    std::ifstream fin("input.txt");

    std::string str;
    //std::cin >> str;
    fin >> str;

    /*
    int** matrix = new int*[str.length()];
    for (int i = 0; i < str.length(); i++)
    {
        matrix[i] = new int[str.length()];
    }
    */

    std::vector <std::vector <int>> matrix;
    for (int i = 0; i < str.length(); i++)
    {
        std::vector <int> buffer(str.length());
        matrix.push_back(buffer);
    }

    for (int i = 0; i < str.length(); i++)
    {
        matrix[i][i] = 1;

        if (i != str.length() - 1)
        {
            matrix[i][i + 1] = 1;
            if (str[i] == str[i + 1])
            {
                matrix[i][i + 1] = 2;
            }
        }
    }

    for (int i = 2; i < str.length(); i++)
    {
        for (int j = 0; j < str.length() - i; j++)
        {
            if (str[j] == str[j + i])
            {
                matrix[j][j + i] = matrix[j + 1][j + i - 1] + 2;
            }
            else
            {
                matrix[j][j + i] = (matrix[j + 1][j + i] > matrix[j][j + i - 1]) ? matrix[j + 1][j + i] : matrix[j][j + i - 1];
            }
        }
    }

    int palindromeLength = matrix[0][str.length() - 1];
    fout << palindromeLength << std::endl;

    std::vector <char> palindrome(palindromeLength);
    int k = str.length() - 1, m = 0, n = 0;
    while (true)
    {
        if (k <= m)
        {
            palindrome[palindromeLength / 2] = str[k];
            break;
        }

        if (str[k] == str[m])
        {
            palindrome[n] = str[k];
            palindrome[palindromeLength - n - 1] = str[k];
            k--;    m++;    n++;
        }
        else if(matrix[m][k - 1] > matrix[m + 1][k])
        {

            k--;
        }
        else
        {
            m++;
        }
    }

    for (int i = 0; i < palindrome.size(); i++)
    {
        fout << palindrome[i];
    }
    fout << std::endl;
    /*
    for (int i = 0; i < str.length(); i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    */
    fout.close();
    fin.close();

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int replaceFunc(char x, char y)
{
    return !(x == y);
}

int findLD( std::string badString, std::string goodString, int deletePoints, int insertPoints, int replacePoints)
{
    std::vector <std::vector <int>> matrix(badString.length() + 1);
    for (int i = 0; i <= badString.length(); i++)
    {
        std::vector <int> temp(goodString.length() + 1);
        matrix[i] = temp;
    }

    for (int i = 0; i <= badString.length(); i++)
    {
        for (int j = 0; j <= goodString.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                matrix[i][j] = i * deletePoints + j * insertPoints;
                continue;
            }

            matrix[i][j] = (matrix[i - 1][j] + deletePoints < matrix[i][j - 1] + insertPoints) 
                ? (matrix[i - 1][j] + deletePoints < matrix[i - 1][j - 1] + replacePoints * replaceFunc(goodString[j - 1], badString[i - 1])) 
                    ? matrix[i - 1][j] + deletePoints
                    : matrix[i - 1][j - 1] + replacePoints * replaceFunc(goodString[j - 1], badString[i - 1])
                : (matrix[i][j - 1] + insertPoints < matrix[i - 1][j - 1] + replacePoints * replaceFunc(goodString[j - 1], badString[i - 1]))
                    ? matrix[i][j - 1] + insertPoints
                    : matrix[i - 1][j - 1] + replacePoints * replaceFunc(goodString[j - 1], badString[i - 1]);
        }
    }

    return matrix[badString.length()][goodString.length()];
}

int main()
{
    std::ofstream fout("out.txt");
    std::ifstream fin("in.txt");

    std::string str1, str2;
    int deletePoints, insertPoints, replacePoints;

    fin >> deletePoints >> insertPoints >> replacePoints >> str1 >> str2;
    fout << findLD(str1, str2, deletePoints, insertPoints, replacePoints) << std::endl;
    //std::cout << findLD(str1, str2, deletePoints, insertPoints, replacePoints) << std::endl;

    fin.close();
    fout.close();

    return 0;
}
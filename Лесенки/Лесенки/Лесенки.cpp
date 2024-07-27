/*#include <iostream>
#include <fstream>

int getPyramedsCount(int, int);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::ofstream fout("output.txt", std::ios_base::out);
    std::ifstream fin("input.txt", std::ios_base::in);

    int blockCount, pyramedsCount = 0;
    fin >> blockCount;
    std::cin >> blockCount;

    int saveI = 1;
    for (int i = 1, maxCount = 0; maxCount < blockCount; i++, maxCount += i)
    {
        saveI = i;
    }
    
    int basicFloor = blockCount;
    while (basicFloor >= saveI)
    {
        pyramedsCount += getPyramedsCount(basicFloor, blockCount - basicFloor);
        basicFloor--;
    }
    
    fout << pyramedsCount;
    std::cout << pyramedsCount << std::endl;

    fin.close();
    fout.close();
    
    return 0;
}

int getPyramedsCount(int lastFloor, int remainBlocks)
{
    int count = 0;

    if (remainBlocks == 0)
    {
        return 1;
    }

    for (int thisFloor = 1; thisFloor < lastFloor; thisFloor++)
    {
        if (remainBlocks - thisFloor < 0)
        {
            break;
        }
        count += getPyramedsCount(thisFloor, remainBlocks - thisFloor);
    }

    return count;
}*/

#include <iostream>
#include <fstream>
#include <vector>

unsigned long long countStaircases(int n)
{
    //unsigned long long result;
    std::vector<std::vector<unsigned long long>> matrix(n + 1, std::vector<unsigned long long>(n + 1));
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            matrix[i][j] = matrix[i - j - 1][j + 1] + matrix[i][j + 1];
        }
    }

    return matrix[n - 1][0];
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    //std::cin >> n;
    fin >> n;

    unsigned long long result = countStaircases(n);

    //std::cout << result << std::endl;
    fout << result << std::endl;
    
    fout.close();
    fin.close();
    
    return 0;
}
/*
#include <iostream>
#include <vector>

int countStaircases(int n) {
    // Создаем двумерный вектор dp, где dp[i][j] представляет количество лесенок из i кубиков с j уровнями.
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    // Инициализируем базовые случаи:
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1; // Любое количество кубиков можно использовать для построения лесенки из 0 уровней.
        dp[i][1] = 1; // Любое количество кубиков можно использовать для построения лесенки из 1 уровня.
    }

    // Заполняем dp таблицу для всех остальных случаев.
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - j][j - 1];
        }
    }

    // Результат находится в dp[n][n], где n - количество кубиков и количество уровней.
    return dp[n][n] - 1; // Исправление: вычитаем 1, так как начальный случай, где нет уровней (пустая лесенка), учитывается дважды.
}

int main() {
    int n;
    std::cout << "Введите количество кубиков (n): ";
    std::cin >> n;

    int result = countStaircases(n);

    std::cout << "Число лесенок, которые можно построить из " << n << " кубиков: " << result << std::endl;

    return 0;
}*/
/*
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> dp; // Динамическая таблица для мемоизации

int getPyramedsCount(int lastFloor, int remainBlocks) {
    if (remainBlocks == 0) {
        return 1;
    }

    if (dp[lastFloor][remainBlocks] != -1) {
        return dp[lastFloor][remainBlocks];
    }

    int count = 0;
    for (int thisFloor = lastFloor - 1; thisFloor >= 1 && remainBlocks - thisFloor >= 0; thisFloor--) {
        count += getPyramedsCount(thisFloor, remainBlocks - thisFloor);
    }

    dp[lastFloor][remainBlocks] = count;
    return count;
}

int main() {
    std::ofstream fout("output.txt");
    std::ifstream fin("input.txt");

    int blockCount, pyramedsCount = 0;
    fin >> blockCount;
    std::cin >> blockCount;
    // Инициализируем dp таблицу
    dp.assign(blockCount + 1, std::vector<int>(blockCount + 1, -1));

    for (int basicFloor = blockCount; basicFloor >= 1; basicFloor--) {
        pyramedsCount += getPyramedsCount(basicFloor, blockCount - basicFloor);
    }

    fout << pyramedsCount << std::endl;
    std::cout << pyramedsCount << std::endl;

    fin.close();
    fout.close();

    return 0;
}*/

#include <iostream>
#include <fstream>
#include <vector>

//long long getHuffmanLength(std::vector <int> inputVector)
long long getHuffmanLength(int* inputVector, int n)
{
    long long* buffVector = new long long[n - 1];
    //std::vector <long long> buffVector(inputVector.size() - 1);
    //std::vector <long long> buffVector;
    long long buffer, answer = buffer = inputVector[0] + inputVector[1];
    buffVector[0] = buffer;
    //buffVector.push_back(buffer);

    for (int i = 2, j = 0, k = 1; k < n - 1; k++)
    {
        if (i < n)
        {
            buffer = 0;
            for (int c = 0; c < 2; c++)
            {
                if (i == n)
                {
                    buffer += buffVector[j];
                    j++;
                    continue;
                }
                if (j == k)
                {
                    buffer += inputVector[i];
                    i++;
                    continue;
                }
                if (inputVector[i] < buffVector[j])
                {
                    buffer += inputVector[i];
                    i++;
                    continue;
                }
                buffer += buffVector[j];
                j++;
            }
        }
        else //if (i >= inputVector.size())
        {
            buffer = buffVector[j] + buffVector[j + 1];
            j += 2;
        }

        answer += buffer;
        //buffVector.push_back(buffer);
        buffVector[k] = buffer;
    }

    return answer;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::ifstream fin("huffman.in");
    std::ofstream fout("huffman.out");
    
    int n, buffer, i = 0;
    fin >> n;
    //std::vector <int> inputVector(n);
    int* inputVector = new int[n];
    while (fin >> buffer)
    {
        inputVector[i] = buffer;
        i++;
    }

    long long answer = getHuffmanLength(inputVector, n);

    fout << answer << std::endl;
    //std::cout << answer << std::endl;

    //delete[] inputVector;

    //fin.close();
    //fout.close();

    return 0;
}
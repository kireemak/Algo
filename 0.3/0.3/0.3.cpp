#include <iostream>

unsigned long long exponentiationByFerm(unsigned long long base, int exponent, int mod)
{
    if (exponent == 0)
    {
        return 1;
    }

    if (exponent % 2 == 1)
    {
        return ((exponentiationByFerm(base, exponent - 1, mod) % mod) * (base % mod)) % mod;
    }
    else
    {
        unsigned long long f = exponentiationByFerm(base, exponent / 2, mod) % mod;
        return (f * f) % mod;
    }
}


int main()
{
	int n, k;
	int mod = 1000000007;

    std::cin >> n >> k;

    int* fact = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            fact[i] = 1;
            continue;
        }
        fact[i] = (fact[i - 1] * i) % mod;
    }

	std::cout <<(fact[n] * exponentiationByFerm(fact[k], mod - 2, mod) % mod
        * exponentiationByFerm(fact[n-k], mod - 2, mod) % mod) % mod << std::endl;

    return 0;
}
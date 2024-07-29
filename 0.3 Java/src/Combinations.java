import java.util.*;

public class Combinations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), k = scanner.nextInt(), mod = 1000000007;

        long[] fact = new long[n + 1];
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                fact[i] = 1;
                continue;
            }
            fact[i] = (fact[i - 1] * i) % mod;
        }

        long buffer1 = exponentiationByFerm(fact[k], mod - 2, mod);
        long buffer2 = exponentiationByFerm(fact[n-k], mod - 2, mod);

        System.out.println((fact[n] * buffer1 % mod
                * buffer2 % mod) % mod);
    }

    public static long exponentiationByFerm(long base, int exponent, int mod)
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
            long buffer = exponentiationByFerm(base, exponent / 2, mod) % mod;
            return (buffer * buffer) % mod;
        }
        /*
        long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
        */
    }
}

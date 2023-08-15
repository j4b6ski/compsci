#include <iostream>
#include <random>

const int min_n = 2;
const int max_n = 2;

const int min_a = 46332;
const int max_a = 46342;

int main()
{
    int seed;
    std::cin >> seed;

    std::mt19937 gen(seed);
    const int n = (gen() % (max_n - min_n + 1)) + min_n;
    // std::cout << n << "\n";

    for (int i = 0; i < n; ++i)
    {
        const int a = (gen() % (max_a - min_a + 1)) + min_a;
        std::cout << a << " ";
    }
}

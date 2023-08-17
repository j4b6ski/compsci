#include <iostream>
#include <random>

using namespace std;
int main()
{
    int s;
    cin >> s;

    mt19937 gen;
    gen.seed(s);

    int n = 10;
    cout << n << "\n";
    for (int i = 1; i < n; ++i)
    {
        int a = i;
        int b = gen() % i;
        cout << a + 1 << " " << b + 1 << "\n";
    }
}

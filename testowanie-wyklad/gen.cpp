#include <iostream>
#include <random>

using namespace std;

int main()
{
    int s;
    cin >> s;

    mt19937 gen;
    gen.seed(s);

    cout << gen() % 50000 << " " << gen() % 50000 << "\n";
}

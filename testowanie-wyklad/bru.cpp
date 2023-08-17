#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    long long result = 0;
    for (int i = 0; i < a; ++i)
    {
        result += b;
    }
    cout << result;
}

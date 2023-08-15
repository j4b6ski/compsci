#include <iostream>

int main()
{
    int64_t a, b;
    std::cin >> a >> b;
    int64_t result = 0; 
    for (int i = 0; i < a; ++i)
    {
        result += b;
    }
    std::cout << result;
}

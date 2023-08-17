#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    while(next_permutation(a.begin(), a.end()))
    {
        for (int x : a)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

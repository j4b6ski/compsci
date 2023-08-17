#include <iostream>
#include <cstdlib>

using namespace std;

int call(string cmd)
{
    cout << "running: " << cmd << "\n";
    return system(cmd.c_str());
}

int main()
{
    call("mkdir in");
    call("mkdir out");
    for (int i = 0; i < 1000; ++i)
    {
        string test = "in/test" + to_string(i) + ".in";
        string wzo = "out/wzo" + to_string(i) + ".out";
        string bru = "out/bru" + to_string(i) + ".out";

        call("echo " + to_string(i) + " | ./gen > " + test);
        call("./wzo < " + test + " > " + wzo);
        call("./bru < " + test + " > " + bru);
        int status = call("diff --ignore-all-space " + wzo + " " + bru);
        if (status == 0)
        {
            cout << "OK - " << i << "\n";
        }
        else
        {
            cout << "WRONG ANSWER - " << i << "\n";
            break;
        }
    }
    return 0;
}

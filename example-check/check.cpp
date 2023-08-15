#include <cstdlib>
#include <iostream>

const std::string gen = "./gen";
const std::string wzo = "./wzo";
const std::string bru = "./bru";

int call(std::string cmd)
{
    // std::cerr << cmd << std::endl;
    return std::system(cmd.c_str());
}

int main()
{   
    call("g++ gen.cpp -o " + gen);
    call("g++ wzo.cpp -o " + wzo);
    call("g++ bru.cpp -o " + bru);
    call("mkdir in");
    call("mkdir out");
    
    std::cout << "liczba testow: ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        const std::string seed = std::to_string(i);
        const std::string test_in = "in/" + std::to_string(i) + ".in";
        const std::string wzo_out = "out/" + std::to_string(i) + "_wzo.out";
        const std::string bru_out = "out/" + std::to_string(i) + "_bru.out";

        call("echo " + seed + " | " + gen + " > " + test_in);
        call(wzo + " < " + test_in + " > " + wzo_out);
        call(bru + " < " + test_in + " > " + bru_out);
        const int diff = call("diff -q " + wzo_out + " " + bru_out);
        if (diff == 0)
        {
            std::cout << i << " - OK" << std::endl;
        }
        else
        {
            std::cout << i << " - ZLA ODPOWIEDZ" << std::endl;
            return 1;
        }
    }
}

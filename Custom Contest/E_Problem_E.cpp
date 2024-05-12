#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

std::vector<int> generatePrimes(int start, int end)
{
    std::vector<int> primes;
    for (int num = start; num <= end; ++num)
    {
        if (isPrime(num))
            primes.push_back(num);
    }
    return primes;
}

int main()
{
    std::string input1 = "1 10";
    std::string input2 = "3 5";

    std::istringstream stream1(input1), stream2(input2);
    int start1, end1, start2, end2;
    stream1 >> start1 >> end1;
    stream2 >> start2 >> end2;

    std::vector<int> primes1 = generatePrimes(start1, end1);
    std::vector<int> primes2 = generatePrimes(start2, end2);

    for (int prime : primes1)
    {
        std::cout << prime << std::endl;
    }
    std::cout << std::endl;
    for (int prime : primes2)
    {
        std::cout << prime << std::endl;
    }

    return 0;
}

#include <iostream>

int main()
{
    int rows;

    std::cin >> rows;

    // Print the upper half of the pattern
    for (int i = 0; i < rows; ++i)
    {
        // Print spaces
        for (int j = 0; j < rows - i - 1; ++j)
        {
            std::cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i + 1; ++k)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // Print the lower half of the pattern
    for (int i = rows - 1; i >= 0; --i)
    {
        // Print spaces
        for (int j = 0; j < rows - i - 1; ++j)
        {
            std::cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i + 1; ++k)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}

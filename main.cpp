#include <iostream>
#include <fstream>
#include <string>
 
int main()
{
    std::string line;
    std::string fileName ("text.txt");
 
    std::ifstream in(fileName);
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();

    std::ofstream out(fileName, std::ios::app);
    if (out.is_open())
    {
        out << "Welcome to C++" << std::endl;
    }
    out.close();   

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();

    return 0;
}
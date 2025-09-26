#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }

    Harl harl;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for(int i = 0;i < 4;i++)
    {
        if(levels[i] == argv[1])
        {
            for(int j = i;j < 4;j++)
            {
                harl.complain(levels[j]);
                std::cout << std::endl;
            }
            return 0;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return 0;
}
#include <iostream>
#include <fstream>


std::string ft_replace(std::string str, std::string s1, std::string s2)
{
    std::string new_str = "";

    if (s1.empty()) {
        return str;
    }

    while(str.find(s1) != std::string::npos)
    {
        new_str += str.substr(0, str.find(s1));
        if(!s2.empty())
            new_str += s2;
        str = str.substr(str.find(s1) + s1.length());
    }
    return new_str + str;
}

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if(!file.is_open())
    {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return 1;
    }
    std::ofstream new_file(argv[1] + std::string(".replace"));

    if (!new_file.is_open())
    {
        std::cerr << "Error: could not create file " << argv[1] + std::string(".replace") << std::endl;
        return 1;
    }

    std::string s;

    while(std::getline(file, s))
    {
        s = ft_replace(s, argv[2], argv[3]);
        new_file << s;
        if(!file.eof())
            new_file << std::endl;
    }
    
    if(file.fail() && !file.eof())
    {
        std::cerr << "Error: could not read file " << argv[1] << std::endl;
        return 1;
    }
    file.close();
    return 0;
}
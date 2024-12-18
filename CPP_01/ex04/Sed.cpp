#include "Sed.hpp"

static int  openFile(char *filename, std::string &data)
{
    std::ifstream   file(filename);
    if (!file.is_open())
    {
        
    }
}

int    sed(char *filename, std::string s1, std::string s2)
{
    std::string data;

    if (openFile(filename, data) == 1)
        return 1;
}

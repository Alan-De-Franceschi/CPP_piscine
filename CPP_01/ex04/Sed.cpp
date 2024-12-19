#include "Sed.hpp"

static int  openFile(char *filename, std::string &data)
{
    std::ifstream   file(filename);
    if (!file.is_open())
    {
        std::cout
            << "failed to open: "
            << filename
            << std::endl;
        return (1);
    }
    std::getline(file, data);
    file.close();
    return (0);
}

int    sed(char *filename, std::string s1, std::string s2)
{
    std::string data;
    (void)s1;
    (void)s2;
    if (openFile(filename, data) == 1)
        return 1;
    std::cout << data << std::endl;
    return (0);
}

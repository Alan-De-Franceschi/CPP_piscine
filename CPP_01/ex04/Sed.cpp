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
    std::string buf((std::istreambuf_iterator<char>(file)),
                    (std::istreambuf_iterator<char>()));
    data = buf;
    file.close();
    return (0);
}

static int  replace(char *filename, std::string &data, std::string s1, std::string s2)
{
    std::string newFileName = filename;
    newFileName += ".replace";
    std::ofstream newFile(&newFileName[0], std::ios::trunc);
    if (!newFile.is_open())
    {
        std::cout
            << "failed to open: "
            << newFileName
            << std::endl;
        return (1);
    }
    size_t pos = 0;
    while (s1 != "" && (pos = data.find(s1, pos)) != data.npos)
    {
        data.erase(pos, s1.length());
        data.insert(pos, s2);
        pos += s2.length();
    }
    newFile << data;
    newFile.close();
    return (0);
}

int    sed(char *filename, std::string s1, std::string s2)
{
    std::string data;
    if (openFile(filename, data) == 1)
        return 1;
   if (replace(filename, data, s1, s2) == 1)
       return (1);
    return (0);
}

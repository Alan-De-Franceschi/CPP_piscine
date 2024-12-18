#include "File.hpp"

File::File(const char *filename) : _status(0)
{
    char    c;

    std::ifstream   temp(filename, std::ios::binary);
    if (!temp.is_open())
    {
        std::cout
            << "failed to open: "
            << filename
            << std::endl;
        this->_status = 1;
        return ;
    }
    this->_file.open("outfile", std::ios::binary);
    if (!this->_file.is_open())
    {
        std::cout
            << "failed to open: "
            << "outfile"
            << std::endl;
        this->_status = 1;
        temp.close();
        return ;
    }
    while (temp.get(c))
        this->_file.put(c);
    temp.close();
    return ;
}

File::~File(void)
{
    this->_file.close();
    return ;
}

int File::getStatus(void) const
{
    return (this->_status);
}

void    File::replace(std::string s1, std::string s2)
{
    return ;
}

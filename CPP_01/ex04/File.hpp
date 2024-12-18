#ifndef FILE_H
# define FILE_H

# include <iostream>
# include <string>
# include <fstream>

class	File
{
    public:

        File(const char *filename);
        ~File(void);

		int		getStatus(void) const;
		void    replace(std::string s1, std::string s2);

    private:

        std::ofstream	_file;
        int				_status;

};

#endif
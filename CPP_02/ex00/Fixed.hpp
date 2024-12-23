#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
    public:

        Fixed(void);
        ~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

    private:
	
        int                 _rawBits;
        int const static    _nBits;
};


#endif
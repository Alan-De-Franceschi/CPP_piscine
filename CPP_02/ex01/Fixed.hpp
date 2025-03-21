#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
    public:

        Fixed(void);
        Fixed(Fixed const & src);
        Fixed(int const src);
        Fixed(float const src);
        ~Fixed(void);

        Fixed & operator=(Fixed const & rhs);

        float   toFloat(void) const;
        int     toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

    private:
	
        int                 _rawBits;
        static int const    _nBits;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define GREEN 	"\033[0;32m"
# define END	"\033[0m"

class Fixed
{
    public:

        Fixed(void);
        Fixed(Fixed const & src);
        Fixed(int const src);
        Fixed(float const src);
        ~Fixed(void);

        Fixed &         operator=(Fixed const & rhs);
        Fixed           operator+(Fixed const & rhs);
        Fixed           operator-(Fixed const & rhs);
        Fixed           operator*(Fixed const & rhs);
        Fixed           operator/(Fixed const & rhs);
        bool            operator>(Fixed const & rhs);
        bool            operator>=(Fixed const & rhs);
        bool            operator<(Fixed const & rhs);
        bool            operator<=(Fixed const & rhs);
        bool            operator==(Fixed const & rhs);
        bool            operator!=(Fixed const & rhs);
        Fixed &         operator++();
        Fixed           operator++(int);
        Fixed &         operator--();
        Fixed           operator--(int);

        static Fixed &  min(Fixed & x, Fixed & y);
        static Fixed &  min(Fixed const & x, Fixed const & y);
        float           toFloat(void) const;
        int             toInt(void) const;
		int             getRawBits(void) const;
		void            setRawBits(int const raw);

    private:
	
        int                 _rawBits;
        static int const    _nBits;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif
#include "Fixed.hpp"

int main(void) 
{
	Fixed a(2.5f);
	Fixed b(3.6f);
	Fixed d(2.5f);
	Fixed e(2.5f);

	std::cout
		<<std::endl
		<< GREEN
		<< "===== TEST OPERATOR + ====="
		<< END
		<< std::endl 
		<< std::endl;

	Fixed c = a + b;
	std::cout
		<< "c = a("
		<< a
		<< ") + b("
		<< b
		<< ") = "
		<< c
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR - ====="
		<< END 
		<< std::endl 
		<< std::endl;

	c = a - b;
	std::cout
		<< "c = a("
		<< a
		<< ") - b("
		<< b
		<< ") = "
		<< c
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR * =====" 
		<< END
		<< std::endl 
		<< std::endl;

	c = a * b;
	std::cout
		<< "c = a("
		<< a
		<< ") * b("
		<< b
		<< ") = "
		<< c
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR / =====" 
		<< END
		<< std::endl 
		<< std::endl;

	c = a / b;
	std::cout
		<< "c = a("
		<< a
		<< ") / b("
		<< b
		<< ") = "
		<< c
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR > ====="
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a("
		<< a
		<< ") > b("
		<< b
		<< ") = "
		<< (a > b)
		<< std::endl
		<< std::endl;

	std::cout
		<< "b("
		<< b
		<< ") > a("
		<< a
		<< ") = "
		<< (b > a)
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR >= =====" 
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a("
		<< a
		<< ") >= b("
		<< b
		<< ") = "
		<< (a >= b)
		<< std::endl
		<< std::endl;

	std::cout
		<< "b("
		<< b
		<< ") >= a("
		<< a
		<< ") = "
		<< (b >= a)
		<< std::endl
		<< std::endl;

	std::cout
		<< "d("
		<< d
		<< ") >= e("
		<< e
		<< ") = "
		<< (d >= e)
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR < ====="
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a("
		<< a
		<< ") < b("
		<< b
		<< ") = "
		<< (a < b)
		<< std::endl
		<< std::endl;

	std::cout
		<< "b("
		<< b
		<< ") < a("
		<< a
		<< ") = "
		<< (b < a)
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR <= =====" 
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a("
		<< a
		<< ") <= b("
		<< b
		<< ") = "
		<< (a <= b)
		<< std::endl
		<< std::endl;

	std::cout
		<< "b("
		<< b
		<< ") <= a("
		<< a
		<< ") = "
		<< (b <= a)
		<< std::endl
		<< std::endl;

	std::cout
		<< "d("
		<< d
		<< ") <= e("
		<< e
		<< ") = "
		<< (d <= e)
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR == ====="
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a("
		<< a
		<< ") == b("
		<< b
		<< ") = "
		<< (a == b)
		<< std::endl
		<< std::endl;

	std::cout
		<< "d("
		<< d
		<< ") == e("
		<< e
		<< ") = "
		<< (d == e)
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR != ====="
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a("
		<< a
		<< ") != b("
		<< b
		<< ") = "
		<< (a != b)
		<< std::endl
		<< std::endl;

	std::cout
		<< "d("
		<< d
		<< ") != e("
		<< e
		<< ") = "
		<< (d != e)
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR ++x et x++ ====="
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a = "
		<< a
		<< std::endl
		<< "++a = "
		<< ++a
		<< std::endl
		<< "a++ = "
		<< a++
		<<std::endl
		<< "a = "
		<< a
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST OPERATOR --x et x-- ====="
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a = "
		<< a
		<< std::endl
		<< "--a = "
		<< --a
		<< std::endl
		<< "a-- = "
		<< a--
		<<std::endl
		<< "a = "
		<< a
		<< std::endl
		<< std::endl;

	std::cout
		<< GREEN
		<< "===== TEST Min Fixed/Fixed ====="
		<< END
		<< std::endl 
		<< std::endl;

	std::cout
		<< "a = "
		<< a
		<< std::endl
		<< "b = "
		<< b
		<< std::endl
		<< "min(a, b) = "
		<< Fixed::min(a, b)
		<< std::endl
		<< std::endl;

	return (0);
}
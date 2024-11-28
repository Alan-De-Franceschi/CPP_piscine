#include <iostream>
#include <string>

void	ft_transform(std::string & str)
{
	for (size_t i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

int	main(int ac, char **av)
{
	std::string buf;
	int			i = 1;

	if (ac > 1)
	{
		while (av[i])
		{
			std::string str = av[i];
			ft_transform(str);
			buf += str;
			++i;
		}
	}
	else
		buf = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << buf << std::endl;
}

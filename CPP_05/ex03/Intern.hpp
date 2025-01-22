#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

# define PURPLE	"\033[0;35m"
# define END	"\033[0m"

class   Intern
{
    public :

        Intern(void);
        Intern(const Intern & src);
        ~Intern(void);

        Intern &    operator=(const Intern & rhs);

        AForm*      makeForm(std::string form, std::string target);

    private:


};


#endif
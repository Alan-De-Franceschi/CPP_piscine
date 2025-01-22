#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include <cstdlib>
#include <ctime>
# include "AForm.hpp"

class   RobotomyRequestForm : public AForm
{
    public:

        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &   operator=(RobotomyRequestForm & rhs);

        void                    execute(const Bureaucrat & executor) const;

    private:

        std::string             _target;
};

#endif
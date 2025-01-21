#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

# include "AForm.hpp"

class   Bureaucrat;

class   RobotomyRequestForm : public AForm
{
    public:

        RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm & operator=(RobotomyRequestForm & rhs);

        void    beExecuted(const Bureaucrat & brc) const;

    private:


};

#endif
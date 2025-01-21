#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

# include "AForm.hpp"

class   Bureaucrat;

class   ShrubberyCreationForm : public AForm
{
    public:

        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm & operator=(ShrubberyCreationForm & rhs);

        void    beExecuted(const Bureaucrat & brc) const;

    private:


};

#endif
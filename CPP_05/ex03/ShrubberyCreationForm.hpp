#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

# include "AForm.hpp"

class   ShrubberyCreationForm : public AForm
{
    public:

        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm & operator=(ShrubberyCreationForm & rhs);

        void                    execute(const Bureaucrat & executor) const;

    private:

        std::string             _target;
};

#endif
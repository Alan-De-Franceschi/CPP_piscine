#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

# include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm &    operator=(PresidentialPardonForm & rhs);

        void                        execute(const Bureaucrat & executor) const;

    private:

        std::string                 _target;
};

#endif
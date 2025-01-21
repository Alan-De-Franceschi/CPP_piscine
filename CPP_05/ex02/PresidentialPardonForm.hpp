#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

# include "AForm.hpp"

class   Bureaucrat;

class   PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm & operator=(PresidentialPardonForm & rhs);

        void    beExecuted(const Bureaucrat & brc) const;

    private:


};

#endif
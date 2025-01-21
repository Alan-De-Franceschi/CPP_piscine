#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.cpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src)
{
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm & rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    PresidentialPardonForm::beExecuted(const Bureaucrat & brc) const
{
    if (brc.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    
    return ;
}
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.cpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src)
{
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm & rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    ShrubberyCreationForm::beExecuted(const Bureaucrat & brc) const
{
    if (brc.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    
    return ;
}
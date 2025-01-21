#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.cpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src)
{
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm & rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    RobotomyRequestForm::beExecuted(const Bureaucrat & brc) const
{
    if (brc.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    
    return ;
}
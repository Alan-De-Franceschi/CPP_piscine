#include "PresidentialPardonForm.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("Undefined")
{
    std::cout
        << BLUE
        << this->getName()
        << ": Constructor Called"
        << END
        << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src)
{
    this->_target = src._target;
    std::cout
        << BLUE
        << this->getName()
        << ": Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout
        << BLUE
        << this->getName()
        << ": Constructor Called"
        << END
        << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout
        << BLUE
        << this->getName()
        << ": Destructor Called"
        << END
        << std::endl;
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm & rhs)
{
    AForm::operator=(rhs);
    this->_target = rhs._target;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
    if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout
            << "Bureaucrat "
            << executor.getName()
            << " execute "
            << this->getName()
            << " form"
            << std::endl;
    std::cout
        << this->_target
        << " has been pardoned by Zaphod Beeblebrox"
        << std::endl;
    return ;
}
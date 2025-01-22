#include "RobotomyRequestForm.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Undefined")
{
    std::cout
        << BLUE
        << this->getName()
        << ": Constructor Called"
        << END
        << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src)
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

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout
        << BLUE
        << this->getName()
        << ": Constructor Called"
        << END
        << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
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

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm & rhs)
{
    AForm::operator=(rhs);
    this->_target = rhs._target;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    RobotomyRequestForm::execute(const Bureaucrat & executor) const
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
    static bool randomEngine = false;
    if (!randomEngine)
    {
        std::srand(std::time(NULL));
        randomEngine = true;
    }
    if ((std::rand() % 2) == 0)
    {
        std::cout
            << "DRIIIIILL -> "
            << this->_target
            << " has been robotomized successfully!"
            << std::endl;
    }
    else
    {
        std::cout
            << "DRILL ERROR -> the robotomy failed"
            << std::endl;
    }
    return ;
}
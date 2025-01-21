#include "Bureaucrat.hpp"
#include "AForm.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Bureaucrat::Bureaucrat(void)
{
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src)
{
    *this = src;
    std::cout
        << YELLOW
        << this->_name
        << ": Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout
        << YELLOW
        << this->_name
        << ": Constructor Called"
        << END
        << std::endl;
    try
    {
        checkGrade(grade);
    }
    catch (GradeTooLowException & e)
    {
        std::cerr
            << RED
            << this->_name
            << " "
            << e.what()
            << END
            << std::endl;
        throw std::invalid_argument("grade");
    }
    catch (GradeTooHighException & e)
    {
        std::cerr
            << RED
            << this->_name
            << " "
            << e.what()
            << END
            << std::endl;
        throw std::invalid_argument("grade");
    }
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout
        << YELLOW
        << this->_name
        << ": Destructor Called"
        << END
        << std::endl;
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Bureaucrat &    Bureaucrat::operator=(const Bureaucrat & rhs)
{
    const_cast<std::string &>(this->_name) = rhs._name;
    this->_grade = rhs._grade;
    return (*this);
}

std::ostream &  operator<<(std::ostream & out, Bureaucrat const & rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (out);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

const std::string & Bureaucrat::getName(void) const
{
    return (this->_name);
}

int    Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    Bureaucrat::checkGrade(int grade) 
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1 )
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
    return ;
}

void    Bureaucrat::upGrade(void)
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
    return ;
}

void    Bureaucrat::downGrade(void)
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
    return ;
}

void    Bureaucrat::signForm(AForm & form)
{
    try
    {
        form.beSigned(*this);
        std::cout
            << "Bureaucrat "
            << this->_name
            << " signed "
            << form.getName()
            << " form"
            <<std::endl;
    }
    catch (AForm::GradeTooLowException & e)
    {
        std::cerr
            << RED        
            << "Bureaucrat "
            << this->_name
            << " couldn’t sign "
            << form.getName()
            << " form because Sign-Grade " 
            << e.what()
            << END
            << std::endl;
        throw std::invalid_argument("grade");
    }
    return ;
}

void    Bureaucrat::executeForm(const AForm & form)
{
    try
    {
        form.beExecuted(*this);
        std::cout
            << "Bureaucrat "
            << this->_name
            << " execute "
            << form.getName()
            << " form"
            << std::endl;
    }
    catch (AForm::GradeTooLowException & e)
    {
        std::cerr
            << RED        
            << "Bureaucrat "
            << this->_name
            << " couldn’t execute "
            << form.getName()
            << " form because Exec-Grade " 
            << e.what()
            << END
            << std::endl;
        throw std::invalid_argument("grade");
    }
    catch (AForm::FormNotSigned & e)
    {
        std::cerr
            << RED        
            << "Bureaucrat "
            << this->_name
            << " couldn’t execute "
            << form.getName()
            << " form because "
            << e.what()
            << END
            << std::endl;
        throw std::invalid_argument("signed");
    }
}

/****************************************************************************/
/*                               Exceptions                                 */
/****************************************************************************/

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Error: grade too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return ("Error: grade too high");
}

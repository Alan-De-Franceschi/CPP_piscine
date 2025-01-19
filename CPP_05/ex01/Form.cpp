#include "Form.hpp"
#include "Bureaucrat.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Form::Form(void) : _signGrade(0), _execGrade(0)
{
    return ;
}

Form::Form(const Form & src) : _signGrade(0), _execGrade(0)
{
    *this = src;
    std::cout
        << BLUE
        << this->_name
        << ": Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

Form::Form(std::string name, int sigGrade, int exeGrade) : _name(name), _signed(false), _signGrade(sigGrade), _execGrade(exeGrade)
{
    std::cout
        << BLUE
        << this->_name
        << ": Constructor Called"
        << END
        << std::endl;
    try
    {
        checkGrades();
    }
    catch(const Form::GradeTooHighException & e)
    {
        if (this->_signGrade < 1)
            std::cout << RED << "_signGrade, " << END;
        if (this->_execGrade < 1)
            std::cout << RED << "_execGrade, " << END;
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
        throw std::invalid_argument("grade");
    }
    catch(const Form::GradeTooLowException & e)
    {
        if (this->_signGrade > 150)
            std::cout << RED << "_signGrade, " << END;
        if (this->_execGrade > 150)
            std::cout << RED << "_execGrade, " << END;
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
        throw std::invalid_argument("grade");
    }
    return ;
}

Form::~Form(void)
{
    std::cout
        << BLUE
        << this->_name
        << ": Destructor Called"
        << END
        << std::endl;
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Form &  Form::operator=(const Form & rhs)
{
    const_cast<std::string &>(this->_name) = rhs._name;
    this->_signed = rhs._signed;
    const_cast<int &>(this->_signGrade) = rhs._signGrade;
    const_cast<int &>(this->_execGrade) = rhs._execGrade;
    return (*this);
}

std::ostream &  operator<<(std::ostream & outstream, const Form & rhs)
{
    outstream
        << "Form: " << rhs.getName()
        << ", Signed: " << rhs.getSigned()
        << ", Sign_Grade: " << rhs.getSignGrade()
        << ", Exec_Grade: " << rhs.getExexGrade();
    return (outstream);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

const std::string & Form::getName(void) const
{
    return (this->_name);
}

bool  Form::getSigned(void) const
{
    return (this->_signed);
}

const int & Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

const int & Form::getExexGrade(void) const
{
    return (this->_execGrade);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    Form::checkGrades(void) const
{
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw Form::GradeTooHighException();
    else if (this->_signGrade > 150 || this->_execGrade > 150)
        throw Form::GradeTooLowException();
    return ;
}

void    Form::beSigned(const Bureaucrat & brc)
{
    if (brc.getGrade() >  this->_signGrade)
        throw Form::GradeTooLowException();
    this->_signed = true;
    return ;
}

/****************************************************************************/
/*                               Exceptions                                 */
/****************************************************************************/

const char *Form::GradeTooLowException::what() const throw() 
{
    return ("Error: grade too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Error: grade too high");
}
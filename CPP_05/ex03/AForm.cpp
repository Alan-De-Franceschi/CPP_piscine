#include "AForm.hpp"
#include "Bureaucrat.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

AForm::AForm(void) : _signGrade(0), _execGrade(0)
{
    return ;
}

AForm::AForm(const AForm & src) : _signGrade(0), _execGrade(0)
{
    *this = src;
    std::cout
        << BLUE
        << "AForm: Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

AForm::AForm(std::string name, int sigGrade, int exeGrade) : _name(name), _signed(false), _signGrade(sigGrade), _execGrade(exeGrade)
{
    std::cout
        << BLUE
        << "AForm: Constructor Called"
        << END
        << std::endl;
    try
    {
        checkGrades();
    }
    catch(const AForm::GradeTooHighException & e)
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
    catch(const AForm::GradeTooLowException & e)
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

AForm::~AForm(void)
{
    std::cout
        << BLUE
        << "AForm: Destructor Called"
        << END
        << std::endl;
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

AForm &  AForm::operator=(const AForm & rhs)
{
    const_cast<std::string &>(this->_name) = rhs._name;
    this->_signed = rhs._signed;
    const_cast<int &>(this->_signGrade) = rhs._signGrade;
    const_cast<int &>(this->_execGrade) = rhs._execGrade;
    return (*this);
}

std::ostream &  operator<<(std::ostream & outstream, const AForm & rhs)
{
    outstream
        << "AForm: " << rhs.getName()
        << ", Signed: " << rhs.getSigned()
        << ", Sign_Grade: " << rhs.getSignGrade()
        << ", Exec_Grade: " << rhs.getExecGrade();
    return (outstream);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

const std::string & AForm::getName(void) const
{
    return (this->_name);
}

bool  AForm::getSigned(void) const
{
    return (this->_signed);
}

const int & AForm::getSignGrade(void) const
{
    return (this->_signGrade);
}

const int & AForm::getExecGrade(void) const
{
    return (this->_execGrade);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    AForm::checkGrades(void) const
{
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (this->_signGrade > 150 || this->_execGrade > 150)
        throw AForm::GradeTooLowException();
    return ;
}

void    AForm::beSigned(const Bureaucrat & brc)
{
    if (brc.getGrade() >  this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_signed = true;
    return ;
}

/****************************************************************************/
/*                               Exceptions                                 */
/****************************************************************************/

const char *AForm::GradeTooLowException::what() const throw() 
{
    return ("Error: grade too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Error: grade too high");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("Error: form is not signed, it can't be execute");
}
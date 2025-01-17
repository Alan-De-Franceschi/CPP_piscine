#include "Form.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Form::Form(void) : _signGrade(0), _execGrade(0)
{
    return ;
}

Form::Form(const Form & src): Form()
{
    *this = src;
    return ;
}

Form::Form(std::string name, int sigGrade, int exeGrade) : _name(name), _signed(false), _signGrade(sigGrade), _execGrade(exeGrade)
{
    try
    {
        checkGrades();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return ;
}

Form::~Form(void)
{
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

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    Form::checkGrades(void)
{
    
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
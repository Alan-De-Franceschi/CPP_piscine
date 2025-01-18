#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

class   Bureaucrat;

class   Form
{
    public:
    
        Form(const Form & src);
        Form(std::string name, int sigGrade, int exeGrade);
        ~Form(void);

        Form &              operator=(const Form & rhs);

        const std::string & getName(void) const;
        bool                getSigned(void) const;
        const int &         getSignGrade(void) const;
        const int &         getExexGrade(void) const;
        void                beSigned(const Bureaucrat & brc);

        class   GradeTooLowException : public std::exception
        {
            public:

                virtual const char *what() const throw();
        };
        class   GradeTooHighException :  public std::exception
        {
            public:

                virtual const char *what() const throw();
        };

    private:

        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;

        Form(void);
        
        void                checkGrades(void) const;

};

std::ostream &  operator<<(std::ostream & outstream, const Form & rhs);

#endif
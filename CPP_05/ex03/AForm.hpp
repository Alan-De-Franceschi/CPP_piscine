#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "Bureaucrat.hpp"

# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

class   AForm
{
    public:
    
        AForm(const AForm & src);
        AForm(std::string name, int sigGrade, int exeGrade);
        virtual ~AForm(void);

        AForm &             operator=(const AForm & rhs);

        const std::string & getName(void) const;
        bool                getSigned(void) const;
        const int &         getSignGrade(void) const;
        const int &         getExecGrade(void) const;
        void                beSigned(const Bureaucrat & brc);
        virtual void        execute(const Bureaucrat & executor) const = 0;

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
        class   FormNotSigned :  public std::exception
        {
            public:

                virtual const char *what() const throw();
        };

    private:

        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;

        AForm(void);
        
        void                checkGrades(void) const;

};

std::ostream &  operator<<(std::ostream & outstream, const AForm & rhs);

#endif
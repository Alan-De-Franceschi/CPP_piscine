#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class   Form
{
    public:
    
        Form(const Form & src);
        Form(std::string name, int sigGrade, int exeGrade);
        ~Form(void);

        Form &  operator=(const Form & rhs);

        class   GradeTooLowException : public std::exception
        {
            public:

                virtual const char *what() const throw();
        };
        class GradeTooHighException :  public std::exception
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
        
        void    checkGrades(void);

};

#endif
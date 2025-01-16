#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class   Bureaucrat
{
    public:

        Bureaucrat(const Bureaucrat & src);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat(void);

        Bureaucrat &    operator=(const Bureaucrat & rhs);

        void checkGrade(int grade);
        class GradeTooLowException :  public std::exception
        {
            public:

                virtual const char* what() const throw();
        };
        class GradeTooHighException :  public std::exception
        {
            public:

                virtual const char* what() const throw();
        };

    private:

        const std::string   _name;
        unsigned int        _grade;

        Bureaucrat(void);

};

#endif
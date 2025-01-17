#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define GREEN 	"\033[0;32m"
# define END	"\033[0m"

class   Bureaucrat
{
    public:

        Bureaucrat(const Bureaucrat & src);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat(void);

        Bureaucrat &        operator=(const Bureaucrat & rhs);

        const std::string & getName(void) const;
        int                 getGrade(void) const;
        void                upGrade(void);
        void                downGrade(void);

        class GradeTooLowException :  public std::exception
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
        int                 _grade;

        Bureaucrat(void);
        void    checkGrade(int grade);

};

std::ostream &  operator<<(std::ostream & out, Bureaucrat const & rhs);

#endif
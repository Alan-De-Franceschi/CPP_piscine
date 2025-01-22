#include "Intern.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Intern::Intern(void)
{
    std::cout
        << PURPLE
        << "Intern: Constructor Called"
        << END
        << std::endl;
    return ;
}

Intern::Intern(const Intern & src)
{
    (void)src;
    std::cout
        << PURPLE
        << "Intern: Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

Intern::~Intern(void)
{
    std::cout
        << PURPLE
        << "Intern: Destructor Called"
        << END
        << std::endl;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Intern &    Intern::operator=(const Intern & rhs)
{
    (void)rhs;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

static AForm*   newShrubbery(std::string & target)
{
    AForm*  newForm = new ShrubberyCreationForm(target);
    return (newForm);
}

static AForm*   newPresident(std::string & target)
{
    AForm*  newForm = new PresidentialPardonForm(target);
    return (newForm);
}

static AForm*   newRobotomy(std::string & target)
{
    AForm*  newForm = new RobotomyRequestForm(target);
    return (newForm);
}

static AForm*   wrongForm(std::string & target)
{
    (void)target;
    throw std::invalid_argument("This request");
    return (NULL);
}

AForm*  Intern::makeForm(std::string form, std::string target)
{
    try
    {
        AForm*      newForm;
        std::string forms[4] = {"shrubbery request", "presidential request", "robotomy request", form};
        AForm*      (*func[4])(std::string & target) = {&newShrubbery, &newPresident, &newRobotomy, &wrongForm};
        int         index = 0;

        for (int i = 0; i < 4; i++)
        {
            if (form == forms[i])
                break ;
            index++;
        }
        newForm = func[index](target);
        return (newForm);
    }
    catch(const std::invalid_argument & e)
    {
        std::cerr
            << RED
            << e.what() 
            << " is not a valid form"
            << END
            << std::endl;
        throw std::invalid_argument(target);
    }
    catch(const std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << std::endl;
        throw std::exception();
    }
}
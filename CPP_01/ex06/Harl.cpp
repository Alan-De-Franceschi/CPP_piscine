#include "Harl.hpp"

Harl::Harl(void)
{
    return ;
}

Harl::~Harl(void)
{
    return ;
}

void    Harl::debug(void)
{
    std::cout
        << "[ DEBUG ]"
        << std::endl
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
        << std::endl
        << "I really do!"
        << std::endl;
        return ;
}

void    Harl::info(void)
{
    std::cout
        << "[ INFO ]"
        << std::endl
        << "I cannot believe adding extra bacon costs more money."
        << std::endl
        << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
        return ;
}

void    Harl::warning(void)
{
    std::cout
        << "[ WARNING ]"
        << std::endl
        << "I think I deserve to have some extra bacon for free."
        << std::endl
        << "I’ve been coming for years whereas you started working here since last month."
        << std::endl;
        return ;
}

void    Harl::error(void)
{
    std::cout
        << "[ ERROR ]"
        << std::endl
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
        return ;
}

void    Harl::blabla(void)
{
    std::cout
        << "[ Probably complaining about insignificant problems ]"
        << std::endl;
        return ;
}

void    Harl::printComplain(void (Harl::*f[4])(void), int index)
{
    for (int i = index; i < 4; i++)
    {
        (this->*f[i])();
        std::cout << std::endl;
    }
    return ;
}

void    Harl::complain(std::string level)
{
    std::string levelTab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (level == levelTab[i])
        {
            index = i;
            break;
        }
    }
    void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    switch (index)
    {
        case 0:
            this->printComplain(f, 0);
            break ;
        case 1:
            this->printComplain(f, 1);
            break ;
        case 2:
            this->printComplain(f, 2);
            break ;
        case 3:
            this->printComplain(f, 3);
            break ;
        default:
            this->blabla();
            break ;
    }
    return ;
}
/*
** CECS 275 - 2023
** LAB 5
** FILE DESCRIPTION:
** main
** MADE BY:
** Nathan Bellanger
*/

#include "InvalidDateException.hpp"
#include "months.h"
#include "Date.hpp"
#include <iostream>

int main(void)
{
    try {
        Date defaultDate;
        Date deadlineLab5(APRIL, 23, 2023);
        std::cout << "Example 1: " << defaultDate << "\n" <<
        "Example 2: " << deadlineLab5 << "\n" << std::endl;

        std::list<Date> list = Date::listAllDates(2023);
        std::cout << "listAllDates of 2023:" << std::endl;
        for (Date &elem : list) {
            std::cout << elem << std::endl;
        }
        Date wrongDate(13, 80, 0);
    }
    catch (const InvalidDateException *e) {
        std::cout << "[ERROR]: " << e->what() << std::endl;
        return 1;
    }
    return 0;
}
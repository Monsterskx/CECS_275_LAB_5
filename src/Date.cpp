/*
** CECS 275 - 2023
** LAB 5
** FILE DESCRIPTION:
** Date class implementation
** MADE BY:
** Nathan Bellanger
*/

#include "months.h"
#include "InvalidDateException.hpp"
#include "Date.hpp"
#include <string>

Date::Date() : month(1), day(1), year(1)
{
}

Date::Date(int month, int day, int year) : month(month), day(day), year(year)
{
    if (month > 12) {
        throw new InvalidDateException(ERROR_MSG("Invalid month input"));
    }

    if (day < 1 || day > getDaysInMonth()) {
        throw new InvalidDateException(ERROR_MSG("Invalid day input"));
    }
}

Date::~Date()
{
}

std::list<Date> Date::listAllDates(int year)
{
    std::list<Date> dates;
    for (int month = JANUARY; month <= DECEMBER; ++month) {
        int maxDay = 31;
        if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER) {
            maxDay = 30;
        } else if (month == FEBRUARY) {
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                maxDay = 29;
            } else {
                maxDay = 28;
            }
        }
        for (int day = 1; day <= maxDay; ++day) {
            try {
                Date d(month, day, year);
                dates.push_back(d);
            } catch (const std::exception& e) {
                e.what();
            }
        }
    }
    return dates;
}

std::string Date::toString(const std::string& format) const {
    std::stringstream ss;
    int day = getDay();
    int month = static_cast<int>(getMonth());
    int year = getYear();

    if (format == "yyyy-mm-dd") {
        ss << std::setfill('0') << std::setw(4) << year << "-";
        ss << std::setfill('0') << std::setw(2) << month << "-";
        ss << std::setfill('0') << std::setw(2) << day;
    } else if (format == "dd-mm-yyyy") {
        ss << std::setfill('0') << std::setw(2) << day << "-";
        ss << std::setfill('0') << std::setw(2) << month << "-";
        ss << std::setfill('0') << std::setw(4) << year;
    } else if (format == "mm-dd-yyyy") {
        ss << std::setfill('0') << std::setw(2) << month << "-";
        ss << std::setfill('0') << std::setw(2) << day << "-";
        ss << std::setfill('0') << std::setw(4) << year;
    } else {
        throw std::invalid_argument("Invalid format");
    }

    return ss.str();
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
    std::string monthName;
    switch (date.month) {
        case JANUARY:
            monthName = "January";
            break;
        case FEBRUARY:
            monthName = "February";
            break;
        case MARCH:
            monthName = "March";
            break;
        case APRIL:
            monthName = "April";
            break;
        case MAY:
            monthName = "May";
            break;
        case JUNE:
            monthName = "June";
            break;
        case JULY:
            monthName = "July";
            break;
        case AUGUST:
            monthName = "August";
            break;
        case SEPTEMBER:
            monthName = "September";
            break;
        case OCTOBER:
            monthName = "October";
            break;
        case NOVEMBER:
            monthName = "November";
            break;
        case DECEMBER:
            monthName = "December";
            break;
        default:
            monthName = "Invalid";
            break;
    }

    os << monthName << " " << date.day << ", " << date.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    is >> date.month;
    is.ignore();
    is >> date.day;
    is.ignore();
    is >> date.year;
    return is;
}

Date& Date::operator++()
{
    day++;
    if (day > getDaysInMonth()) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    Date tmp(*this);
    operator++();
    return tmp;
}

Date& Date::operator--()
{
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = getDaysInMonth();
    }
    return *this;
}

Date Date::operator--(int)
{
    Date tmp(*this);
    operator--();
    return tmp;
}

Date Date::operator+(int days) const
{
    Date result(*this);
    while (days > 0) {
        int daysInMonth = result.getDaysInMonth();
        int remainingDays = daysInMonth - result.day + 1;

        if (days > remainingDays) {
            result.month++;
            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
            result.day = 1;
            days -= remainingDays;
        } else {
            result.day += days;
            if (result.day > daysInMonth) {
                result.month++;
                if (result.month > 12) {
                    result.month = 1;
                    result.year++;
                }
                result.day = 1;
            }
            days = 0;
        }
    }
    return result;
}

Date Date::operator-(int days) const
{
    Date result(*this);
    while (days > 0) {
        int remainingDays = result.day - 1;

        if (days > remainingDays) {
            result.month--;
            if (result.month < 1) {
                result.month = 12;
                result.year--;
            }
            result.day = result.getDaysInMonth();
            days -= remainingDays;
        } else {
            result.day -= days;
            if (result.day < 1) {
                result.month--;
                if (result.month < 1) {
                    result.month = 12;
                    result.year--;
                }
                result.day = result.getDaysInMonth();
            }
            days = 0;
        }
    }
    return result;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    if (month < JANUARY || month > DECEMBER) {
        throw new InvalidDateException(ERROR_MSG("Invalid month input"));
    }
    month = month;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    if (day < 1 || day > getDaysInMonth()) {
        throw new InvalidDateException(ERROR_MSG("Invalid day input"));
    }
    day = day;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    if (year < 0) {
        throw new InvalidDateException(ERROR_MSG("Invalid year input"));
    }
    year = year;
}

int Date::getDaysInMonth() const
{
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}
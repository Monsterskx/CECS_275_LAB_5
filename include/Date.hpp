/*
** CECS 275 - 2023
** LAB 5
** FILE DESCRIPTION:
** Date class declaration
** MADE BY:
** Nathan Bellanger
*/

#include <list>
#include <string>
#include <sstream>
#include <iomanip>

class Date
{
    public:
        /* Default contructor
        */ Date();
        // -------

        /* Overloaded Constructor
        ** Allow to create Date obj with inputs
        */ Date(int month, int day, int year);
        // -----------------------------------

        /* Destrcutor
        */ ~Date();
        // --------

        /* return a list of all dates for the year given as input
        */ static std::list<Date> listAllDates(int year);
        // ----------------------------------------------

        /* overload operator for <<
        */ friend std::ostream& operator<<(std::ostream& os, const Date& date);
        // --------------------------------------------------------------------

        /* overload operator for >>
        */ friend std::istream& operator>>(std::istream& is, Date& date);
        // --------------------------------------------------------------

        /* overload operator for ++
        ** increment day by day
        */ Date& operator++();
        // -------------------

        /* overload operator for ++
        ** increment day by day
        */ Date operator++(int);
        // ---------------------

        /* overload operator for --
        ** decrement day by day
        */ Date& operator--();
        // -------------------

        /* overload operator for --
        ** decrement day by day
        */ Date operator--(int);
        // ---------------------

        /* overload operator for +
        */ Date operator+(int days) const;
        // -------------------------------

        /* overload operator for -
        */ Date operator-(int days) const;
        // -------------------------------

        /* Getter method for month
        */ int getMonth() const;
        // ---------------------

        /* Setter method for month
        */ void setMonth(int month);
        // -------------------------

        /* Getter method for day
        */ int getDay() const;
        // -------------------

        /* Setter method for day
        */ void setDay(int day);
        // ---------------------

        /* Getter method for year
        */ int getYear() const;
        // --------------------

        /* Setter method for year
        */ void setYear(int year);
        // -----------------------

        /* toString function for class Date
        ** accept the following formats as input: yyyy-mm-dd, dd-mm-yyyy, and mm-dd-yyyy 
        */ std::string toString(const std::string& format) const;

    private:
        /* this method return the number of day in a month
        ** handle leap years
        */ int getDaysInMonth() const;
        // ---------------------------

    private:
        int month;
        int day;
        int year;
};
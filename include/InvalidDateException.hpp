/*
** CECS 275 - 2023
** LAB 5
** FILE DESCRIPTION:
** InvalidDateException class declaration
** MADE BY:
** Nathan Bellanger
*/

#include <exception>
#include <string>
#include <cstring>

#define ERROR_MSG(msg) msg, __FILE__, __LINE__

class InvalidDateException : public std::exception
{
    public:
        InvalidDateException(const std::string& message, const std::string& fileName, int lineNum) :
            message(message), fileName(fileName), lineNum(lineNum) {}

        virtual const char* what() const noexcept override {
            std::string errorMessage(message + " On File: " + getFileName() + " line: " + std::to_string(getLineNum()));
            char* errorMessagePtr = new char[errorMessage.size() + 1];
            std::strcpy(errorMessagePtr, errorMessage.c_str());
            return errorMessagePtr;
        }

        const std::string& getFileName() const noexcept {
            return fileName;
        }

        int getLineNum() const noexcept {
            return lineNum;
        }

    private:
        std::string message;
        std::string fileName;
        int lineNum;
};
/*
** EPITECH PROJECT, 2020
** Error
** File description:
** Error.hpp
*/

#include <string>

#ifndef ERROR_HPP_
#define ERROR_HPP_

class NanoError : public std::exception {
    public:
        NanoError(const std::string &message) noexcept;

        const char *what() const noexcept override;

    private:
        std::string _message;
};


#endif /* ERROR_HPP_ */

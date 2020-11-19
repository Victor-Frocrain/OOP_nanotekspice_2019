/*
** EPITECH PROJECT, 2020
** Error
** File description:
** Error.cpp
*/

#include "../include/Error.hpp"

NanoError::NanoError(const std::string &message) noexcept : _message(message)
{

}

const char *NanoError::what() const noexcept
{
    return _message.c_str();
}
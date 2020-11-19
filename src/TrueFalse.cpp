/*
** EPITECH PROJECT, 2020
** TrueFalse
** File description:
** TrueFalse.cpp
*/

#include "../include/TrueFalse.hpp"

namespace nts {

    True::True(const std::string &name) : Components()
    {
        _nbPuts = 1;
        _type = "true";
        _inPuts1.push_back(0);
        _inPuts2.push_back(0);
        _outPuts.push_back(1);
        _name = name;
        _pins.in1.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.in2.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.out.insert(std::pair<std::size_t, Tristate>(1, TRUE));
    }

    False::False(const std::string &name) : Components()
    {
        _nbPuts = 1;
        _type = "false";
        _inPuts1.push_back(0);
        _inPuts2.push_back(0);
        _outPuts.push_back(1);
        _name = name;
        _pins.in1.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.in2.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.out.insert(std::pair<std::size_t, Tristate>(1, FALSE));
    }

    True::~True()
    {

    }

    False::~False()
    {

    }

    Tristate True::compute(std::size_t pin)
    {
        Tristate state = TRUE;

        state = _pins.out[pin];
        return state;
    }

    Tristate False::compute(std::size_t pin)
    {
        Tristate state = FALSE;

        state = _pins.out[pin];
        return state;
    }
}
/*
** EPITECH PROJECT, 2020
** Clock
** File description:
** Clock.cpp
*/

#include "../include/Clock.hpp"

namespace nts {

    Clock::Clock(const std::string &name) : Components()
    {
        _nbPuts = 1;
        _type = "clock";
        _inPuts1.push_back(0);
        _inPuts2.push_back(0);
        _outPuts.push_back(1);
        _name = name;
        _pins.in1.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.in2.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.out.insert(std::pair<std::size_t, Tristate>(1, UNDEFINED));
    }

    Clock::~Clock()
    {

    }

    Tristate Clock::compute(std::size_t pin)
    {
        Tristate state = UNDEFINED;

        state = _pins.out[pin];
        return state;
    }

}
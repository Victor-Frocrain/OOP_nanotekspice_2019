/*
** EPITECH PROJECT, 2020
** Comp4001
** File description:
** Comp4001.cpp
*/

#include "../include/Comp4001.hpp"

namespace nts {

    Comp4001::Comp4001(const std::string &name) : Components()
    {
        _nbPuts = 4;
        _type = "4001";
        size_t in1[4] = { 1, 5, 8, 12 };
        size_t in2[4] = { 2, 6, 9, 13 };
        size_t out[4] = { 3, 4, 10, 11 };

        _name = name;
        for (size_t i = 0; i < _nbPuts; i++) {
            _inPuts1.push_back(in1[i]);
            _inPuts2.push_back(in2[i]);
            _outPuts.push_back(out[i]);
            _pins.in1.insert(_pins.in1.end(), std::pair<std::size_t, Tristate>(_inPuts1[i], UNDEFINED));
            _pins.in2.insert(_pins.in2.end(), std::pair<std::size_t, Tristate>(_inPuts2[i], UNDEFINED));
            _pins.out.insert(_pins.out.end(), std::pair<std::size_t, Tristate>(_outPuts[i], UNDEFINED));
        }
    }

    Comp4001::~Comp4001()
    {

    }

    Tristate Comp4001::compute(std::size_t pin)
    {
        Tristate state = UNDEFINED;
        Tristate pin1;
        Tristate pin2;

        pin1 = _pins.in1[_inPuts1[pin]];
        pin2 = _pins.in2[_inPuts2[pin]];
        if (pin1 == TRUE || pin2 == TRUE)
            state = FALSE;
        else if (pin1 == FALSE && pin2 == FALSE)
            state = TRUE;
        _pins.out[_outPuts[pin]] = state;
        return state;
    }
}
/*
** EPITECH PROJECT, 2020
** Comp4069
** File description:
** Comp4069.cpp
*/

#include "../include/Comp4069.hpp"

namespace nts {

    Comp4069::Comp4069(const std::string &name) : Components()
    {
        _nbPuts = 6;
        _type = "4069";
        size_t in1[6] = { 1, 3, 5, 9, 11, 13 };
        size_t in2[6] = { 0, 0, 0, 0, 0, 0};
        size_t out[6] = { 2, 4, 6, 8, 10, 12 };

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

    Comp4069::~Comp4069()
    {

    }

    Tristate Comp4069::compute(std::size_t pin)
    {
        Tristate state = UNDEFINED;
        Tristate pin1;

        pin1 = _pins.in1[_inPuts1[pin]];
        if (pin1 == FALSE)
            state = TRUE;
        else if (pin1 == TRUE)
            state = FALSE;
        _pins.out[_outPuts[pin]] = state;
        return state;
    }
}
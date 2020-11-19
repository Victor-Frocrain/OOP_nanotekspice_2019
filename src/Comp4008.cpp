/*
** EPITECH PROJECT, 2020
** Comp4008
** File description:
** Comp4008.cpp
*/

#include "../include/Comp4008.hpp"

namespace nts {

    Comp4008::Comp4008(const std::string &name) : Components()
    {
        _nbPuts = 4;
        _type = "4008";
        size_t in1[4] = { 6, 4, 2, 15 };
        size_t in2[4] = { 7, 5, 3, 1 };
        size_t out[4] = { 10, 11, 12, 13 };

        _name = name;
        _cin = { 9, UNDEFINED };
        _cout = { 14, UNDEFINED };
        for (size_t i = 0; i < _nbPuts; i++) {
            _inPuts1.push_back(in1[i]);
            _inPuts2.push_back(in2[i]);
            _outPuts.push_back(out[i]);
            _pins.in1.insert(_pins.in1.end(), std::pair<std::size_t, Tristate>(_inPuts1[i], UNDEFINED));
            _pins.in2.insert(_pins.in2.end(), std::pair<std::size_t, Tristate>(_inPuts2[i], UNDEFINED));
            _pins.out.insert(_pins.out.end(), std::pair<std::size_t, Tristate>(_outPuts[i], UNDEFINED));
            _pins.carry.insert(_pins.carry.end(), std::pair<std::size_t, Tristate>(0, UNDEFINED));
        }
    }

    Comp4008::~Comp4008()
    {

    }

    Tristate Comp4008::compute(std::size_t pin)
    {
        int in1 = UNDEFINED;
        int in2 = UNDEFINED;
        int in3 = _cin.second;
        int result = 0;

        for (size_t i = 0; i < _nbPuts; i++) {
            in1 = _pins.in1[_inPuts1[i]];
            in2 = _pins.in2[_inPuts2[i]];
            result = in1 + in2 + in3;
            switch (result)
            {
            case 3:
                in3 = TRUE;
                _pins.out[_outPuts[i]] = TRUE;
                break;
            case 2:
                in3 = TRUE;
                _pins.out[_outPuts[i]] = FALSE;
                break;
            case 1:
                in3 = FALSE;
                _pins.out[_outPuts[i]] = TRUE;
                break;
            case 0:
                in3 = FALSE;
                _pins.out[_outPuts[i]] = FALSE;
                break;
            default:
                break;
            }
        }
        if (in3 == 1)
            _cout.second = TRUE;
        else if (in3 == 0)
            _cout.second = FALSE;
        return _pins.out[_outPuts[pin]];
    }
}
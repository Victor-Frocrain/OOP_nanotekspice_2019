/*
** EPITECH PROJECT, 2020
** Puts
** File description:
** Puts.cpp
*/

#include "../include/Puts.hpp"

namespace nts {

    Input::Input(const std::string &name) : Components()
    {
        _nbPuts = 1;
        _type = "input";
        _inPuts1.push_back(0);
        _inPuts2.push_back(0);
        _outPuts.push_back(1);
        _name = name;
        _pins.in1.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.in2.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.out.insert(std::pair<std::size_t, Tristate>(1, UNDEFINED));
    }

    Output::Output(const std::string &name) : Components()
    {
        _nbPuts = 1;
        _type = "output";
        _inPuts1.push_back(1);
        _inPuts2.push_back(0);
        _outPuts.push_back(0);
        _name = name;
        _pins.in1.insert(std::pair<std::size_t, Tristate>(1, UNDEFINED));
        _pins.in2.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
        _pins.out.insert(std::pair<std::size_t, Tristate>(0, UNDEFINED));
    }

    Input::~Input()
    {

    }

    Output::~Output()
    {
    
    }

    Tristate Output::compute(std::size_t pin)
    {
        Tristate state = UNDEFINED;

        state = _pins.in1[pin];
        return state;
    }

    Tristate Input::compute(std::size_t pin)
    {
        Tristate state = UNDEFINED;

        state = _pins.out[pin];
        return state;
    }

}
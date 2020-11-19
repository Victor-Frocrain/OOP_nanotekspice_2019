/*
** EPITECH PROJECT, 2020
** Component
** File description:
** Component.cpp
*/

#include "../include/nanoTekSpice.hpp"
#include "../include/Tools.hpp"
#include "../include/Puts.hpp"
#include "../include/Comp4001.hpp"
#include <algorithm>

namespace nts {

    Components::Components() : IComponent()
    {

    }

    Pins::Pins()
    {

    }

    Components::~Components()
    {
    
    }

    Tristate Components::compute(std::size_t pin)
    {
        Tristate state = UNDEFINED;

        if (pin == 0)
            state = FALSE;
        else if (pin == 1)
            state = TRUE;
        return state;
    }

    void Components::dump() const
    {
        
    }

    size_t Components::getPinIndex(size_t pin) const
    {
        size_t index = 0;

        for (index = 0; index < _inPuts1.size() && index < _inPuts2.size() && index < _outPuts.size(); index++) {
            if (pin == _inPuts1[index] || pin == _inPuts2[index] || pin == _outPuts[index])
                break;
        }
        return index;
    }

    void Components::setValue(Tristate value, size_t put)
    {
        if (_type == "4008") {
            if (put == _cin.first)
                _cin.second = value;
            else if (put == _cout.first)
                _cout.second = value;
        }
        for (size_t i = 0; i < _inPuts1.size() && i < _inPuts2.size() && i < _outPuts.size(); i++) {
            if (put == _inPuts1[i]) {
                _pins.in1[put] = value;
                break;
            }
            else if (put == _inPuts2[i]) {
                _pins.in2[put] = value;
                break;
            }
            else if (put == _outPuts[i]) {
                _pins.out[put] = value;
                break;
            }
        }
    }

    std::string Components::getType() const
    {
        return _type;
    }

    std::map<std::size_t, Tristate> Components::getPin(const std::string &type) const
    {
        std::map<std::size_t, Tristate> pin;

        if (type == "in1")
            pin = _pins.in1;
        else if (type == "in2")
            pin = _pins.in2;
        else if (type == "out")
            pin = _pins.out;
        return pin;
    }

    std::string Components::getPinType(size_t pin) const
    {
        std::string type = "";

        for (size_t i = 0; i < _inPuts1.size() && i < _inPuts2.size() && i < _outPuts.size(); i++) {
            if (pin == _inPuts1[i]) {
                type = "in1";
                break;
            }
            else if (pin == _inPuts2[i]) {
                type = "in2";
                break;
            }
            else if (pin == _outPuts[i]) {
                type = "out";
                break;
            }
            else if (pin == _cout.first) {
                type = "cout";
                break;
            }
            else if (pin == _cin.first) {
                type = "cin";
                break;
            }
        }
        if (type == "") {
            int put = pin;
            throw NanoError("The pin " + std::to_string(put) + " can not be found.");
        }
        return type;
    }

    std::pair<size_t, Tristate> Components::getCarry(size_t type) const
    {
        std::pair<size_t, Tristate> res;

        if (type == 1)
            res = _cin;
        else if (type == 2)
            res = _cout;
        return res;
    }

    std::vector<std::size_t> Components::getPuts(size_t type) const
    {
        std::vector<size_t> puts = _inPuts1;

        if (type == 2)
            puts = _inPuts2;
        else if (type == 3)
            puts = _outPuts;
        return puts;
    }

    std::size_t Components::getNbPuts() const
    {
        return _nbPuts;
    }

    Tristate Components::getOutputValue(std::size_t pin) const
    {
        Tristate state = UNDEFINED;
        std::map<std::size_t, Tristate> puts;

        puts = _pins.out;
        for (std::size_t i = 0; i < _outPuts.size(); i++) {
            if (_outPuts[i] == pin) {
                state = puts[pin];
                break;
            }
        }
        return state;
    }

    std::vector<std::string> Components::getValues(std::map<std::size_t, Tristate> pin, std::vector<std::size_t> puts) const
    {
        std::vector<std::string> values;

        for (size_t i = 0; i < _nbPuts; i++) {
            if (pin[puts[i]] == TRUE)
                values.push_back("TRUE");
            else if (pin[puts[i]] == FALSE)
                values.push_back("FALSE");
            else
                values.push_back("UNDEFINED");
        }
        return values;
    }

    std::string Components::getName() const
    {
        return _name;
    }

    std::vector<std::size_t> Components::getInPuts1() const
    {
        return _inPuts1;
    }

    std::vector<std::size_t> Components::getInPuts2() const
    {
        return _inPuts2;
    }

    std::vector<std::size_t> Components::getOutPuts() const
    {
        return _outPuts;
    }

    void Connections::setComponent(Components *comp)
    {
        _comp = comp;
    }
    
    void Connections::setNext(Components *comp)
    {
        Connections *connect = new Connections;

        connect->_comp = comp;
        _next = connect;
    }

    Components *Connections::getComponent() const
    {
        return _comp;
    }

}
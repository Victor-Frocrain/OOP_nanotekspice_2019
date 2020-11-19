/*
** EPITECH PROJECT, 2020
** Circuit
** File description:
** Circuit.cpp
*/

#include "../include/Circuit.hpp"
#include <vector>
#include "../include/Tools.hpp"
#include "../include/nanoTekSpice.hpp"
#include <algorithm>

namespace nts {

    Circuit::Circuit()
    {

    }

    Circuit::~Circuit()
    {

    }

    Connections::Connections()
    {

    }

    Connections::~Connections()
    {

    }

    std::vector<Components*> Circuit::getComponents() const
    {
        return _comps;
    }
    
    int Circuit::addComponent(const std::string &line)
    {
        int result = 0;
        std::vector<std::string> infos;
        Tools tool;

        infos = tool.cutString(line, " \t");
        if (infos.size() != 2)
            throw NanoError("Declarations need to have two elements.");
        else {
            if (infos[0] == "input")
                _comps.push_back(new Input(infos[1]));
            else if (infos[0] == "output")
                _comps.push_back(new Output(infos[1]));
            else if (infos[0] == "4081")
                _comps.push_back(new Comp4081(infos[1]));
            else if (infos[0] == "clock")
                _comps.push_back(new Clock(infos[1]));
            else if (infos[0] == "4071")
                _comps.push_back(new Comp4071(infos[1]));
            else if (infos[0] == "4001")
                _comps.push_back(new Comp4001(infos[1]));
            else if (infos[0] == "4011")
                _comps.push_back(new Comp4011(infos[1]));
            else if (infos[0] == "4030")
                _comps.push_back(new Comp4030(infos[1]));
            else if (infos[0] == "4069")
                _comps.push_back(new Comp4069(infos[1]));
            else if (infos[0] == "4008")
                _comps.push_back(new Comp4008(infos[1]));
            else if (infos[0] == "true")
                _comps.push_back(new True(infos[1]));
            else if (infos[0] == "false")
                _comps.push_back(new False(infos[1]));
        }
        return result;
    }

    void Circuit::swapClockValues()
    {
        for (size_t i = 0; i < _comps.size(); i++) {
            if (_comps[i]->getType() == "clock") {
                Tristate state = _comps[i]->getOutputValue(1);
                if (state == TRUE)
                    _comps[i]->setValue(FALSE, 1);
                else if (state == FALSE)
                    _comps[i]->setValue(TRUE, 1);
            }
        }
    }

    int Circuit::compute()
    {
        Tristate state = UNDEFINED;
        std::map<int, std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>>::iterator it = _links.begin();
        size_t position = 0;
        bool inFound = false;

        for (; it != _links.end(); it++) {
            inFound = false;
            std::string InCompName = it->second.first.first;
            std::string OutCompName = it->second.second.first;
            std::size_t InPin = it->second.first.second;
            std::size_t OutPin = it->second.second.second;
            for (position = 0; position < _comps.size(); position++) {
                if (_comps[position]->getName() == InCompName) {
                    std::string pinType = "";
                    try {
                        pinType = _comps[position]->getPinType(InPin);
                    }
                    catch (NanoError &e) {
                        std::cerr << e.what() << std::endl;
                        return MY_EXIT_ERROR;
                    }
                    if (_comps[position]->getType() == "4008" && _comps[position]->getCarry(2).first == InPin)
                        state = _comps[position]->getCarry(2).second;
                    else
                        state = _comps[position]->getPin(pinType)[InPin];
                    inFound = true;
                    break;
                }
            }
            if (!inFound)
                throw NanoError("An input component didn't be found.");
            for (size_t i = 0; i < _comps.size(); i++) {
                if (_comps[i]->getName() == OutCompName) {
                    _comps[i]->setValue(state, OutPin);
                    _comps[i]->compute(_comps[i]->getPinIndex(OutPin));
                    break;
                }
            }
        }
        return 0;
    }

    void Circuit::displayOutputs() const
    {
        std::map<std::size_t, Tristate> pin;
        std::vector<std::string> outs;
        std::vector<Components *> outputs;

        for (size_t i = 0; i < _comps.size(); i++) {
            if (_comps[i]->getType() == "output") {
                outs.push_back(_comps[i]->getName());
            }
        }
        std::sort(outs.begin(), outs.end(), std::less<std::string>());
        for (size_t i = 0; i < outs.size(); i++) {
            for (size_t j = 0; j < _comps.size(); j++) {
                if (_comps[j]->getName() == outs[i]) {
                    outputs.push_back(_comps[j]);
                    break;
                }
            }
        }
        for (size_t i = 0; i < outputs.size(); i++) {
            std::vector<std::string> result;
            pin = outputs[i]->getPin("in1");
            result = outputs[i]->getValues(pin, outputs[i]->getPuts(1));
            for (size_t j = 0; j < result.size(); j++) {
                std::string res = "U";
                if (result[j] == "TRUE")
                    res = "1";
                else if (result[j] == "FALSE")
                    res = "0";
                std::cout << outputs[i]->getName() + "=" << res << std::endl;
            }
        }
    }

    void Circuit::dump() const
    {
        std::vector<std::string> in1;
        std::vector<std::string> in2;
        std::vector<std::string> out;
        std::map<std::size_t, Tristate> pin1;
        std::map<std::size_t, Tristate> pin2;
        std::map<std::size_t, Tristate> pin3;

        std::cout << "---CURRENT CIRCUIT---" << std::endl;
        for (size_t i = 0; i < _comps.size(); i++) {
            pin1 = _comps[i]->getPin("in1");
            pin2 = _comps[i]->getPin("in2");
            pin3 = _comps[i]->getPin("out");
            in1 = _comps[i]->getValues(pin1, _comps[i]->getPuts(1));
            in2 = _comps[i]->getValues(pin2, _comps[i]->getPuts(2));
            out = _comps[i]->getValues(pin3, _comps[i]->getPuts(3));
            std::cout << _comps[i]->getName() << ":";
            for (size_t j = 0; j < _comps[i]->getNbPuts(); j++) {
                std::cout << "\t" << in1[j] << " - " << in2[j] << " -> " << out[j] << std::endl;
            }
            std::cout << std::endl;
        }
    }

    size_t Circuit::getNbComps() const
    {
        return _comps.size();
    }

    void Circuit::setValue(size_t index, std::string value)
    {
        Tristate val = UNDEFINED;

        if (value == "1")
            val = TRUE;
        else if (value == "0")
            val = FALSE;
        else if (value == "-1")
            val = UNDEFINED;
        _comps[index]->setValue(val, 1);
    }

    Components *Circuit::findComp(const std::string &name) const
    {
        std::vector<IComponent*>::iterator it;
        Components *comp = NULL;

        for (size_t i = 0; i < _comps.size(); i++) {
            if (_comps[i]->getName() == name) {
                comp = _comps[i];
                break;
            }
        }
        if (comp == NULL)
            throw NanoError("The component " + name + " hasn't been declared.");
        return comp;
    }

    void Circuit::pushLinks(const std::pair<std::string, std::size_t> &ins, const std::pair<std::string, std::size_t> &outs)
    {
        static int index = 0;
        std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>> pair;

        pair.first = ins;
        pair.second = outs;
        _links[index] = pair;
        index++;
    }

    void Circuit::pushIns(const std::string &name, std::size_t value)
    {
        _ins[name].push_back(value);
    }

    void Circuit::pushOuts(const std::string &name, std::size_t value)
    {
        _outs[name].push_back(value);
    }

    void Circuit::changeValues(const std::string &str)
    {
        std::string name = "";
        std::string value = "";
        bool equal = false;
        bool found = false;

        for (size_t i = 0; i < str.length(); i++) {
            if (!equal && str[i] != '=')
                name += str[i];
            else if (str[i] != '=')
                value += str[i];
            if (!equal && str[i] == '=')
                equal = true;
            else if (equal && str[i] == '=')
                return;
        }
        if (name == "" || !equal)
            return;
        if (value != "0" && value != "1" && value != "-1")
            return;
        std::vector<nts::Components*> components = getComponents();
        for (size_t i = 0; i < components.size(); i++) {
            if (components[i]->getName() == name) {
                if (components[i]->getType() != "input")
                    return;
                else {
                    setValue(i, value);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            return;
    }
}
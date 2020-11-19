/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser.cpp
*/

#include "../include/nanoTekSpice.hpp"
#include "../include/Tools.hpp"

Parser::Parser()
{

}

Parser::~Parser()
{

}

bool Parser::checkInputValues(std::vector<nts::Components*> &components) const
{
    bool value = true;

    for (size_t i = 0; i < components.size(); i++) {
        if ((components[i]->getType() == "input" || components[i]->getType() == "clock") && components[i]->getOutputValue(1) == nts::UNDEFINED) {
            value = false;
            break;
        }
    }
    return value;
}

int Parser::parseValues(const char *val, nts::Circuit &comp) const
{
    int res = 0;
    std::string str(val);
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
            throw NanoError("Invalid argument.");
    }
    if (name == "" || !equal)
        throw NanoError("Invalid argument.");
    if (value != "0" && value != "1" && value != "-1")
        throw NanoError("Invalid value.");
    std::vector<nts::Components*> components = comp.getComponents();
    for (size_t i = 0; i < components.size(); i++) {
        if (components[i]->getName() == name) {
            if (components[i]->getType() != "input" && components[i]->getType() != "clock")
                throw NanoError("Only inputs can be set.");
            else {
                comp.setValue(i, value);
                found = true;
                break;
            }
        }
    }
    if (!found)
        throw NanoError("No component called " + name + " found.");
    return res;
}

int Parser::checkArgs(int ac, char **args, nts::Circuit &comp) const
{
    int value = 0;

    if (ac < 2)
        throw NanoError("Arguments needed.");
    else {
        try {
            value = parseFile(args[1], comp);
        }
        catch (NanoError &e) {
            throw NanoError(e.what());
        }
        for (int i = 2; i < ac; i++) {
            try {
                value = parseValues(args[i], comp);
            }
            catch (NanoError &e) {
                throw NanoError(e.what());
                value = MY_EXIT_ERROR;
                break;
            }
        }
        std::vector<nts::Components*> components = comp.getComponents();
        if (!checkInputValues(components))
            throw NanoError("All inputs must be initialized.");
    }
    return value;
}

int Parser::parseFile(char *filename, nts::Circuit &comp) const
{
    int returnValue = 0;
    std::ifstream fs;

    if (filename) {
        fs.open(filename);
        if (!fs.fail()) {
            try {
                returnValue = parseContent(fs, comp);
                fs.close();
            }
            catch (NanoError &e) {
                throw NanoError(e.what());
            }
        }
        else
            throw NanoError("The file cannot be opened or doesn't exists.");
    }
    else
        throw NanoError("The file name is empty or NULL.");
    return returnValue;
}

int Parser::parseContent(std::ifstream &fs, nts::Circuit &comp) const
{
    int result = 0;
    std::string line;
    bool chipsets = false;
    bool links = false;
    Tools tool;

    while (std::getline(fs, line)) {
        line = tool.realeaseComments(line);
        line = tool.cleanStrings(line);
        if (line.length() > 0) {
            if (line == ".chipsets:")
                chipsets = true;
            else if (line == ".links:")
                links = true;
            else {
                try {
                    result = fillChipsets(chipsets, links, line, comp);
                }
                catch (NanoError &e) {
                    throw NanoError(e.what());
                }
            }
        }
        if (result == MY_EXIT_ERROR)
            return result;
    }
    if (!chipsets || !links) {
        throw NanoError("There is no chipset or link.");
    }
    return result;
}

int Parser::fillChipsets(const bool &chipsets, const bool &links, const std::string &line, nts::Circuit &comp) const
{
    int result = 0;

    try {
        if (chipsets && !links)
            comp.addComponent(line);
        else if (links)
            result = fillLinks(line, comp);
    }
    catch (NanoError &e) {
        throw NanoError(e.what());
    }
    return result;
}

bool Parser::fillAdderComp(nts::Components *comp, std::pair<std::string, std::size_t> first, std::pair<std::string, std::size_t> second,
                           std::pair<std::string, std::size_t> &in, std::pair<std::string, std::size_t> &out) const
{
    bool res = false;

    if (comp->getType() == "4008") {

        std::string firstName = first.first;
        std::string secondName = second.first;
        size_t firstPin = first.second;
        size_t secondPin = second.second;
        size_t cin = comp->getCarry(1).first;
        size_t cout = comp->getCarry(2).first;

        if (comp->getName() == firstName && cin == firstPin) {
            out = first;
            res = true;
        }
        else if (comp->getName() == secondName && cin == secondPin) {
            out = second;
            res = true;
        }
        else if (comp->getName() == firstName && cout == firstPin) {
            in = first;
            res = true;
        }
        else if (comp->getName() == secondName && cout == secondPin) {
            in = second;
            res = true;
        }
    }
    return res;
}

int Parser::fillLinks(const std::string &line, nts::Circuit &comp) const
{
    Tools tool;
    std::pair<std::string, std::size_t> first;
    std::pair<std::string, std::size_t> second;
    std::pair<std::string, std::size_t> in = { "", 0 };
    std::pair<std::string, std::size_t> out = { "", 0 };
    std::vector<nts::Components *> components = comp.getComponents();
    std::vector<std::size_t> inPuts1;
    std::vector<std::size_t> inPuts2;
    std::vector<std::size_t> outPuts;

    try {
        first = tool.findIn(line, 0);
        second = tool.findOut(line);
    }
    catch (NanoError &e) {
        std::cerr << e.what() << std::endl;
        return MY_EXIT_ERROR;
    }

    std::string firstName = first.first;
    std::string secondName = second.first;
    size_t firstPin = first.second;
    size_t secondPin = second.second;

    for (size_t i = 0; i < components.size(); i++) {
        if (components[i]->getName() == firstName || components[i]->getName() == secondName) {
            inPuts1 = components[i]->getPuts(1);
            inPuts2 = components[i]->getPuts(2);
            outPuts = components[i]->getPuts(3);
            fillAdderComp(components[i], first, second, in, out);
            for (size_t j = 0; j < inPuts1.size() && j < inPuts2.size() && j < outPuts.size(); j++) {
                if (components[i]->getName() == firstName && (inPuts1[j] == firstPin || inPuts2[j] == firstPin)) {
                    out = first;
                }
                else if (components[i]->getName() == secondName && (inPuts1[j] == secondPin || inPuts2[j] == secondPin)) {
                    out = second;
                }
                else if (components[i]->getName() == firstName && outPuts[j] == firstPin) {
                    in = first;
                }
                else if (components[i]->getName() == secondName && outPuts[j] == secondPin) {
                    in = second;
                }
            }
            if (in.first != "" && out.first != "") {
                break;
            }
        }
    }
    if (in.first == "" || out.first == "")
        throw NanoError("Input or output mistake in configuration file.");
    comp.pushIns(in.first, in.second);
    comp.pushOuts(out.first, out.second);
    comp.pushLinks(in, out);
    return 0;
}
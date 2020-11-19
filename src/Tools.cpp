/*
** EPITECH PROJECT, 2020
** Tools
** File description:
** Tools.cpp
*/

#include "../include/Tools.hpp"
#include "../include/Error.hpp"
#include <iostream>

Tools::Tools()
{

}

std::string Tools::reverseString(std::string &line) const
{
    std::string newLine = "";

    for (int i = line.length() - 1; i >= 0; i--)
        newLine += line[i];
    return newLine;
}

std::string Tools::realeaseComments(std::string &line) const
{
    std::string copy = "";

    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == '#')
            break;
        copy += line[i];
    }
    return copy;
}

std::string Tools::cleanStrings(std::string &line) const
{
    std::string newLine = "";
    std::string tmp = "";
    size_t begin = 0;
    size_t end = 0;

    for (; begin < line.length() && (line[begin] == ' ' || line[begin] == '\t'); begin++);
    tmp = reverseString(line);
    for (; end < tmp.length() && (tmp[end] == ' ' || tmp[end] == '\t'); end++);
    if (line.length() == 0)
        end = 0;
    else
        end = line.length() - end - begin;
    newLine = line.substr(begin, end);
    return newLine;
}

std::vector<std::string> Tools::cutString(const std::string &str, const std::string &separators) const
{
    std::vector<std::string> listString;
    std::string newStr = "";
    bool isFound = false;
    bool goodChar = true;

    for (size_t i = 0; i < str.length(); i++) {
        isFound = false;
        goodChar = true;
        for (size_t j = 0; j < separators.length(); j++) {
            if (str[i] == separators[j]) {
                isFound = true;
                goodChar = false;
                break;
            }
        }
        if (!isFound && goodChar)
            newStr += str[i];
        else if (newStr != "") {
            listString.push_back(newStr);
            newStr = "";
        }
    }
    if (newStr != "")
        listString.push_back(newStr);
    return listString;
}

std::pair<std::string, int> Tools::findIn(const std::string &str, size_t begin) const
{
    std::pair<std::string, int> ins;
    std::string param = "";
    std::string name = "";
    std::string value = "";
    bool hasSep = false;

    for (size_t i = begin; i < str.length(); i++) {
        if (str[i] == ':' && !hasSep)
            hasSep = true;
        else if (str[i] == ':' && hasSep)
            throw NanoError("Invalid parameter.");
        if (str[i] != ' ' && str[i] != '\t')
            param += str[i];
        else
            break;
    }
    if (!hasSep || param == "")
        throw NanoError("Invalid parameter.");
    hasSep = false;
    for (size_t i = 0; i < param.length(); i++) {
        if (param[i] != ':' && !hasSep)
            name += param[i];
        else if (param[i] != ':' && hasSep)
            value += param[i];
        else if (param[i] == ':')
            hasSep = true;
    }
    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] < '0' || value[i] > '9')
            throw NanoError("Invalid parameter.");
    }
    if (name == "" || value == "")
        throw NanoError("Invalid parameter.");
    ins.first = name;
    ins.second = std::stoi(value);
    return ins;
}

std::pair<std::string, int> Tools::findOut(const std::string &str) const
{
    size_t begin = 0;

    for (; begin < str.length() && str[begin] != ' ' && str[begin] != '\t'; begin++);
    for (; begin < str.length() && (str[begin] == ' ' || str[begin] == '\t'); begin++);
    if (begin == str.length())
        throw NanoError("Invalid parameter.");
    return findIn(str, begin);
}
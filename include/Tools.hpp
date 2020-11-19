/*
** EPITECH PROJECT, 2020
** Tools
** File description:
** Tools.hpp
*/

#include <vector>
#include <string>

#ifndef TOOLS_HPP_
#define TOOLS_HPP_

class Tools {
    public:
    Tools();

    std::vector<std::string> cutString(const std::string &str, const std::string &separator) const;
    std::pair<std::string, int> findIn(const std::string &str, size_t begin) const;
    std::pair<std::string, int> findOut(const std::string &str) const;
    std::string cleanStrings(std::string &line) const;
    std::string reverseString(std::string &line) const;
    std::string realeaseComments(std::string &line) const;
};

#endif /* TOOLS_HPP_ */

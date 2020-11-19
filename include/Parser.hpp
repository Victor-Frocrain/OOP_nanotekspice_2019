/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser.hpp
*/

#include "Circuit.hpp"
#include <fstream>

#ifndef PARSER_HPP_
#define PARSER_HPP_

#define MY_EXIT_ERROR 84

class Parser {
    public:
    Parser();
    ~Parser();

    int checkArgs(int ac, char **args, nts::Circuit &comp) const;
    int parseFile(char *filename, nts::Circuit &comp) const;
    int parseContent(std::ifstream &buff, nts::Circuit &comp) const;
    int fillChipsets(const bool &chipsets, const bool &links, const std::string &line, nts::Circuit &comp) const;
    int fillLinks(const std::string &line, nts::Circuit &comp) const;
    int parseValues(const char *val, nts::Circuit &comp) const;
    bool checkInputValues(std::vector<nts::Components*> &components) const;
    bool fillAdderComp(nts::Components *comp, std::pair<std::string, std::size_t> first, std::pair<std::string, std::size_t> second,
                       std::pair<std::string, std::size_t> &in, std::pair<std::string, std::size_t> &out) const;
};

#endif /* PARSER_HPP_ */

/*
** EPITECH PROJECT, 2020
** Interpretor
** File description:
** Interpretor.hpp
*/

#include "../include/nanoTekSpice.hpp"
#include <csignal>

#ifndef INTERPRETOR_HPP_
#define INTERPRETOR_HPP_

class Interpretor {
    public:
    Interpretor();

    void readInput(nts::Circuit &comp) const;
    void execCommand(const std::string &command, nts::Circuit &comp) const;
    static void sig_handler(int signal);
};

#endif /* INTERPRETOR_HPP_ */

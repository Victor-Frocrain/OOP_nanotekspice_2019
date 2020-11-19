/*
** EPITECH PROJECT, 2020
** Interpretor
** File description:
** Interpretor.cpp
*/

#include "../include/Interpretor.hpp"
#include <string>

static bool interrupt = false;

Interpretor::Interpretor()
{

}

void Interpretor::readInput(nts::Circuit &comp) const
{
    std::string command = "";
    char c = 1;

    while (c != EOF && command != "exit") {
        std::cout << "> ";
        c = 1;
        command = "";
        while (c != '\n' && c != EOF) {
            c = std::cin.get();
            if (c != '\n')
                command += c;
        }
        execCommand(command, comp);
    }
}

void Interpretor::sig_handler(int signal)
{
    if (signal == 2)
        interrupt = true;
}

void Interpretor::execCommand(const std::string &command, nts::Circuit &comp) const
{
    if (command == "dump")
        comp.dump();
    else if (command == "simulate") {
        comp.compute();
        comp.swapClockValues();
    }
    else if (command == "display")
        comp.displayOutputs();
    else if (command == "loop") {
        while (!interrupt) {
            comp.compute();
            comp.swapClockValues();
            comp.displayOutputs();
            std::signal(SIGINT, sig_handler);
        }
        interrupt = false;
    }
    else
        comp.changeValues(command);
}
/*
** EPITECH PROJECT, 2020
** Circuit
** File description:
** Circuit.cpp
*/

#include "../include/nanoTekSpice.hpp"
#include "../include/Interpretor.hpp"

NanoTekSpice::NanoTekSpice()
{
    
}

int NanoTekSpice::progEntry(int ac, char **args) const
{
    int returnValue = 0;
    Parser parse;
    nts::Circuit comp;
    Interpretor interpretor;

    try {
        returnValue = parse.checkArgs(ac, args, comp);
        returnValue = comp.compute();
        comp.swapClockValues();
        comp.displayOutputs();
        interpretor.readInput(comp);
    }
    catch (NanoError &e) {
        std::cerr << e.what() << std::endl;
        returnValue = MY_EXIT_ERROR;
    }
    return (returnValue);
}
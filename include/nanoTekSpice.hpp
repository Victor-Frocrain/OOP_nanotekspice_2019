/*
** EPITECH PROJECT, 2020
** nanoTekSpice
** File description:
** nanoTekSpice.hpp
*/

#include "Parser.hpp"
#include "Puts.hpp"
#include "Clock.hpp"
#include "Error.hpp"
#include "Circuit.hpp"
#include "Comp4081.hpp"
#include "Comp4071.hpp"
#include "Comp4001.hpp"
#include "Comp4011.hpp"
#include "Comp4030.hpp"
#include "Comp4069.hpp"
#include "Comp4008.hpp"
#include "TrueFalse.hpp"
#include <iostream>

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

class NanoTekSpice {
    public:
    NanoTekSpice();

    int progEntry(int ac, char **av) const;
};

#endif /* NANOTEKSPICE_HPP_ */

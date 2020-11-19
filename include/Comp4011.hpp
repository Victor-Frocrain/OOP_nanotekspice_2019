/*
** EPITECH PROJECT, 2020
** Comp4011
** File description:
** Comp4011.hpp
*/

#include "Components.hpp"

#ifndef COMP4011_HPP_
#define COMP4011_HPP_

namespace nts {
    class Comp4011 : public Components {
        public:
        Comp4011(const std::string &name = "");
        ~Comp4011();

        nts::Tristate compute(std:: size_t pin = 1);
    };
}

#endif /* COMP4011_HPP_ */

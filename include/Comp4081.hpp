/*
** EPITECH PROJECT, 2020
** Comp4081
** File description:
** Comp4081.hpp
*/

#include "Components.hpp"

#ifndef COMP4081_HPP_
#define COMP4081_HPP_

namespace nts {
    class Comp4081 : public Components {
        public:
        Comp4081(const std::string &name = "");
        ~Comp4081();

        nts::Tristate compute(std:: size_t pin = 1);
    };
}

#endif /* COMP4081_HPP_ */

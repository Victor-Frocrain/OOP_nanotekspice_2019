/*
** EPITECH PROJECT, 2020
** Comp4069
** File description:
** Comp4069.hpp
*/

#include "Components.hpp"

#ifndef COMP4069_HPP_
#define COMP4069_HPP_

namespace nts {
    class Comp4069 : public Components {
        public:
        Comp4069(const std::string &name = "");
        ~Comp4069();

        nts::Tristate compute(std:: size_t pin = 1);
    };
}

#endif /* COMP4069_HPP_ */

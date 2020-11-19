/*
** EPITECH PROJECT, 2020
** Comp4030
** File description:
** Comp4030.hpp
*/

#include "Components.hpp"

#ifndef COMP4030_HPP_
#define COMP4030_HPP_

namespace nts {
    class Comp4030 : public Components {
        public:
        Comp4030(const std::string &name = "");
        ~Comp4030();

        nts::Tristate compute(std:: size_t pin = 1);
    };
}

#endif /* COMP4030_HPP_ */

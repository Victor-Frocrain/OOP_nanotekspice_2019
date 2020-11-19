/*
** EPITECH PROJECT, 2020
** Comp4008
** File description:
** Comp4008.hpp
*/

#include "Components.hpp"

#ifndef COMP4008_HPP_
#define COMP4008_HPP_

namespace nts {
    class Comp4008 : public Components {
        public:
        Comp4008(const std::string &name = "");
        ~Comp4008();

        Tristate compute(std:: size_t pin = 1);
    };
}

#endif /* COMP4008_HPP_ */

/*
** EPITECH PROJECT, 2020
** Comp4071
** File description:
** Comp4071.hpp
*/

#include "Components.hpp"

#ifndef COMP4071_HPP_
#define COMP4071_HPP_

namespace nts {
    class Comp4071 : public Components {
        public:
        Comp4071(const std::string &name = "");
        ~Comp4071();

        nts::Tristate compute(std:: size_t pin = 1);
    };
}

#endif /* COMP4071_HPP_ */

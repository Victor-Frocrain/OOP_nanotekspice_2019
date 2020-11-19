/*
** EPITECH PROJECT, 2020
** Comp4001
** File description:
** Comp4001.hpp
*/

#include "IComponent.hpp"
#include "Components.hpp"

#ifndef COMP4001_HPP_
#define COMP4001_HPP_

namespace nts {
    class Comp4001 : public Components {
        public:
        Comp4001(const std::string &name = "");
        ~Comp4001();

        nts::Tristate compute(std:: size_t pin = 1);
    };
}

#endif /* COMP4001_HPP_ */

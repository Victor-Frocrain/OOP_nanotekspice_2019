/*
** EPITECH PROJECT, 2020
** Clock
** File description:
** Clock.hpp
*/

#include "Components.hpp"

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

namespace nts {
    class Clock : public Components {
        public:
        Clock(const std::string &name = "");
        ~Clock();

        virtual Tristate compute(std::size_t pin = 1);

        void setValue(std::size_t value);
        std::size_t getValue() const;
    };
}

#endif /* CLOCK_HPP_ */

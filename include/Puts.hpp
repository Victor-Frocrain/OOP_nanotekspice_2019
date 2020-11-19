/*
** EPITECH PROJECT, 2020
** Puts
** File description:
** Puts.hpp
*/

#include "Components.hpp"

#ifndef PUTS_HPP_
#define PUTS_HPP_

namespace nts {
    class Input : public Components {
        public:
        Input(const std::string &name = "");
        ~Input();

        virtual Tristate compute(std::size_t pin = 1);

        void setValue(std::size_t value);
        std::size_t getValue() const;
    };

    class Output : public Components {
        public:
        Output(const std::string &name = "");
        ~Output();

        virtual Tristate compute(std::size_t pin = 1);

        void setValue(std::size_t value);
        std::size_t getValue() const;
    };
}

#endif /* PUTS_HPP_ */

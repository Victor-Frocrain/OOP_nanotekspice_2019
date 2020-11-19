/*
** EPITECH PROJECT, 2020
** TrueFalse
** File description:
** TrueFalse.hpp
*/

#include "Components.hpp"

#ifndef TRUEFALSE_HPP_
#define TRUEFALSE_HPP_

namespace nts {
    class True : public Components {
        public:
        True(const std::string &name = "");
        ~True();

        virtual Tristate compute(std::size_t pin = 1);

        void setValue(std::size_t value);
        std::size_t getValue() const;
    };

    class False : public Components {
        public:
        False(const std::string &name = "");
        ~False();

        virtual Tristate compute(std::size_t pin = 1);

        void setValue(std::size_t value);
        std::size_t getValue() const;
    };
}

#endif /* TRUEFALSE_HPP_ */

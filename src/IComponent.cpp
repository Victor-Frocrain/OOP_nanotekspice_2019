/*
** EPITECH PROJECT, 2020
** IComponent
** File description:
** IComponent.cpp
*/

#include "../include/IComponent.hpp"

namespace nts {

    Tristate IComponent::compute(std::size_t pin)
    {
        Tristate state = UNDEFINED;

        if (pin == 0)
            state = FALSE;
        else if (pin == 1)
            state = TRUE;
        return state;
    }
    
    /*void IComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {

    }*/

    void IComponent::dump() const
    {

    }

}
/*
** EPITECH PROJECT, 2020
** IComponent
** File description:
** IComponent.hpp
*/

#include <cstddef>
#include <string>
#include <map>
#include <vector>

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace nts
{
    enum Tristate {UNDEFINED = (-true),TRUE = true ,FALSE = false};
    
    class IComponent {
        public:
        virtual ~IComponent() = default;

        public:
        virtual Tristate compute(std::size_t pin = 1) = 0;
        //virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const = 0;
        virtual std::string getName() const = 0;
        virtual std::vector<std::string> getValues(std::map<std::size_t, Tristate> pin, std::vector<std::size_t>) const = 0;
        virtual std::map<std::size_t, Tristate>getPin(const std::string &type) const = 0;
        virtual void setValue(Tristate value, size_t put) = 0;
        virtual std::string getType() const = 0;
        virtual std::vector<std::size_t> getPuts(size_t type) const = 0;
        virtual std::size_t getNbPuts() const = 0;
        virtual std::vector<std::size_t> getInPuts1() const = 0;
        virtual std::vector<std::size_t> getInPuts2() const = 0;
        virtual std::vector<std::size_t> getOutPuts() const = 0;
        virtual std::string getPinType(size_t pin) const = 0;
        virtual size_t getPinIndex(size_t pin) const = 0;
        virtual std::pair<size_t, Tristate> getCarry(size_t type) const = 0;
    };
}

#endif /* ICOMPONENT_HPP_ */

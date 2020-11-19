/*
** EPITECH PROJECT, 2020
** Component
** File description:
** Component.hpp
*/

#include "IComponent.hpp"
#include <list>
#include <map>
#include <vector>

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

namespace nts {
    class Pins {
        public:
        Pins();

        std::map<std::size_t, Tristate> in1;
        std::map<std::size_t, Tristate> in2;
        std::map<std::size_t, Tristate> out;
        std::map<std::size_t, Tristate> carry;
    };

    class Components : public IComponent {
        public:
        Components();
        ~Components();

        virtual Tristate compute(std::size_t pin = 1) = 0;
        //void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
        void dump() const;
        std::string getName() const;
        std::vector<std::string> getValues(std::map<std::size_t, Tristate> pin, std::vector<std::size_t>) const;
        std::map<std::size_t, Tristate>getPin(const std::string &type) const;
        std::string getType() const;
        void setValue(Tristate value, size_t put);
        std::vector<std::size_t> getPuts(size_t type) const;
        std::size_t getNbPuts() const;
        std::vector<std::size_t> getInPuts1() const;
        std::vector<std::size_t> getInPuts2() const;
        std::vector<std::size_t> getOutPuts() const;
        Tristate getOutputValue(size_t pin) const;
        std::string getPinType(size_t pin) const;
        size_t getPinIndex(size_t pin) const;
        std::pair<size_t, Tristate> getCarry(size_t type) const;

        protected:
        std::string _name;
        Pins _pins;
        std::vector<std::size_t> _inPuts1;
        std::vector<std::size_t> _inPuts2;
        std::vector<std::size_t> _outPuts;
        std::pair<std::size_t, Tristate> _cin;
        std::pair<std::size_t, Tristate> _cout;
        std::size_t _nbPuts;
        std::string _type;
    };
}

#endif /* COMPONENT_HPP_ */

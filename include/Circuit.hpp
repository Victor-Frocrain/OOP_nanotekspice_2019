/*
** EPITECH PROJECT, 2020
** Circuit
** File description:
** Circuit.hpp
*/

#include "Components.hpp"
#include <vector>
#include <set>

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

namespace nts {
    class Connections {
        public:
        Connections();
        ~Connections();

        void setComponent(Components *comp);
        void setNext(Components *comp);
        Components *getComponent() const;

        private:
        Connections *_next;
        Components *_comp;
    };

    class Circuit {
        public:
        Circuit();
        ~Circuit();

        std::vector<Components*> getComponents() const;
        int addComponent(const std::string &line);
        int compute();
        void dump() const;
        size_t getNbComps() const;
        void setValue(size_t index, std::string value);
        Components *findComp(const std::string &name) const;
        void pushIns(const std::string &name, std::size_t value);
        void pushOuts(const std::string &name, std::size_t value);
        void pushLinks(const std::pair<std::string, std::size_t> &ins, const std::pair<std::string, std::size_t> &outs);
        void displayOutputs() const;
        void changeValues(const std::string &str);
        void swapClockValues();

        protected:
        std::map<std::string, std::vector<std::size_t>> _ins;
        std::map<std::string, std::vector<std::size_t>> _outs;
        std::map<int, std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>> _links;
        std::vector<Components*> _comps;
        std::vector<Connections> _connections;
    };
}

#endif /* CIRCUIT_HPP_ */

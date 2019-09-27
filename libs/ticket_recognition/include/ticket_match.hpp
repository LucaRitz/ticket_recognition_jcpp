#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {
    class EXPORT TicketMatch {
    public:
        TicketMatch(string name) : _name(std::move(name)) {}
        TicketMatch(const TicketMatch& other) : _name(other._name) {};
        TicketMatch(TicketMatch&& other) : _name(other._name) {};
        TicketMatch& operator=(const TicketMatch& other) = delete;
        TicketMatch& operator=(TicketMatch&&) = delete;

        const string name() const {
            return _name;
        }

    private:
        const string _name;
    };
}
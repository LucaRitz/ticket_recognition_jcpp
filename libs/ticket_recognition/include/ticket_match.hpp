#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {
    class EXPORT TicketMatch {
    public:
        TicketMatch(string);
        TicketMatch(const TicketMatch&);
        TicketMatch(TicketMatch&&);
        TicketMatch& operator=(const TicketMatch& other) = delete;
        TicketMatch& operator=(TicketMatch&&) = delete;

        const string name() const;

    private:
        const string _name;
    };
}
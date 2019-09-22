#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {
    class EXPORT TicketMatch {
            public:
            TicketMatch(string name) : name(name) {}
            TicketMatch(const TicketMatch& other) = delete;
            TicketMatch(TicketMatch&& other) = delete;
            TicketMatch& operator=(const TicketMatch& other) = delete;
            TicketMatch& operator=(TicketMatch&& other) = delete;

            string getName() const {
                return name;
            }

            private:
            const string name;
    };
}
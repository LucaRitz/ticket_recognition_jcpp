#pragma once

#include "dllmacro.h"

namespace cti {
    class Ticket;

    class EXPORT TicketMatch {
    public:
        explicit TicketMatch(const Ticket&);
        TicketMatch(const TicketMatch&);
        TicketMatch(TicketMatch&&);
        TicketMatch& operator=(const TicketMatch& other) = delete;
        TicketMatch& operator=(TicketMatch&&) = delete;

        const Ticket& ticket() const;

    private:
        const Ticket& _ticket;
    };
}
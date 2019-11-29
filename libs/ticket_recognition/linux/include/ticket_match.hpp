#pragma once

#include "dllmacro.h"

namespace cti {
    class Ticket;

    class EXPORT TicketMatch {
    public:
        explicit TicketMatch(const Ticket&, const double);
        TicketMatch(const TicketMatch&);
        TicketMatch(TicketMatch&&);
        TicketMatch& operator=(const TicketMatch& other) = delete;
        TicketMatch& operator=(TicketMatch&&) = delete;

        const Ticket& ticket() const;
        const double score() const;

    private:
        const Ticket& _ticket;
        const double _score;
    };
}
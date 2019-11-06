#pragma once

#include <include/dllmacro.h>
#include <vector>

using std::vector;

namespace cti {

    class Ticket;
    class TicketImage;
    class TicketMatch;

    class EXPORT MatchingAlgorithm {
    public:
        virtual void train(const Ticket&) = 0;
        virtual void train(const vector<const Ticket*>&) = 0;
        virtual vector<TicketMatch> execute(const TicketImage&) const = 0;
        virtual const TicketMatch select(vector<TicketMatch>&) const = 0;
    };
}
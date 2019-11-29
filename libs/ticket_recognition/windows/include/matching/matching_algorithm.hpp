#pragma once

#include <include/dllmacro.h>
#include <vector>
#include <optional>

using std::vector;
using std::optional;

namespace cti {

    class Ticket;
    class TicketImage;
    class TicketMatch;

    class EXPORT MatchingAlgorithm {
    public:
        virtual void train(const Ticket&) = 0;
        virtual void train(const vector<const Ticket*>&) = 0;
        virtual vector<TicketMatch> execute(const TicketImage&) = 0;
        virtual const optional<TicketMatch> select(vector<TicketMatch>&) const = 0;
    };
}
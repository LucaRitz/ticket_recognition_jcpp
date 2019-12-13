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

    /**
     * Abstract class describing an algorithm used to match a given TicketImage to one of several known Tickets.
     * First, Tickets are trained, in order for them to be known.
     * Secondly, a TicketImage is supplied and any number of TicketMatches are returned.
     * Finally, the best TicketMatch is selected and returned.
     * If none of the TicketMatches is good enough, none is returned.
     */
    class EXPORT MatchingAlgorithm {
    public:

        /**
         * Train a single Ticket. The Ticket is preprocessed in order to save time when matching.
         */
        virtual void train(const Ticket&) = 0;

        /**
         * Train any number of Tickets. The Tickets are preprocessed in order to save time when matching.
         */
        virtual void train(const vector<const Ticket*>&) = 0;

        /**
         * Find viable TicketMatches for the given TicketImage. These represent candidates for the matched Ticket.
         * @return
         */
        virtual vector<TicketMatch> execute(const TicketImage&) = 0;

        /**
         * Select the best TicketMatch from a given list or discard all of them if none is good enough.
         * @return
         */
        virtual const optional<TicketMatch> select(vector<TicketMatch>&) const = 0;
    };
}
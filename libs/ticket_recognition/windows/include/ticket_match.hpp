#pragma once

#include "dllmacro.h"

namespace cti {
    class Ticket;

    /**
     * Match returned by a MatchingAlgorithm or a Matcher indicating that a TicketImage
     * has been found in a set of Ticket's. The quality of the TicketMatch is indicated in it's score.
     */
    class EXPORT TicketMatch {
    public:

        /**
         * Construct a TicketMatch using a matched Ticket and a matching score.
         * @param ticket Reference to the matched Ticket.
         * @param score Score of the TicketMatch. The higher the score, the better the match.
         */
        explicit TicketMatch(const Ticket& ticket, double score);

        TicketMatch(const TicketMatch&);
        TicketMatch(TicketMatch&&);
        TicketMatch& operator=(const TicketMatch& other) = delete;
        TicketMatch& operator=(TicketMatch&&) = delete;

        /**
         * Reference to the matched Ticket.
         * @return
         */
        const Ticket& ticket() const;

        /**
         * Score of the TicketMatch. The higher the score, the better the match.
         * @return
         */
        double score() const;

    private:
        const Ticket& _ticket;
        const double _score;
    };
}
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
        * Train a single Ticket so that a TicketImage can be matched against it.
        * Note that this operation may take some time. The Ticket is preprocessed in order to save time when matching.
        * If the Ticket has a name that has already been trained, previous training data is
        * discarded and it is trained again.
        * If multiple Ticket are to be trained, a different overload of this function should be used,
        * since training multiple Ticket's is more efficient than training every single one of them independently.
        * @param ticket Ticket to be trained.
        */
        virtual void train(const Ticket&) = 0;

        /**
         * Train a set of Ticket so that a TicketImage can be matched against them.
         * Note that this operation may take some time. The Tickets are preprocessed in order to save time when matching.
         * If one of the Tickets has a name that has already been trained, previous training data is
         * discarded and that Ticket is trained again.
         * @param tickets Tickets to be trained.
         */
        virtual void train(const vector<const Ticket*>&) = 0;

        /**
         * Discard all training data associated to the given Ticket's name.
         * The Ticket will no longer be matched against on subsequent calls to match.
         * @param ticket Ticket to be untrained.
         */
        virtual void untrain(const Ticket& ticket) = 0;

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
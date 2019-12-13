#pragma once

#include "dllmacro.h"
#include <vector>
#include <optional>

using std::vector;

namespace cti {

    class TicketMatch;
    class TicketImage;
    class Ticket;
    class MatchingAlgorithm;

    /**
     * Provides the ability to train a set of Ticket's that describe all supported kinds of tickets.
     * After training, a ticket to be processed can be matched against the trained set of Ticket's using a TicketImage.
     * The image of the ticket is compared to all known Ticket's and if it matches,
     * the Ticket with the best score is returned.
     * It may also be that no Ticket matches because the TicketImage shows a kind of ticket that is unknown.
     * It makes sense to use this in combination with a MetadataReader, which can be used after matching for
     * extracting Metadata that is located on the given TicketImage and which is defined in the matched Ticket.
     */
    class EXPORT Matcher {
    public:

        /**
         * Constructs a Matcher using a given implementation of a MatchingAlgorithm.
         * @param matchingAlgorithms Algorithm used for Ticket matching. Can be constructed using factory methods on class MatchingAlgorithms.
         */
        explicit Matcher(MatchingAlgorithm& matchingAlgorithms);

        Matcher(const Matcher&) = delete;
        Matcher(Matcher&&) = delete;
        Matcher& operator=(const Matcher&) = delete;
        Matcher& operator=(Matcher&&) = delete;

        /**
         * Train a single Ticket so that a TicketImage can be matched against it.
         * Note that this operation may take some time. The Ticket is preprocessed in order to save time when matching.
         * If the Ticket has a name that has already been trained, previous training data is
         * discarded and it is trained again.
         * If multiple Ticket are to be trained, a different overload of this function should be used,
         * since training multiple Ticket's is more efficient than training every single one of them independently.
         * @param ticket Ticket to be trained.
         */
        void train(const Ticket& ticket);

        /**
         * Train a set of Ticket so that a TicketImage can be matched against them.
         * Note that this operation may take some time. The Tickets are preprocessed in order to save time when matching.
         * If one of the Tickets has a name that has already been trained, previous training data is
         * discarded and that Ticket is trained again.
         * @param tickets Tickets to be trained.
         */
        void train(const vector<const Ticket*>& tickets);

        /**
         * Discard all training data associated to the given Ticket's name.
         * The Ticket will no longer be matched against on subsequent calls to match.
         * @param ticket Ticket to be untrained.
         */
        void untrain(const Ticket& ticket);

        /**
         * Match a ticket to be processed, provided as a TicketImage, against the previouly trained set of Tickets.
         * @return an optional TicketMatch describing the one Ticket that matched or an empty optional if none matched.
         */
        const std::optional<const TicketMatch> match(const TicketImage&) const;

    private:
        MatchingAlgorithm& _algorithm;
    };
}
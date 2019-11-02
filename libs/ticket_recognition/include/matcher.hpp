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

    class EXPORT Matcher {
    public:
        Matcher(MatchingAlgorithm&);
        Matcher(const Matcher&) = delete;
        Matcher(Matcher&&) = delete;
        Matcher& operator=(const Matcher&) = delete;
        Matcher& operator=(Matcher&&) = delete;

        void train(const Ticket&);
        void train(const vector<const Ticket*>&);
        const std::optional<const TicketMatch> match(const TicketImage&) const;

    private:
        MatchingAlgorithm& _algorithm;
    };
}
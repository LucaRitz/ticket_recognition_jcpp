#pragma once

#include <include/dllmacro.h>
#include <include/algorithm/matching_algorithm.hpp>

namespace cti {

    class EXPORT SiftMatchingAlgorithm : public MatchingAlgorithm {
    public:
        void train(const Ticket&) override;
        void train(const vector<const Ticket*>&) override;
        vector<TicketMatch> execute(const TicketImage&) const override;
        const optional<TicketMatch> select(vector<TicketMatch>&) const override;
    };
}
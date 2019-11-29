#pragma once

#include <include/dllmacro.h>
#include <include/matching/matching_algorithm.hpp>
#include <memory>

using std::unique_ptr;

namespace cti {

    class MatchingAlgorithm;

    class EXPORT MatchingAlgorithms {
    public:
        MatchingAlgorithms();
        static unique_ptr<MatchingAlgorithm> orb(); // TODO: tweak parameter
        static unique_ptr<MatchingAlgorithm> sift(); // TODO: tweak parameter
    };
}
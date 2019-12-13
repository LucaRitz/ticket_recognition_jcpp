#pragma once

#include <include/dllmacro.h>
#include <include/matching/matching_algorithm.hpp>
#include <memory>

using std::unique_ptr;

namespace cti {

    class MatchingAlgorithm;
    class MatchingOptions;

    class EXPORT MatchingAlgorithms {
    public:
        MatchingAlgorithms() = delete;
        static unique_ptr<MatchingAlgorithm> orb(const MatchingOptions& options);
        static unique_ptr<MatchingAlgorithm> sift(const MatchingOptions& options);
    };
}
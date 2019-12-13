#pragma once

#include <include/dllmacro.h>
#include <include/matching/matching_algorithm.hpp>
#include <include/matching/matching_options.hpp>
#include <memory>

using std::unique_ptr;

namespace cti {

    class MatchingAlgorithm;
    class MatchingOptions;

    /**
     * Factory class that provides static methods to instantiate different implementations of MatchingAlgorithm.
     */
    class EXPORT MatchingAlgorithms {
    public:
        MatchingAlgorithms() = delete;

        /**
         * Creates an instance of MatchingAlgorithm that uses ORB (Oriented FAST and Rotated BRIEF) keypoints and descriptors.
         * @return
         */
        static unique_ptr<MatchingAlgorithm> orb(const MatchingOptions& options = MatchingOptions{});

        /**
         * Creates an instance of MatchingAlgorithm that uses SIFT (scale-invariant feature transform) keypoints and descriptors.
         * @return
         */
        static unique_ptr<MatchingAlgorithm> sift(const MatchingOptions& options = MatchingOptions{});
    };
}

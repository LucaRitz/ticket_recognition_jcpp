#pragma once

#include <include/dllmacro.h>
#include <include/extraction/extraction_algorithm.hpp>
#include <include/extraction/extraction_options.hpp>
#include <memory>

using std::unique_ptr;

namespace cti {

    class ExtractionAlgorithm;
    class ExtractionOptions;

    /**
     * Factory class that provides static methods to instantiate different implementations of ExtractionAlgorithm.
     */
    class EXPORT ExtractionAlgorithms {
    public:
        ExtractionAlgorithms();

        /**
         * Creates an instance of ExtractionAlgorithm that uses ORB (Oriented FAST and Rotated BRIEF) keypoints and descriptors.
         * @return
         */
        static unique_ptr<ExtractionAlgorithm> orb(const ExtractionOptions& options = ExtractionOptions {});

        /**
         * Creates an instance of ExtractionAlgorithm that uses SIFT (scale-invariant feature transform) keypoints and descriptors.
         * @return
         */
        static unique_ptr<ExtractionAlgorithm> sift(const ExtractionOptions& options = ExtractionOptions {});
    };
}

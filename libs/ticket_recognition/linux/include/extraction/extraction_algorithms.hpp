#pragma once

#include <include/dllmacro.h>
#include <include/extraction/extraction_algorithm.hpp>
#include <memory>

using std::unique_ptr;

namespace cti {

    class ExtractionAlgorithm;
    class ExtractionOptions;

    class EXPORT ExtractionAlgorithms {
    public:
        ExtractionAlgorithms();
        static unique_ptr<ExtractionAlgorithm> orb(const ExtractionOptions& options);
        static unique_ptr<ExtractionAlgorithm> sift(const ExtractionOptions& options);
    };
}
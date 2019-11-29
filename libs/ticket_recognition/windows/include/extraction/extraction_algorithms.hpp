#pragma once

#include <include/dllmacro.h>
#include <include/extraction/extraction_algorithm.hpp>
#include <memory>

using std::unique_ptr;

namespace cti {

    class ExtractionAlgorithm;

    class EXPORT ExtractionAlgorithms {
    public:
        ExtractionAlgorithms();
        static unique_ptr<ExtractionAlgorithm> orb(); // TODO: tweak parameter
        static unique_ptr<ExtractionAlgorithm> sift(); // TODO: tweak parameter
    };
}
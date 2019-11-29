#pragma once

#include <include/dllmacro.h>
#include "ocr_algorithm.hpp"
#include <string>
#include <memory>

using std::unique_ptr;
using std::string;

namespace cti {

    class OcrAlgorithm;

    class EXPORT OcrAlgorithms {
    public:
        OcrAlgorithms();
        static unique_ptr<OcrAlgorithm> tesseract(const string& language); // TODO: tweak parameter
    };
}
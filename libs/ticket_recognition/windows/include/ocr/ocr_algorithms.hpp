#pragma once

#include <include/dllmacro.h>
#include "ocr_algorithm.hpp"
#include <string>
#include <memory>

using std::unique_ptr;
using std::string;

namespace cti {

    class OcrAlgorithm;

    /**
     * Factory class that provides static methods to instantiate different implementations of OcrAlgorithm.
     */
    class EXPORT OcrAlgorithms {
    public:
        OcrAlgorithms();

        /**
         * Creates an instance of OcrAlgorithm that uses Tesseract OCR.
         * @return
         */
        static unique_ptr<OcrAlgorithm> tesseract(const string& language);
    };
}
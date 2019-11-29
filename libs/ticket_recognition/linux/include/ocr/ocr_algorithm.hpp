#pragma once

#include <include/dllmacro.h>
#include <string>

using std::string;

namespace cti {

    class TicketImage;
    class BoundingBox;

    class EXPORT OcrAlgorithm {
    public:
        virtual string read(const TicketImage& image, const BoundingBox& boundingBox) const = 0;
    };
}
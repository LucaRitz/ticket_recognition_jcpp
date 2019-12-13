#pragma once

#include <include/dllmacro.h>
#include <string>

using std::string;

namespace cti {

    class Ticket;
    class TicketImage;
    class BoundingBox;

    /**
     * Abstract Class describing the API of an OCR-Algorithm usable
     * in combination with an instance of ExtractionAlgorithm.
     */
    class EXPORT OcrAlgorithm {
    public:

        /**
         * Reads the text inside the specified BoundingBox of the specified TicketImage.
         * @param image Image containing the desired text.
         * @param ticket Ticket which the given TicketImage belongs to and which contains the given BoundingBox.
         * @param boundingBox BoundingBox where the desired text is to be found.
         * @return
         */
        virtual string read(const TicketImage& image, const Ticket& ticket, const BoundingBox& boundingBox) const = 0;
    };
}
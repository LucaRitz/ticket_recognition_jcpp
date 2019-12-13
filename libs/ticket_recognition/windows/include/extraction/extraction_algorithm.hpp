#pragma once

#include <include/dllmacro.h>

namespace cti {

    class Ticket;
    class TicketImage;
    class Metadata;

    /**
     * Abstract class describing an algorithm used to extract Metadata
     * from a TicketImage using the Information from a Ticket.
     */
    class EXPORT ExtractionAlgorithm {
    public:

        /**
         * Normalize the given TicketImage to match the rotation and scale of the Ticket's image.
         * @return
         */
        virtual TicketImage* normalize(const Ticket& ticket, const TicketImage& ticketImage) const = 0;

        /**
         * Read all Metadata from the given TicketImage which are specified in the given Ticket.
         * @return
         */
        virtual Metadata read(const Ticket&, TicketImage&) const = 0;
    };
}

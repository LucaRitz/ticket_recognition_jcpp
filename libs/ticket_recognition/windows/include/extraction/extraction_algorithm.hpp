#pragma once

#include <include/dllmacro.h>

namespace cti {

    class Ticket;
    class TicketImage;
    class Metadata;

    class EXPORT ExtractionAlgorithm {
    public:
        virtual TicketImage* normalize(const Ticket&, const TicketImage&) const = 0;
        virtual Metadata* read(const Ticket&, TicketImage&) const = 0;
    };
}
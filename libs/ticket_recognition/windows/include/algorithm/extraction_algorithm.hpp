#pragma once

#include <include/dllmacro.h>

namespace cti {

    class Ticket;
    class TicketImage;
    class Metadata;

    class EXPORT ExtractionAlgorithm {
    public:
        virtual void normalize(const Ticket&, TicketImage&) const = 0;
        virtual Metadata* read(const Ticket&, TicketImage&) const = 0;
    };
}
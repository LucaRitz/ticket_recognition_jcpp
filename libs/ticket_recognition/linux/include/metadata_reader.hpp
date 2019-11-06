#pragma once

#include "dllmacro.h"

namespace cti {
    class TicketImage;
    class Metadata;
    class Ticket;
    class ExtractionAlgorithm;

    class EXPORT MetadataReader {
    public:
        explicit MetadataReader(const ExtractionAlgorithm&);
        MetadataReader(const MetadataReader&) = delete;
        MetadataReader(MetadataReader&&) = delete;
        MetadataReader& operator=(const MetadataReader&) = delete;
        MetadataReader& operator=(MetadataReader&&) = delete;

        const Metadata* const read(const Ticket&, TicketImage&);
    };
}
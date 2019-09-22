#pragma once

#include "dllmacro.h"

namespace cti {
    class TicketImage;
    class TicketMetadata;
    class Metadata;

    class EXPORT MetadataReader {
            public:
            MetadataReader(const MetadataReader& other) = delete;
            MetadataReader(MetadataReader&& other) = delete;
            MetadataReader& operator=(const MetadataReader& other) = delete;
            MetadataReader& operator=(MetadataReader&& other) = delete;

            virtual const Metadata* const read(const TicketImage& image, const TicketMetadata& metadata) = 0;
    };
}
#pragma once

#include <include/dllmacro.h>
#include <include/algorithm/extraction_algorithm.hpp>

namespace cti {

    class EXPORT SiftExtractionAlgorithm : public ExtractionAlgorithm {
    public:
        cti::TicketImage* normalize(const Ticket&, TicketImage&) const override;
        Metadata* read(const Ticket&, TicketImage&) const override;
    };
}
#pragma once

#include "dllmacro.h"
#include <include/metadata.hpp>

namespace cti {

    class TicketImage;
    class Ticket;
    class ExtractionAlgorithm;

    /**
     * Provides the ability to read all Metadata located on a ticket to be processed, provided as a TicketImage,
     * and a Ticket that describes the kind of ticket and what kind of Metadata can be found.
     * It makes sense to use this in combination with a Matcher, after matching a Ticket using a TicketImage, the
     * Metadata can be read out using this class.
     */
    class EXPORT MetadataReader {
    public:

        /**
         * Constructs a MetadataReader using a given implementation of a ExtractionAlgorithm.
         * @param extractionAlgorithm Algorithm used for Metadata extraction. Can be constructed using factory methods on class ExtractionAlgorithms.
         */
        explicit MetadataReader(const ExtractionAlgorithm& extractionAlgorithm);

        MetadataReader(const MetadataReader&) = delete;
        MetadataReader(MetadataReader&&) = delete;
        MetadataReader& operator=(const MetadataReader&) = delete;
        MetadataReader& operator=(MetadataReader&&) = delete;

        /**
         * Read as much Metadata as possible located on the given TicketImage, defined in the given Ticket.
         * This uses the ExtractionAlgorithm provided at construction of this class.
         * @return a pointer to a dynamically allocated instance of Metadata.
         */
        const Metadata read(const Ticket&, const TicketImage&) const;

    private:
        const ExtractionAlgorithm& _algorithm;
    };
}

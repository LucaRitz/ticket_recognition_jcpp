#pragma once

#include "dllmacro.h"
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace cti {

    /**
     * Metadata found on a ticket to be processed. This is the result of a MetadataReader.
     */
    class EXPORT Metadata {
    public:

        /**
         * Construct a Metadata object from a map of texts found on a ticket.
         * @param texts Map of texts found on a ticket. The key is the Text's key property, the value is the text recognized by OCR.
         */
        explicit Metadata(const unordered_map<string, string> texts);

        Metadata(const Metadata&) = default;
        Metadata(Metadata&&) = default;
        Metadata& operator=(const Metadata&) = delete;
        Metadata& operator=(Metadata&&) = delete;

        /**
         * Map of texts found on a ticket. The key is the Text's key property, the value is the text recognized by OCR.
         * @return
         */
        const unordered_map<string, string>& texts() const;

    private:
        const unordered_map<string, string> _texts;
    };
}

#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {

    class BoundingBox;

    /**
     * Definition of a text that is to be found on a Ticket inside a specified BoundingBox.
     */
    class EXPORT Text {
    public:
        /**
         * Construct a Text.
         * @param key Identification of the Text. Must be unique for a single Ticket.
         * @param boundingBox BoundingBox where the Text is to be found on a Ticket.
         */
        Text(string key, BoundingBox& boundingBox);
        Text(const Text&) = delete;
        Text(Text&&) = delete;
        Text& operator=(const Text&) = delete;
        Text& operator=(Text&&) = delete;

        /**
         * Identification of the Text. Must be unique for a single Ticket.
         * @return
         */
        const string key() const;

        /**
         * BoundingBox where the Text is to be found on a Ticket.
         * @return
         */
        const BoundingBox& boundingBox() const;

    private:
        const string _key;
        const BoundingBox& _boundingBox;
    };

}
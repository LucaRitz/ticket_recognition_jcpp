#pragma once

#include "dllmacro.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace cti {

    class Text;
    class TicketImage;
    class BoundingBox;

    /**
     * Template of a ticket to be processed. It describes how one kind of ticket may look, using a TicketImage,
     * and which Text's are to be found in which BoundingBoxes of the TicketImage.
     * It is used to train a MatchingAlgorithm or a Matcher before matching a TicketImage of a ticket to be processed.
     * It is used to read the Texts from a TicketImage of a ticket to be processed using
     * a ExtractionAlgorithm or a MetadataReader.
     * It must be uniquely identifiable among a set of Ticket's using a name.
     */
    class EXPORT Ticket {
    public:

        /**
         * Constructs a Ticket.
         * @param name Identification of a Ticket. Must be unique among a set of Tickets.
         * @param image Image of the Ticket used as a reference in the matching phase.
         * @param texts Set of Texts that can be found in a TicketImage if it is an image of this Ticket.
         */
        Ticket(string name, const TicketImage& image, vector<const Text*>& texts) noexcept(false);

        Ticket(const Ticket& other) = delete;
        Ticket(Ticket&& other) = delete;
        Ticket& operator=(const Ticket& other) = delete;
        Ticket& operator=(Ticket&& other) = delete;

        /**
         * Identification of a Ticket. Must be unique among a set of Tickets.
         * @return
         */
        const string name() const;

        /**
         * Image of the Ticket used as a reference in the matching phase.
         * @return
         */
        const TicketImage& image() const;

        /**
         * Set of Texts that can be found in a TicketImage if it is an image of this Ticket.
         * @return
         */
        const vector<const Text*>& texts() const;

    private:
        const string _name;
        const TicketImage& _image;
        const vector<const Text*>& _texts;
    };
}

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

    class EXPORT Ticket {
    public:
        Ticket(string, const TicketImage&, vector<const Text*>&);
        Ticket(string, const TicketImage&, vector<const Text*>&, vector<const BoundingBox*>&);

        Ticket(const Ticket& other) = delete;
        Ticket(Ticket&& other) = delete;
        Ticket& operator=(const Ticket& other) = delete;
        Ticket& operator=(Ticket&& other) = delete;

        const string name();
        const TicketImage& image() const;
        const vector<const Text*>& texts() const;
        const vector<const BoundingBox*>& matchingAreas() const;

    private:
        const string _name;
        const TicketImage& _image;
        const vector<const Text*>& _texts;
        const vector<const BoundingBox*>& _matchingAreas;
    };
}

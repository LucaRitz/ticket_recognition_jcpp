#pragma once

#include "dllmacro.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace cti {
    class Text;

    class EXPORT TicketMetadata {
            public:
            TicketMetadata(string name, vector<const Text>& texts) : name(name), texts(texts) {}
            TicketMetadata(const TicketMetadata& other) = delete;
            TicketMetadata(TicketMetadata&& other) = delete;
            TicketMetadata& operator=(const TicketMetadata& other) = delete;
            TicketMetadata& operator=(TicketMetadata&& other) = delete;
            const vector<const Text>& getTexts() const {
                return texts;
            }

            private:
            const string name;
            const vector<const Text>& texts;
    };
}
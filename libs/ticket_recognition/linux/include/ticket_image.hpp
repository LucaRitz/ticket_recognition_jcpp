#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {
    class EXPORT TicketImage {
    public:
        explicit TicketImage(const string&);
        TicketImage(const int, const int, const int, const int, unsigned char*);
        TicketImage(const TicketImage&) = delete;
        TicketImage(TicketImage&&) = delete;
        TicketImage &operator=(const TicketImage&) = delete;
        TicketImage &operator=(TicketImage&&) = delete;

        const int width() const;
        const int height() const;
        const int bytesPerPixel() const;
        const int bytesPerLine() const;
        unsigned char *image() const;
    };
}
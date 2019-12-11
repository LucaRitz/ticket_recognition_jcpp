#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {
    class EXPORT TicketImage {
    public:
        explicit TicketImage(const string&) noexcept(false);
        TicketImage(const int, const int, const int, const size_t, unsigned char*) noexcept(false);
        TicketImage(const TicketImage&) = delete;
        TicketImage(TicketImage&&) = delete;
        TicketImage &operator=(const TicketImage&) = delete;
        TicketImage &operator=(TicketImage&&) = delete;

        const int width() const;
        const int height() const;
        const int bytesPerPixel() const;
        const size_t bytesPerLine() const;
        unsigned char *image() const;

    private:
        int _width;
        int _height;
        int _bytes_per_pixel;
        size_t _bytes_per_line;
        unsigned char* _image;
    };
}
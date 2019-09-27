#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {
    class EXPORT TicketImage {
    public:
        TicketImage(string);
        TicketImage(const int width, const int height, const int bytes_per_pixel, const int bytes_per_line, char *image)
                : _width(width), _height(height), _bytes_per_pixel(bytes_per_pixel), _bytes_per_line(bytes_per_line),
                  _image(image) {}
        TicketImage(const TicketImage&) = delete;
        TicketImage(TicketImage&&) = delete;
        TicketImage &operator=(const TicketImage&) = delete;
        TicketImage &operator=(TicketImage&&) = delete;

        const int width() const {
            return _width;
        }

        const int height() const {
            return _height;
        }

        const int bytesPerPixel() const {
            return _bytes_per_pixel;
        }

        const int bytesPerLine() const {
            return _bytes_per_line;
        }

        char *image() {
            return _image;
        }

    private:
        const int _width;
        const int _height;
        const int _bytes_per_pixel;
        const int _bytes_per_line;
        char *_image;
    };
}
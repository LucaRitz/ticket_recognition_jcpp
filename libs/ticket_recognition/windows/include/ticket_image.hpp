#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {

    /**
     * Image of a concrete ticket to be processed or the template image of a Ticket.
     */
    class EXPORT TicketImage {
    public:

        /**
         * Construct a TicketImage from a filepath pointing to an image file.
         * @param imageFilePath
         * @throw CtiException if the image at the given filepath could not be loaded.
         */
        explicit TicketImage(const string& imageFilePath) noexcept(false);

        /**
         * Construct a TicketImage from an already loaded image.
         * @param width image width in pixel.
         * @param height image height in pixel.
         * @param bytesPerPixel number of bytes required for each pixel. E.g. RGB requires 3 bytes per pixel, while RGBA requires 4 bytes per pixel.
         * @param bytesPerLine number of bytes per line (Number of bytes per pixel * Image width).
         * @param image pointer to the image data.
         * @throw CtiException if the provided information is invalid, like width=0.
         */
        TicketImage(const int width, const int height, const int bytesPerPixel, const size_t bytesPerLine, unsigned char* image) noexcept(false);

        TicketImage(const TicketImage&) = delete;
        TicketImage(TicketImage&&) = delete;
        TicketImage &operator=(const TicketImage&) = delete;
        TicketImage &operator=(TicketImage&&) = delete;
        ~TicketImage();

        /**
         * Image width in pixel.
         * @return
         */
        int width() const;

        /**
         * Image height in pixel.
         * @return
         */
        int height() const;

        /**
         * Number of bytes required for each pixel.
         * E.g. RGB requires 3 bytes per pixel, while RGBA requires 4 bytes per pixel.
         * @return
         */
        int bytesPerPixel() const;

        /**
         * Number of bytes per line (Number of bytes per pixel * Image width).
         * @return
         */
        size_t bytesPerLine() const;

        /**
         * Pointer to the image data.
         * @return
         */
        unsigned char* image() const;

    private:
        int _width;
        int _height;
        int _bytes_per_pixel;
        size_t _bytes_per_line;
        unsigned char* _image;
    };
}
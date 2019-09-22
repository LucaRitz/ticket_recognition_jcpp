#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {
    class EXPORT TicketImage {
            public:
            TicketImage(string imageFilePath) {} // TODO: implement
            TicketImage(int width, int height, int bytes_per_pixel, int bytes_per_line) {} // TODO: implement
            TicketImage(const TicketImage& other) = delete;
            TicketImage(TicketImage&& other) = delete;
            TicketImage& operator=(const TicketImage& other) = delete;
            TicketImage& operator=(TicketImage&& other) = delete;

            private:
            // TODO: internal structure?
    };
}
#pragma once

#include "dllmacro.h"

namespace cti {
    class TicketMatch;
    class TicketImage;

    class EXPORT Matcher {
            public:
            Matcher(const Matcher& other) = delete;
            Matcher(Matcher&& other) = delete;
            Matcher& operator=(const Matcher& other) = delete;
            Matcher& operator=(Matcher&& other) = delete;

            virtual TicketMatch* match(const TicketImage& image) = 0;
    };
}
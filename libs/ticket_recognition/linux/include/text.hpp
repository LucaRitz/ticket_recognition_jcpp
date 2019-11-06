#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {

    class BoundingBox;

    class EXPORT Text {
    public:
        Text(string, BoundingBox&);
        Text(const Text&) = delete;
        Text(Text&&) = delete;
        Text& operator=(const Text&) = delete;
        Text& operator=(Text&&) = delete;

        const string key() const;
        const BoundingBox& boundingBox() const;
    };

}
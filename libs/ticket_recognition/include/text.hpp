#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {

    class BoundingBox;

    class EXPORT Text {
            public:
            Text(string key, BoundingBox& boundingBox) : key(key), boundingBox(boundingBox) {}
            Text(const Text& other) = delete;
            Text(Text&& other) = delete;
            Text& operator=(const Text& other) = delete;
            Text& operator=(Text&& other) = delete;

            private:
            const string key;
            const BoundingBox& boundingBox;
    };

}
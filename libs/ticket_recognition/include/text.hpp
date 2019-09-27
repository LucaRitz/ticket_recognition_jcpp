#pragma once

#include "dllmacro.h"
#include <string>

using std::string;

namespace cti {

    class BoundingBox;

    class EXPORT Text {
    public:
        Text(string key, BoundingBox& boundingBox) : _key(std::move(key)), _boundingBox(boundingBox) {}
        Text(const Text&) = delete;
        Text(Text&&) = delete;
        Text& operator=(const Text&) = delete;
        Text& operator=(Text&&) = delete;

        const string key() const {
            return _key;
        }

        const BoundingBox& boundingBox() const {
            return _boundingBox;
        }

    private:
        const string _key;
        const BoundingBox& _boundingBox;
    };

}
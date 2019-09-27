#pragma once

#include "dllmacro.h"
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace cti {

    class EXPORT Metadata {
    public:
        Metadata(const unordered_map<string, string> texts) : _texts(texts) {}
        const unordered_map<string, string>& texts() const {
            return _texts;
        }

    private:
        const unordered_map<string, string> _texts;
    };
}
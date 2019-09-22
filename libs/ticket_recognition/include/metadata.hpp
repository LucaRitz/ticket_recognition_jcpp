#pragma once

#include "dllmacro.h"
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace cti {
    class EXPORT Metadata {
            public:
            const unordered_map<const string, const string>& getTexts() const {
                return texts;
            }
            private:
            const unordered_map<const string, const string>& texts;
    };
}
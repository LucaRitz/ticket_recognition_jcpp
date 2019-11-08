#pragma once

#include "dllmacro.h"
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace cti {

    class EXPORT Metadata {
    public:
        explicit Metadata(const unordered_map<string, string>);
        const unordered_map<string, string>& texts() const;

    private:
        const unordered_map<string, string> _texts;
    };
}
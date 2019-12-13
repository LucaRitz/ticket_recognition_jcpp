#pragma once

#include <include/dllmacro.h>
#include <string>

namespace cti {
    class EXPORT ExtractionOptions {
    public:
        explicit ExtractionOptions(double ratioTestThreshold = 0.7, std::string language = std::string("eng"));

        double ratioTestThreshold() const;
        const std::string& language() const;

    private:
        double _ratioTestThreshold;
        const std::string _language;
    };
}
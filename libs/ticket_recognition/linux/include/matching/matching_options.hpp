#pragma once

#include <include/dllmacro.h>

namespace cti {

    class EXPORT MatchingOptions {
    public:
        explicit MatchingOptions(double ratioTestThreshold = 0.7, double scoreTestThreshold = 0.5,
                                 double scoreThreshold = 25.0);

        double ratioTestThreshold() const;
        double scoreTestThreshold() const;
        double scoreThreshold() const;

    private:
        double _ratioTestThreshold;
        double _scoreTestThreshold;
        double _scoreThreshold;
    };
}
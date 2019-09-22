#pragma once

#include "dllmacro.h"
#include <vector>
#include <string>

using std::vector;

namespace cti {
    class Matcher;
    class Ticket;

    /**
     * This class represents the library entrypoint.
     */
    class EXPORT Cti {
    public:
        Cti(){}
        Cti(const Cti& other) = delete;
        Cti(Cti&& other) = delete;
        Cti& operator=(const Cti& other) = delete;
        Cti& operator=(Cti&& other) = delete;

    public:
        const Matcher* const train(const vector<const Ticket>& tickets) const;
        void hello(char*) const;
        std::string helloWorld() const;
        // TODO: possibly a learn method that takes an existing matcher and a vector of tickets to train additional tickets?
    };
}
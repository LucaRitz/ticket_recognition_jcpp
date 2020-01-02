#pragma once

#include <exception>
#include <string>
#include <include/dllmacro.h>

namespace cti {

    class EXPORT CtiException : public std::exception {
    public:
        explicit CtiException(std::string message);

        const char* what() const noexcept override;

    private:
        const std::string _message;
    };
}
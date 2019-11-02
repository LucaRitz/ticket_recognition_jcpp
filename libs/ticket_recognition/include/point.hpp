#pragma once

#include "dllmacro.h"

namespace cti {
    class EXPORT Point {
    public:
        Point(int, int);
        Point(const Point&) = delete;
        Point(Point&&) = delete;
        Point& operator=(const Point&) = delete;
        Point& operator=(Point&&) = delete;

        const int x() const;
        const int y() const;

    private:
        const int _x;
        const int _y;
    };
}
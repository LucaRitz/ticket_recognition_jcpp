#pragma once

#include "dllmacro.h"

namespace cti {
    class EXPORT Point {
    public:
        Point(int x, int y) : _x(x), _y(y) {}
        Point(const Point&) = delete;
        Point(Point&&) = delete;
        Point& operator=(const Point&) = delete;
        Point& operator=(Point&&) = delete;

        const int x() const {
            return _x;
        }

        const int y() const {
            return _y;
        }

    private:
        const int _x;
        const int _y;
    };
}
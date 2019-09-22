#pragma once

#include "dllmacro.h"

namespace cti {
    class EXPORT Point {
            public:
            Point(int x, int y) : x(x), y(y) {}
            Point(const Point& other) = delete;
            Point(Point&& other) = delete;
            Point& operator=(const Point& other) = delete;
            Point& operator=(Point&& other) = delete;

            private:
            const int x;
            const int y;
    };
}
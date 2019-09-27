#pragma once

#include "dllmacro.h"

namespace cti {
    class Point;

    class EXPORT BoundingBox {
            public:
            BoundingBox(Point& topLeft, Point& bottomRight) : _topLeft(topLeft), _bottomRight(bottomRight) {}
            BoundingBox(const BoundingBox&) = delete;
            BoundingBox(BoundingBox&&) = delete;
            BoundingBox& operator=(const BoundingBox&) = delete;
            BoundingBox& operator=(BoundingBox&&) = delete;

            const Point& topLeft() const {
                return _topLeft;
            }

            const Point& bottomRight() const {
                return _bottomRight;
            }

            private:
            const Point& _topLeft;
            const Point& _bottomRight;
    };
}
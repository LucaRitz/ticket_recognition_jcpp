#pragma once

#include "dllmacro.h"

namespace cti {
    class Point;

    class EXPORT BoundingBox {
            public:
            BoundingBox(Point& topLeft, Point& bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {}
            BoundingBox(const BoundingBox& other) = delete;
            BoundingBox(BoundingBox&& other) = delete;
            BoundingBox& operator=(const BoundingBox& other) = delete;
            BoundingBox& operator=(BoundingBox&& other) = delete;

            private:
            const Point& topLeft;
            const Point& bottomRight;
    };
}
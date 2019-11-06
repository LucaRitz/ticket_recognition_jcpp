#pragma once

#include "dllmacro.h"

namespace cti {
    class Point;

    class EXPORT BoundingBox {
            public:
            BoundingBox(Point&, Point&);
            BoundingBox(const BoundingBox&) = delete;
            BoundingBox(BoundingBox&&) = delete;
            BoundingBox& operator=(const BoundingBox&) = delete;
            BoundingBox& operator=(BoundingBox&&) = delete;

            const Point& topLeft() const;
            const Point& bottomRight() const;
    };
}
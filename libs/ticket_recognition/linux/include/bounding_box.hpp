#pragma once

#include "dllmacro.h"

namespace cti {
    class Point;

    class EXPORT BoundingBox {
            public:
            BoundingBox(const Point&, const Point&);
            BoundingBox(const BoundingBox&) = default;
            BoundingBox(BoundingBox&&) = delete;
            BoundingBox& operator=(const BoundingBox&) = delete;
            BoundingBox& operator=(BoundingBox&&) = delete;

            const Point& topLeft() const;
            const Point& bottomRight() const;

            private:
            const Point& _topLeft;
            const Point& _bottomRight;
    };
}
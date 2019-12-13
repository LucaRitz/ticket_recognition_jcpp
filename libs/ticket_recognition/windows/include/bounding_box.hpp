#pragma once

#include "dllmacro.h"
#include <include/point.hpp>

namespace cti {

    /**
     * Rectangular bounding box on a TicketImage.
     */
    class EXPORT BoundingBox {
    public:

        /**
         * Constructs a BoundingBox limited by the given top-left and bottom-right corner coordinates.
         * @param topLeft Point/Coordinate of the top-left corner.
         * @param bottomRight Point/Coordinate of the bottom-right corner.
         */
        BoundingBox(Point topLeft, Point bottomRight) noexcept(false);

        BoundingBox(const BoundingBox&) = default;
        BoundingBox(BoundingBox&&) = delete;
        BoundingBox& operator=(const BoundingBox&) = delete;
        BoundingBox& operator=(BoundingBox&&) = delete;

        /**
         * Point of the top-left corner.
         * @return
         */
        const Point& topLeft() const;

        /**
         * Point of the bottom-right corner.
         * @return
         */
        const Point& bottomRight() const;

    private:
        const Point _topLeft;
        const Point _bottomRight;
    };
}

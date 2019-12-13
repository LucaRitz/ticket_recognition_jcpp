#pragma once

#include "dllmacro.h"

namespace cti {

    /**
     * Two-dimensional Point on a TicketImage.
     */
    class EXPORT Point {
    public:

        /**
         * Constructs a Point.
         * @param x X-Coordinate of the Point.
         * @param y Y-Coordinate of the Point.
         */
        Point(int x, int y);

        Point(const Point&) = default;
        Point(Point&&) = default;
        Point& operator=(const Point&) = delete;
        Point& operator=(Point&&) = delete;

        /**
         * X-Coordinate of the Point.
         * @return
         */
        const int x() const;

        /**
         * Y-Coordinate of the Point.
         * @return
         */
        const int y() const;

    private:
        const int _x;
        const int _y;
    };
}
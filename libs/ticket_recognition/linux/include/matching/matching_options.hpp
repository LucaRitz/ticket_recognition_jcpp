#pragma once

#include <include/dllmacro.h>

namespace cti {

    /**
     * Available options for matching. These are used in the static factory methods in MatchingAlgorithms.
     */
    class EXPORT MatchingOptions {
    public:

        /**
         * Constructs options with the given values.
         * @param ratioTestThreshold Required distance ratio between nearest and second nearest neighbour of a keypoint when matching.
         * @param scoreTestThreshold Required score ratio between best and second best TicketMatch in order for the best match to be confirmed.
         * @param scoreThreshold Minimum score required for a TicketMatch to be considered.
         */
        explicit MatchingOptions(double ratioTestThreshold = 0.7, double scoreTestThreshold = 0.5,
                                 double scoreThreshold = 25.0);

        /**
         * Required distance ratio between nearest and second nearest neighbour of a keypoint when matching.
         * A better and more elaborate description can be found in David G. Lowe's paper
         * "Distinctive Image Features from Scale-Invariant Keypoints".
         * @return
         */
        double ratioTestThreshold() const;

        /**
         * Required score ratio between best and second best TicketMatch in order for the best match to be confirmed.
         * E.g. a value of 0.5 means that the best match must have a score that is 2x higher
         * than the second best matches score.
         * @return
         */
        double scoreTestThreshold() const;

        /**
         * Minimum score required for a TicketMatch to be considered. Any TicketMatch with a score lower than
         * this threshold is discarded. This is important in order for situations where an unknown ticket is provided
         * and there is no trained Ticket that matches, although some of them may be considered matches by the algorithm.
         * @return
         */
        double scoreThreshold() const;

    private:
        double _ratioTestThreshold;
        double _scoreTestThreshold;
        double _scoreThreshold;
    };
}
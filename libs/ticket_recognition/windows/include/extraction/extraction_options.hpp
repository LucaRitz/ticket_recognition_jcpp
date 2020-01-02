#pragma once

#include <include/dllmacro.h>
#include <string>

namespace cti {

    /**
     * Available options for extraction. These are used in the static factory methods in ExtractionAlgorithms.
     */
    class EXPORT ExtractionOptions {
    public:

        /**
         * Constructs options with the given values.
         * @param ratioTestThreshold Required distance ratio between nearest and second nearest neighbour of a keypoint when matching.
         * @param language Tesseract language file(s) to be used. Multiple files can be concatenated by a "+", like "deu+eng".
         */
        explicit ExtractionOptions(double ratioTestThreshold = 0.7, std::string language = std::string("eng"));

        /**
         * Required distance ratio between nearest and second nearest neighbour of a keypoint when matching.
         * A better and more elaborate description can be found in David G. Lowe's paper
         * "Distinctive Image Features from Scale-Invariant Keypoints".
         * @return
         */
        double ratioTestThreshold() const;

        /**
         * Tesseract language file(s) to be used. Multiple files can be concatenated by a "+", like "deu+eng"
         * @return
         */
        const std::string& language() const;

    private:
        double _ratioTestThreshold;
        const std::string _language;
    };
}
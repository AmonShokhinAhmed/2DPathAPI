#pragma once
namespace PathAPI {
    /// Simple two dimensional vector class.
    /**
     * Stores x and y coordinates. Allows simple use of vector math.
     */
    /// \todo Math operations
    class Vector2 {
      public:
        /// Constructor using it's coordinates
        /**
         * @param[in] x - The value the x coordinate will be set to.
         * @param[in] y - The value the y coordinate will be set to.
         */
        Vector2(float x, float y);
        /// Constructor setting both coordinates to the same value
        /**
         * @param[in] value - The value both coordinates will be set to.
         */
        Vector2(float value);
        /// Default constructor, intializes both coordinates to zero
        Vector2();
        float x;
        float y;
    };
} // namespace PathAPI
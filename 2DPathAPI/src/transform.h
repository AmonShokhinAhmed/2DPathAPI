#pragma once
#include "vector2.h"
namespace PathAPI {
    /// Transform class for use with every object in a scene
    /**
     * Stores the position, the scale and the rotation of the object. Provides simple ways to
     * manipulate those values.
     */
    /// \todo Add utility functions
    class Transform {
      public:
        /// Default constructor, initilazing Position to (0,0), Scale to (1,1) and Rotation to 0;
        Transform();
        /// Constructor taking already definied Positon, Scale and Rotation
        /**
         * @param[in] position - the value Position will be set to
         * @param[in] scale - the value Scale will be set to
         * @param[in] rotation - the value Rotation will be set to
         */
        Transform(const Vector2 &position, const Vector2 &scale, float rotation);
        /// Position of the object
        Vector2 Position;
        /// Scale of the object
        Vector2 Scale;
        /// Rotation of the object in degrees
        float Rotation;
    };
} // namespace PathAPI
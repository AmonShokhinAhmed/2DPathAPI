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
        /// Position of the object
        Vector2 Position;
        /// Scale of the object
        Vector2 Scale;
        /// Rotation of the object in degrees
        float Rotation;
    };
} // namespace PathAPI
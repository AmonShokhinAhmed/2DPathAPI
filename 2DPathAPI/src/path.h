#pragma once
#include "node.h"
#include <vector>
/// The namespace for the whole 2DPathAPI project.
namespace PathAPI {
    class Path {
      public:
        /// Constructor building the path from an ordered list of positions
        /**
         * The passed vector has to have it's position in the orderer we want the path to be
         * travelled in. As the positions can't contain every possible step the user would want to
         * know about, they should only feature points where the path changes direction, as every
         * other point can be interpolated
         */
        Path(const std::vector<Vector2> &positions);
        /// Gets the next position on the path.
        /**
         * @param[in] stepSize - how far we want to travel (can also be negative)
         * @param[out] nextPosition - the position we traveled to on the path
         * @return whether we reached the end of the path
         */
        bool GetNextPosition(float stepSize, Vector2 &nextPosition);
        /// Gets the position on the path determined by the normalized position value
        /**
         * @param[in] position - the normalized position value. This means that a value of 0 denotes
         * the beginning of the path while 1 corresponds to the end.
         */
        Vector2 GetPositionOnPath(float position);
        /// Sets the current position on the path to the normalized position value
        /**
         * @param[in] position - the normalized position value. This means that a value of 0 denotes
         * the beginning of the path while 1 corresponds to the end.
         */
        void SetCurrentPosition(float position);

      private:
        /// index of the current position in the positions vector
        int currentPosition;
        /// distance we have currently travelled between currentPosition and the following index
        float distanceTraveled;
        /// stores the positions the path consists of
        std::vector<Vector2> positions;
    };
} // namespace PathAPI
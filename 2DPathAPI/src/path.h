#pragma once
#include "node.h"
#include <vector>
namespace PathAPI {
    class Path {
      public:
        /// Gets the next position on the path.
        /**
         * @param[in] stepSize - how far we want to travel (can also be negative) from the previous
         * position
         * @param[out] endofPath - true when we reached the end of the path (meaning either end or
         * start of path depending on the sign of stepSize)
         * @return the position we traveled to
         */
        Vector2 GetNextPosition(float stepSize, bool &endofPath);
        /// Gets the current position on the path
        /**
         * @return returns the current position on the path, determined by the distance travelled
         * using GetNextPosition
         */
        Vector2 GetCurrentPosition();
        /// Gets the current normalized position value on the path
        /**
         * @return returns the current normalized position on the path, determined by the distance
         * travelled using GetNextPosition. The value is between 0 and 1, where 0 is the start of
         * the path and 1 the end.
         */
        float GetCurrentNormalizedPosition();
        /// Gets the position on the path determined by the normalized position value
        /**
         * @param[in] position - the normalized position value. This means that a value of 0 denotes
         * the beginning of the path while 1 corresponds to the end. This value is clamped between 0
         * and 1.
         * @return the queried position
         */
        Vector2 GetPositionOnPath(float position);
        /// Sets the current position on the path to the normalized position value
        /**
         * @param[in] position - the normalized position value. This means that a value of 0 denotes
         * the beginning of the path while 1 corresponds to the end. This value is clamped between 0
         * and 1.
         */
        void SetCurrentPosition(float position);

      private:
        /// Constructor building the path from an ordered list of positions
        /**
         * The passed vector has to have it's position in the orderer we want the path to be
         * travelled in. As the positions can't contain every possible step the user would want to
         * know about, they should only feature points where the path changes direction, as every
         * other point can be interpolated.
         * This is private because only Pathfinder needs to be able to create a Path.
         * @param[in] positions - the positions the path consists of
         */
        Path(const std::vector<Vector2> &positions);
        /// index of the current position in the positions vector
        int currentPosition;
        /// distance we have currently travelled between currentPosition and the following index
        float distanceTraveled;
        /// stores the positions the path consists of
        std::vector<Vector2> positions;

        // Declaring PathFinder::createPath as a friend so it has access to the private constructor
        friend Path PathFinder::createPath(const std::vector<Vector2> &positions);
    };
} // namespace PathAPI
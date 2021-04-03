#pragma once
#include "navmesh.h"
#include "path.h"
#include <vector>
namespace PathAPI {
    class Node;
    /// The heart of the PathAPI, that should find the path for the user.
    /**
     * This class handles the pathfinding. To do that it uses a user created navmesh.
     */
    class PathFinder {
      public:
        /// Constructor using a navmesh
        /**
         * The only way the pathfinder makes sense in combination with a navmesh so no other
         * constructor is available.
         */
        PathFinder(const Navmesh &navmesh);
        /// Finds a path as fast as possible
        /**
         * @param[in] start - Start position of the path
         * @param[in] end - End position of the path
         * @param[out] pathFound - returns false if no possible path was found
         * @return A Path object, that allows the user use the found path.
         */
        Path FindFastPath(const Vector2 &start, const Vector2 &end, bool &pathFound);
        /// Finds the best possible path
        /**
         * @param[in] start - Start position of the path
         * @param[in] end - End position of the path
         * @param[out] pathFound - returns false if no possible path was found
         * @return A Path object, that allows the user use the found path.
         */
        Path FindOptimizedPath(const Vector2 &start, const Vector2 &end, bool &pathFound);
        /// Finds a path as fast as possible using all passed positions
        /**
         * @param[in] position - Positions the path has to travel through, starting at index 0 and
         * ending at the last index in the vector.
         * @param[out] pathFound - returns false if no possible path was found
         * @return A Path object, that allows the user use the found path.
         */
        Path FindFastPath(const std::vector<Vector2> &positions, bool &pathFound);
        /// Finds the best possible path using all passed positions
        /**
         * @param[in] position - Positions the path has to travel through, starting at index 0 and
         * ending at the last index in the vector.
         * @param[out] pathFound - returns false if no possible path was found
         * @return A Path object, that allows the user use the found path.
         */
        Path FindOptimizedPath(const std::vector<Vector2> &, bool &pathFound);

      private:
        /// function is used by all Find*Path methods to create the path.
        /**
         * This is a friend function of path, so we can access the private constructor
         */
        Path createPath(const std::vector<Vector2> &positions);
        /// The navmesh the pathfinder uses
        const Navmesh Navmesh;
    };
} // namespace PathAPI

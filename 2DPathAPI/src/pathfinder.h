#pragma once
#include "navmesh.h"
#include "path.h"
#include <vector>
/// The namespace for the whole 2DPathAPI project.
namespace PathAPI {
    class Node;
    /// The heart of the PathAPI, that should find the path for the user.
    /**
     * This class handles pretty much everything the user wants from the PathAPI.
     */
    class PathFinder {
      public:
        /// Default Constructor
        PathFinder(Navmesh navmesh);
        Path FindFastPath();
        Path FindOptimizedPath();

      private:
        Navmesh navmesh;
    };
} // namespace PathAPI

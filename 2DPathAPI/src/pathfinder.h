#pragma once

/// The namespace for the whole 2DPathAPI project.
namespace PathAPI {
/// The heart of the PathAPI, that should find the path for the user.
/**
 * This class handles pretty much everything the user wants from the PathAPI.
 */
class PathFinder {
  public:
    /// Default Constructor
    /**
     * Will probably be replaced soon
     */
    PathFinder();
    /// Only simple test function
    /**
     * This was only created so I could check that the intial project setup worked correctly.
     *
     * @return always returns 0
     */
    int TestFunction();
};
} // namespace PathAPI

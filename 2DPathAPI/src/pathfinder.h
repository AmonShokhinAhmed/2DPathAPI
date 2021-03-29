#pragma once
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
    /**
     * Will probably be replaced soon
     */
    PathFinder();
    /// Adding a node to the pathfinders current map.
    /**
     * This is the only way a node can be created. Because creating a node in a vacuum does not make
     * any sense. It also ensures that the node gets the correct id value.
     */
    Node *AddNode(const std::vector<uint32_t> &connections);

    /// Gets a node from the map corresponding to the id
    Node *GetNode(uint32_t id);
    /// Getter for the size of the Map
    uint32_t GetMapSize();

  private:
    std::vector<Node *> map;
};
} // namespace PathAPI

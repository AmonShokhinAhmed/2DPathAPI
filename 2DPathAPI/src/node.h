#pragma once
#include "pathfinder.h"
#include <vector>
namespace PathAPI {
class Node {
  public:
    /// Getter for the node's id.
    int GetId();
    /// Getter for the node's connections
    const std::vector<uint32_t> &GetConnections();

  private:
    /// Holds id's of all connections in the containing vector.
    std::vector<uint32_t> connections;
    /// The id of the node is also it's index in the containing vecotr
    uint32_t id;
    /// Constructor using the connection the Node is going to have and assigning it its id
    /**
     * This constructor should only ever be called from PathFinder::AddNode, because creating a node
     * in a vacuum does not make sense
     */
    Node(const std::vector<uint32_t> &connections, uint32_t id);

    // Declaring PathFinder::AddNode as a friend so it has access to the private constructor
    friend Node *PathFinder::AddNode(const std::vector<uint32_t> &connections);
};
} // namespace PathAPI
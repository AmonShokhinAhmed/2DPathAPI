#pragma once
#include "navmesh.h"
#include <vector>
namespace PathAPI {
    /// Node class for use by the PathFinder class
    /**
     * Stores ids of other nodes it is connected to. Those ids are getting set during creation by
     * the PathFinder and correspond to the node's position in the map member variable of PathFinder
     */
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
        /// Position of the node in the scene
        Vector2 position;
        /// Constructor using the connection the Node is going to have and assigning it it's id
        /**
         * This constructor should only ever be called from PathFinder::AddNode, because creating a
         * node in a vacuum does not make sense
         */
        Node(const Vector2 &position, const std::vector<uint32_t> &connections, uint32_t id);

        // Declaring Navmesh::AddNode as a friend so it has access to the private constructor
        friend Node *Navmesh::AddNode(Vector2 position, const std::vector<uint32_t> &connections);
    };
} // namespace PathAPI
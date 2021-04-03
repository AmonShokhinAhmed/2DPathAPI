
#pragma once
#include "node.h"
#include "shape.h"
#include <vector>
namespace PathAPI {

    class Navmesh {
      public:
        /// Default constructor
        /**
         * As this does not yet create a Node network representing the scene, no path can be found.
         * This means this Constructor only makes sense when manually adding Nodes with the AddNode
         * function. This is intended as it provides the User with more flexibility.
         */
        Navmesh();
        /// Copy constructor
        /**
         * @param other - the navmesh we want to copy
         */
        Navmesh(const Navmesh &other);
        /// Constructor using a vector of shapes to create the navmesh
        /**
         * Using shapes flagged as walkable or not it is possible to create the Navmesh pretty
         * intuitively from an already existing scene. This changes that representation to a Node
         * network so path finding algorithms can work more efficiently
         * @param shapes - the vector of shapes that is used to create the navmesh
         */
        Navmesh(std::vector<Shape> shapes);

        /// Adding a node to the navmesh's current map.
        /**
         * This is the only way a node can be "manually" created by the user. Because creating a
         * node in a vacuum does not make any sense. It also ensures that the node gets the correct
         * id value.
         * This is also used when copying another navmesh or creating a navmesh from a shape.
         * @param [in] position - the position of the added node
         * @param [in] connections - the ids of the nodes the added node has connections to
         * @return the added Node or a nullptr when no node could be added (this happens when
         * connections contains invalid id's)
         */
        Node *AddNode(Vector2 position, const std::vector<uint32_t> &connections);

        /// Gets a node from the map corresponding to the id
        /**
         * @param[in] id - the id the looked for node should have
         * @return The found node or a nullptr
         */
        Node *GetNode(uint32_t id);
        /// Gets a node from the map corresponding to the position
        /**
         * @param[in] position - the position the looked for node should have
         * @return The found node or a nullptr
         */
        Node *GetNode(Vector2 position);

        /// Destructor cleaing up all the nodes
        ~Navmesh();

      private:
        /// Vector containing all nodes
        std::vector<Node *> map;
    };
} // namespace PathAPI
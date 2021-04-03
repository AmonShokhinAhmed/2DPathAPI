
#pragma once
#include "node.h"
#include "shape.h"
#include <vector>
namespace PathAPI {
    class Navmesh {
      public:
        Navmesh();
        Navmesh(std::vector<Shape> shapes);
        /// Adding a node to the navmesh's current map.
        /**
         * This is the only way a node can be created. Because creating a node in a vacuum does not
         * make any sense. It also ensures that the node gets the correct id value.
         */
        Node *AddNode(Vector2 position, const std::vector<uint32_t> &connections);

        /// Gets a node from the map corresponding to the id
        Node *GetNode(uint32_t id);
        /// Getter for the size of the Map
        uint32_t GetMapSize();

      private:
        std::vector<Node *> map;
    };
} // namespace PathAPI
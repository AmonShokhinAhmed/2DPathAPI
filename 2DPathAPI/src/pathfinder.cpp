#include "pathfinder.h"
#include "node.h"
#include <iostream>
namespace PathAPI {

    // public:

    PathFinder::PathFinder() {
        std::cout << "Pathfinder was created!" << std::endl;
    }

    Node *PathFinder::AddNode(const std::vector<uint32_t> &connections) {
        // current next free id is equal to map size
        // TODO: handle removal of nodes and how to handle ids
        Node *node = new Node(connections, map.size());
        // TODO: handle backwards connections
        map.push_back(node);
        return node;
    }
    Node *PathFinder::GetNode(uint32_t id) {
        // TODO: handle id outside of map size
        return map[id];
    }
    uint32_t PathFinder::GetMapSize() {
        return map.size();
    }
    // private:

} // namespace PathAPI
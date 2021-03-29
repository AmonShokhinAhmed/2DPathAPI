#include "node.h"
namespace PathAPI {

    // public:

    int Node::GetId() {
        return id;
    }
    const std::vector<uint32_t> &Node::GetConnections() {
        return connections;
    }

    // private:

    Node::Node(const std::vector<uint32_t> &connections, uint32_t id)
        : connections(connections), id(id) {
    }
} // namespace PathAPI
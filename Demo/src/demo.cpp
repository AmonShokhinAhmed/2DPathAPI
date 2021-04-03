#include "navmesh.h"
#include "pathfinder.h"
#include <iostream>
int main() {
    // Manually creating a node network should be possible:
    PathAPI::Navmesh navmesh;
    std::vector<uint32_t> connections;
    connections.push_back(1);
    PathAPI::Vector2 position1(0.0, 0.0);
    navmesh.AddNode(position1, connections);
    connections.clear();
    connections.push_back(0);
    PathAPI::Vector2 position2(0.0, 1.0);
    navmesh.AddNode(position2, connections);
    PathAPI::PathFinder pathfinder(navmesh);
}
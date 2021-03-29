#include "pathfinder.h"
#include <iostream>
int main() {
    std::cout << "Starting Demo." << std::endl;
    PathAPI::PathFinder pathfinder;
    std::vector<uint32_t> connections;
    connections.push_back(1);
    pathfinder.AddNode(connections);
    connections.clear();
    connections.push_back(0);
    pathfinder.AddNode(connections);
}
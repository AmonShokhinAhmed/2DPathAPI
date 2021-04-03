#include "node.h"
#include "pathfinder.h"
#include <catch2/catch.hpp>

/*
SCENARIO("Creating a Pathfinder instance and adding nodes", "[nodes]") {
    GIVEN("A Pathfinder instance is created") {
        PathAPI::PathFinder pathfinder;
        WHEN("the user adds a node with a connection to 1") {
            std::vector<uint32_t> connections;
            connections.push_back(1);
            PathAPI::Node *node = pathfinder.AddNode(connections);
            THEN("map has to be of size 1") {
                REQUIRE(pathfinder.GetMapSize() == 1);
            }
            THEN("the node's connection vector has to be of size 1") {
                REQUIRE(node->GetConnections().size() == 1);
            }
            THEN("the node has to have a connection to node with id 1") {
                REQUIRE(node->GetConnections()[0] == 1);
            }
            THEN("the node has to have id 0") {
                REQUIRE(node->GetId() == 0);
            }
            delete node;
        }
        WHEN("the user adds two connected nodes") {
            std::vector<uint32_t> connections;
            connections.push_back(1);
            PathAPI::Node *nodeA = pathfinder.AddNode(connections);
            connections.clear();
            connections.push_back(0);
            PathAPI::Node *nodeB = pathfinder.AddNode(connections);
            THEN("map has to be of size 2") {
                REQUIRE(pathfinder.GetMapSize() == 2);
            }
            THEN("the connection vectors have to be of size 1") {
                REQUIRE(nodeA->GetConnections().size() == 1);
                REQUIRE(nodeB->GetConnections().size() == 1);
            }
            THEN("first node has to have id 0 and second id 1") {
                REQUIRE(nodeA->GetId() == 0);
                REQUIRE(nodeB->GetId() == 1);
            }
            THEN(
                "map has to return the other node when accessing with it with the node's "
                "connection") {
                REQUIRE(pathfinder.GetNode(nodeB->GetConnections()[0]) == nodeA);
                REQUIRE(pathfinder.GetNode(nodeA->GetConnections()[0]) == nodeB);
            }
            delete nodeA;
            delete nodeB;
        }
        WHEN("the user adds multiple connected nodes") {
            std::vector<PathAPI::Node *> nodes;
            std::vector<uint32_t> connections;
            uint32_t nodeAmount = 9;
            for (uint32_t i = 0; i < nodeAmount; ++i) {
                connections.clear();
                for (uint32_t j = 0; j < nodeAmount; ++j) {
                    if (j != i) {
                        connections.push_back(j);
                    }
                }
                nodes.push_back(pathfinder.AddNode(connections));
            }
            THEN("map has to be of size " + std::to_string(nodeAmount)) {
                REQUIRE(pathfinder.GetMapSize() == nodeAmount);
            }
            THEN("the connection vectors have to be of size " + std::to_string(nodeAmount - 1)) {
                for (PathAPI::Node *node : nodes) {
                    REQUIRE(node->GetConnections().size() == nodeAmount - 1);
                }
            }
            THEN("the nodes have to have the correct id") {
                for (uint32_t i = 0; i < nodeAmount; i++) {
                    REQUIRE(nodes[i]->GetId() == i);
                }
            }
            THEN(
                "map has to return the other nodes when accessing with it with the node's "
                "connections") {
                for (uint32_t i = 0; i < nodeAmount; i++) {
                    for (uint32_t j = 0; j < nodeAmount; j++) {
                    }
                }
                for (PathAPI::Node *node : nodes) {
                    uint32_t idInMap = 0;
                    uint32_t idInVector = 0;
                    while (idInMap < nodeAmount - 1) {
                        if (idInMap == node->GetId()) {
                            ++idInVector;
                        }
                        REQUIRE(pathfinder.GetNode(node->GetConnections()[idInMap]) ==
                                nodes[idInVector]);
                        ++idInMap;
                        ++idInVector;
                    }
                }
            }
        }
    }
}
*/
#include "pathapi.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
void createRandomNavmesh(PathAPI::Navmesh *navmesh) {
    srand(time(nullptr));
    int randomNodeAmount = 9;
    // Create nodes
    for (uint32_t i = 0; i < randomNodeAmount; ++i) {
        // Create random position vector with coordinates between -10 and 10
        PathAPI::Vector2 position(rand() % 21 - 10, rand() % 21 - 10);

        // Create random connections
        std::vector<uint32_t> connections;
        for (uint32_t j = 0; j < randomNodeAmount; ++j) {
            // Don't connect to itself
            if (j != i) {
                // 50% chance to create a connection to node with id equal to current index
                if (rand() % 99 < 50) {
                    connections.push_back(j);
                }
            }
        }
        // Adding node to the navmesh
        navmesh->AddNode(position, connections);
    }
}
void usePath(PathAPI::Path &path) {
    // How fast we want to travel
    float stepSize = 1;
    // bool to check if we reached the end
    bool endOfPath = false;
    // Get the current position (should be equal to the start position at the beginning)
    PathAPI::Vector2 currentPosition = path.GetCurrentPosition();
    // While we haven't reached the end
    while (!endOfPath) {
        // Do something with current position
        // Print how far we have travelled until now
        float currentNormalizedPosition = path.GetCurrentNormalizedPosition();
        std::cout << "We travelled " << (int)(currentNormalizedPosition * 100.0f)
                  << "% of the path." << std::endl;
        // Travel to the next position and get it
        currentPosition = path.GetNextPosition(stepSize, endOfPath);
    }
    // Travelling backwards:
    // stepSize now obviously has to be negative
    stepSize = -1;
    // We set the position to 1, meaning we start at the end of the path
    path.SetCurrentPosition(1);
    // reset the bool
    endOfPath = false;
    // Get the current position (= end of path)
    currentPosition = path.GetCurrentPosition();
    // While we havent reached the end of the path (in this case this actually means the beginning)
    while (!endOfPath) {
        // ...do something with current position
        // Get the next position
        currentPosition = path.GetNextPosition(stepSize, endOfPath);
    }

    // We can also get an arbitrary position on the path by passing a normalized value
    // Here we get the middle of the path
    PathAPI::Vector2 middleOfPath = path.GetPositionOnPath(0.5f);
}
int main() {

    std::vector<PathAPI::Navmesh *> navmeshes;

    // Manually creating a node network should be possible:
    {
        // Creating an empty navmesh
        PathAPI::Navmesh *navmesh = new PathAPI::Navmesh();
        // Manually adding nodes to the navmesh
        createRandomNavmesh(navmesh);
        navmeshes.push_back(navmesh);
    }
    // Using a nodefile
    {
        // Creating the navmesh by loading a nodefile
        PathAPI::Navmesh *navmesh = new PathAPI::Navmesh("nodefile.txt");
        navmeshes.push_back(navmesh);
    }
    // Using textures
    {
        // Create a vector containing the "scene"
        std::vector<PathAPI::Shape *> shapes;
        // Load the floor shape
        PathAPI::Shape *floor = new PathAPI::Shape("floor.png");
        // Set it to walkable
        floor->Walkable = true;
        // Add it to the scene
        shapes.push_back(floor);
        // Load an obstacle shape
        PathAPI::Shape *obstacle = new PathAPI::Shape("obstacle.png");
        // Add it to the scene
        shapes.push_back(obstacle);
        // Move the obstacle to another position
        obstacle->Transform.Position = PathAPI::Vector2(1, 0);
        // Create the navmesh from the scene
        PathAPI::Navmesh *navmesh = new PathAPI::Navmesh(shapes);
    }
    for (PathAPI::Navmesh *navmesh : navmeshes) {
        // Creating a pathfinder
        PathAPI::PathFinder pathfinder(navmesh);
        // Choosing start and end point
        PathAPI::Vector2 start(0, 0);
        PathAPI::Vector2 end(1, 0);

        // Bool to check for errors
        bool pathFound;
        // Trying to find a path as fast as possible
        PathAPI::Path fastPath = pathfinder.FindFastPath(start, end, pathFound);
        // If no errors happened
        if (pathFound) {
            // Use the path
            usePath(fastPath);
        }
        // Trying to find the best possible path
        PathAPI::Path optimizedPath = pathfinder.FindOptimizedPath(start, end, pathFound);
        // If no errors happened
        if (pathFound) {
            // Use the path
            usePath(optimizedPath);
        }
    }
    // Cleanup
    for (int i = 0; i < navmeshes.size(); ++i) {
        delete navmeshes[i];
    }
    navmeshes.clear();
}
#include "pathapi.h"
#include <iostream>
void createRandomNavmesh(PathAPI::Navmesh &navmesh) {
}
void testPath(PathAPI::Path &path) {
}
int main() {
    // Manually creating a node network should be possible:
    {
        PathAPI::Navmesh navmesh;
        createRandomNavmesh(navmesh);
        PathAPI::PathFinder pathfinder(navmesh);
        PathAPI::Vector2 start(0, 0);
        PathAPI::Vector2 end(1, 0);
        bool pathFound;
        PathAPI::Path fastPath = pathfinder.FindFastPath(start, end, pathFound);
        PathAPI::Path optimizedPath = pathfinder.FindOptimizedPath(start, end, pathFound);
        testPath(fastPath);
        testPath(optimizedPath);
    }
    {
        std::vector<PathAPI::Shape> shapes;
        PathAPI::Shape floor("floor.png");
        floor.Walkable = true;
        shapes.push_back(floor);
        PathAPI::Shape obstacle("obstacle.png");
        shapes.push_back(obstacle);
        obstacle.Transform.Position = PathAPI::Vector2(1, 0);
        PathAPI::Navmesh navmesh(shapes);
        PathAPI::PathFinder pathfinder(navmesh);
        PathAPI::Vector2 start(0, 0);
        PathAPI::Vector2 end(1, 0);
        bool pathFound;
        PathAPI::Path fastPath = pathfinder.FindFastPath(start, end, pathFound);
        PathAPI::Path optimizedPath = pathfinder.FindOptimizedPath(start, end, pathFound);
        testPath(fastPath);
        testPath(optimizedPath);
    }
}
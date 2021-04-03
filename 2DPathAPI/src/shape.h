#pragma once
#include "transform.h"
#include "vector2.h"
#include <string>
#include <vector>
namespace PathAPI {
    class Shape {
      public:
        bool Walkable = false;
        Transform Transform;
        Shape(std::string path);
        Shape(std::vector<Vector2> vertices);
    };
} // namespace PathAPI
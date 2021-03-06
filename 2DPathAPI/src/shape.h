#pragma once
#include "transform.h"
#include "vector2.h"
#include <string>
#include <vector>
namespace PathAPI {
    /// Shape class, storing a list of vectors to define a 2D shape.
    /**
     * This is the most basic way to represent an object. It consists of the a list of Vector2
     * objects (forming triangles), that defines a basic shape. That shape can be altered by
     * manipulating the Transform member variable. In addition the Walkable flag can be used to
     * define if the shape should be part of the walkable terrain, when using it to create a Navmesh
     */
    class Shape {
      public:
        /// Flag to define the shape as walkable for potential Navmesh creation
        bool Walkable = false;
        /// Transform of the shape
        Transform Transform;
        /// Constructor using a path to load a image file from disc to define the shape
        /**
         * This will define the shape considering pixel as empty when they are either white or the
         * alpha channel value is zero. White pixels can also be considered filled if the
         * whiteAsAlpha flag is turned to false
         * @param[in] path - Path to the image file
         * @param[in] whiteAsAlpha - true if white pixel should be considered empty
         */
        Shape(const std::string &path, bool whiteAsAlpha = true);
        /// Constructor that allows the user to manually define the shapes vertices
        /**
         * @param[in] vertices - the vertices the shape consists of. Every three indices denote on
         * triangle, so only a vector with a size of a multiple of three will be valid. If it is
         * invalid the Shape will just ignore the last 1 or 2 indices.
         */
        Shape(const std::vector<Vector2> &vertices);

        /// Getter to the stored vertices
        /**
         * @return a reference vector containing it's vertices
         */
        const std::vector<Vector2> &GetVertices();

      private:
        std::vector<Vector2> vertices;
    };
} // namespace PathAPI
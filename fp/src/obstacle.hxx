#pragma once

#include <ge211.hxx>
#include "geometry.hxx"
#include "bird.hxx"

int const horizontal_velocity = 10;
int const col_width = 20;

using Column = ge211::Rectangle;

class Obstacle
{
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    // Rectangle representing the top pipe
    Column top_pipe_;

    // Rectangle representing the bottom pipe
    Column bottom_pipe_;

    // Whether there will be a coin in the gap
    bool has_coin_;

public:

    ///
    /// CONSTRUCTOR
    ///

    // Constructs a new obstacle. The top of the top_pipe_ will always have a y coordinate of 0,
    // and the bottom of the bottom_pipe_ will always have a y coordinate of the y dimensions.
    // The widths of both pipes for every obstacle is constant, but the heights of each pipe are
    // determined randomly. Whether or not there will be a coin in the middle of the pipes is also
    // determined randomly.
    // Takes in a reference to a ge211::Random object that will be used to randomize the pipes and
    // coin, and a reference to a Geometry object that provides the dimensions of the scene.

    Obstacle(ge211::Random& rng, Geometry const&, Bird const&);

    ///
    /// MEMBER FUNCTIONS
    ///

    // Returns top_pipe_
    Column top_pipe() const;

    // Returns bottom_pipe_
    Column bottom_pipe() const;

    // Returns has_coin_
    bool has_coin() const;

    // Returns a new Obstacle but whose position has been updated by its velocity
    Obstacle next();
};
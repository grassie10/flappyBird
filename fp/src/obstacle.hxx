#pragma once

#include <ge211.hxx>
#include "geometry.hxx"
#include "coin.hxx"

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

    // Width of the pipes in the obstacle
    int width_;

    // Velocity of the obstacle
    ge211::Dimensions velocity_;

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
    Obstacle(ge211::Random& rng, Geometry const&);

    // Constructor for Obstacle strictly for testing purposes.
    // Controls the heights of the pipes and whether the obstacle has a coin.
    Obstacle(Geometry const&, int top_height, int bottom_height, bool with_coin);

    ///
    /// PUBLIC DATA MEMBERS
    ///

    // Coin object in gap between top and bottom pipes. Only accessed if has_coin_ is true
    Coin coin_;

    ///
    /// MEMBER FUNCTIONS
    ///

    // Returns top_pipe_
    Column top_pipe() const;

    // Returns bottom_pipe_
    Column bottom_pipe() const;

    // Returns has_coin_
    bool has_coin() const;

    // Returns coin_.
    // PRECONDITION: has_coin_ is true
    Coin coin() const;

    // Returns width_
    int width() const;

    // Returns velocity_
    ge211::Dimensions velocity() const;

    // Sets the position of the top and bottom pipes via x-coordinate
    void set_position(int x);

    // Returns a new Obstacle but whose position has been updated by its velocity
    Obstacle next();
};
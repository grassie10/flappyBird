#pragma once

#include <ge211.hxx>
#include "geometry.hxx"

class Coin
{
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    // Center of the coin
    ge211::Position center_;

    // Radius of the coin
    int radius_;

    // Velocity of the coin
    ge211::Dimensions velocity_;

    // Whether or not the coin has been collected by the bird. If it has been collected,
    // then it should disappear from the screen.
    bool collected_;

public:

    ///
    /// CONSTRUCTOR
    ///

    // Constructs a new coin that is centered in the gap between the two pipes in an Obstacle
    Coin(ge211::Position center, Geometry const&);

    ///
    /// PUBLIC MEMBER FUNCTIONS
    ///

    // Returns collected_
    bool is_collected() const;

    // Returns the radius of the coin
    int radius() const;

    // Returns the velocity of the coin
    ge211::Dimensions velocity() const;

    // Sets collected_ equal to true, and is called when the bird hits the coin
    void collect();

    // Returns the position of the top left of the coin's bounding box
    ge211::Position top_left() const;

    // Returns the position of the top right of the coin's bounding box
    ge211::Position top_right() const;

    // Returns the position of the bottom left of the coin's bounding box
    ge211::Position bottom_left() const;

    // Returns the position of the bottom right of the coin's bounding box
    ge211::Position bottom_right() const;

    // Returns a new Coin but whose position has been updated by its velocity
    Coin next();
};
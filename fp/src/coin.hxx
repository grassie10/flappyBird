#pragma once

#include <ge211.hxx>
#include "obstacle.hxx"

int const radius = 5;

class Coin
{
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    // Center of the coin
    ge211::Position center_;

    // Whether or not the coin has been collected by the bird. If it has been collected,
    // then it should disappear from the screen.
    bool collected_;

public:

    ///
    /// CONSTRUCTOR
    ///

    // Constructs a new coin that is centered in the gap between
    Coin(Obstacle const&);

    ///
    /// PUBLIC MEMBER FUNCTIONS
    ///

    // Returns collected_
    bool is_collected() const;

    // Sets collected_ equal to true, and is called when the bird hits the coin
    void collect();

    // Returns the position of the top left of the coin's bounding box
    ge211::Position top_left();

    // Returns the position of the top right of the coin's bounding box
    ge211::Position top_right();

    // Returns the position of the bottom left of the coin's bounding box
    ge211::Position bottom_left();

    // Returns the position of the bottom right of the coin's bounding box
    ge211::Position bottom_right();

    // Returns a new Coin but whose position has been updated by its velocity
    Coin next();
};
// Defines a struct for modeling the bird.

#pragma once

#include "geometry.hxx"
#include <ge211.hxx>
#include "obstacle.hxx"
#include "coin.hxx"

using Column = ge211::Rectangle;
// This struct is used to represent the state of the bird. In particular, we
// need to know how big the bird is (radius_), whether it's moving or
// stopped (live_), where it is (center_), and where it's going (velocity_).
//
// `velocity_` is a ge211::Dimensions, which means it has two
// `int` member variables, `width` and `height`, which are the rates of
// change in the x and y dimensions (the x dimension is constant),
// respectively. In particular, in each "frame" `center_` gets shifted by
// `velocity_`. A `Dimensions`added to a `Position` yields a shifted `Position`,
// so this may be written as
//
//     a_bird.position_ += a_bird.velocity_;
//
struct Bird
{
    ///
    /// CONSTRUCTOR
    ///

    // Constructs a new bird. It needs to know where the center of
    // the left side of the screen is (so it can position itself
    // and the geometry (which includes the bird's radius and initial velocity).
    // The bird starts dead--not moving and in the middle of the left side of the screen
    // In addition to constructing the bird in the model in the first place,
    // this can also be used to reset the bird by creating a new bird to
    // assign over it:
    //
    //     bird_ = Bird(geometry_);
    Bird(Geometry const&);

    ///
    /// MEMBER FUNCTIONS
    ///

    // Returns the position of the top-left corner of the bird's "bounding
    // box", meaning the smallest rectangle in which is can be enclosed.
    // This is useful to the UI because sprites are positioned based on
    // their top-left corners.
    ge211::Position top_left() const;

    // Returns a new bird like this one but whose position has been
    // updated by adding on the velocity. This is useful because the
    // model's algorithm for collision detection involves speculatively
    // moving the ball and checking where it would end up, before
    // actually moving it.
    //
    // This can also be used to actually move it, via assignment:
    //
    //    bird_ = bird_.next();
    //
    Bird next() const;

    // These functions all perform collision detection by telling us whether
    // this bird is *past* the given edge.
    bool hits_top(Geometry const&) const;
    bool hits_bottom(Geometry const&) const;

    // Collision detection for obstacles. Returns whether the circle's
    // bounding box intersects with the given object.
    //
    // Intersection between a circle and a rectangle is tricky, so we
    // will approximate it with the intersection of two rectangles.
    bool hits_column(Column const&) const;
    bool hits_obstacle(Obstacle const&) const;
    bool pass_obstacle(Obstacle const&) const;
    
    // Collision detection between the bird and the coin.
    // If the bird collides with the coin then that coin is removed and
    // the functions returns true.
    // If there is no collision then the function returns false.
    bool hits_coin(Coin const&) const;

    // Negates the vertical component of this bird's velocity.
    void boost_vertical(int boost);


    ///
    /// MEMBER VARIABLES
    ///

    // The radius of the bird.
    int               radius_;

    // The velocity of the bird in pixels per tick.
    ge211::Dimensions velocity_;

    // The position of the center of the bird.
    ge211::Position   center_;

    // Whether the bird is moving freely (true) or stuck on
    // the center of the left side of the screen
    bool              live_;
};

// Compares two `Bird`s for equality. This may be useful for testing.
//
// Two `Bird`s are equal if all their member variables are pairwise
// equal.
bool operator==(Bird const&, Bird const&);

// Inequality for `Ball`s.
bool operator!=(Bird const&, Bird const&);
// Defines a struct to hold model geometry parameters.

#pragma once

#include <ge211.hxx>

struct Geometry
{
    // Constructs an instance with the default parameters.
    Geometry() noexcept;

    // The dimensions of the whole window:
    ge211::Dimensions scene_dims;

    // Number of pixels from sides of screen to bird's starting point:
    int side_margin;

    // The radius of the bird:
    int bird_radius;

    // The bird's initial velocity {width, height}:
    ge211::Dimensions bird_velocity0;

    // The obstacle and coin's velocity {width, height}:
    ge211::Dimensions background_velocity;

    // The amount that clicking boosts the bird's y
    // velocity component:
    int bird_boost;

};


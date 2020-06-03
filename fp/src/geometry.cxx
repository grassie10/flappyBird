#include "geometry.hxx"

// This is the default (and only) constructor for `Geometry`. It determines
// all the default values of all the member variables.
Geometry::Geometry() noexcept
        : bird_radius    {    20 }
        , bird_boost      {    100 }
        , bird_velocity0 {    0, 4 }
        , background_velocity  {   -10,   0 }
        , scene_dims     { 1000, 700 }
        , side_margin    {  50 }
        , obstacle_width    { 40 }
        , obstacle_spacing  { 150 }
        , coin_radius       { 10 }
{ }


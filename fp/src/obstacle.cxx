#include "obstacle.hxx"
#include "geometry.hxx"
#include "bird.hxx"

Obstacle::Obstacle(ge211::Random& rng, Geometry const& geometry, Bird const& bird)
{
    // Make sure that the gap between the pipes is big enough for the bird
    int diff = 0;
    int top_height = 0;
    int bottom_height = 0;
    while (diff < bird.radius_ + 10) {
        top_height = rng.between(1, geometry.scene_dims.height);
        bottom_height = rng.between(1, geometry.scene_dims.height - top_height);
        diff = (geometry.scene_dims.height - bottom_height) - top_height;
    }
    // Initialize the top and bottom pipes
    top_pipe_ = Column::from_top_left({geometry.scene_dims.width, 0}, {col_width, top_height});
    bottom_pipe_ = Column::from_bottom_left({geometry.scene_dims.width, geometry.scene_dims.height},
                                            {col_width, bottom_height});

    // Randomly determine if this obstacle should contain a coin
    int r = rng.between(0, 100);
    if (r < 30) {
        has_coin_ = true;
    } else {
        has_coin_ = false;
    }
}

// Returns top_pipe_
Column Obstacle::top_pipe() const
{
    return top_pipe_;
}

// Returns bottom_pipe_
Column Obstacle::bottom_pipe() const
{
    return bottom_pipe_;
}

// Returns has_coin_
bool Obstacle::has_coin() const
{
    return has_coin_;
}

// Returns a new Obstacle but whose position has been updated by its velocity
Obstacle Obstacle::next()
{
    Obstacle result(*this);
    result.top_pipe_.x -= horizontal_velocity;
    result.bottom_pipe_.x -= horizontal_velocity;
    return result;
}
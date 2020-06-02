#include "obstacle.hxx"
#include "geometry.hxx"
#include "coin.hxx"

Obstacle::Obstacle(ge211::Random& rng, Geometry const& geometry)
            : width_ (geometry.obstacle_width)
            , velocity_ (geometry.background_velocity)
            , coin_ (ge211::Position {top_pipe_.center().x,
                                      (top_pipe_.bottom_left().y + bottom_pipe_.top_left().y) / 2},
                     geometry)
{
    // Make sure that the gap between the pipes is big enough for the bird
    int diff = 0;
    int top_height = 0;
    int bottom_height = 0;
    while (diff < (2*geometry.bird_radius) + 20) {
        int top_height = rng.between(1, geometry.scene_dims.height);
        int bottom_height = rng.between(1, geometry.scene_dims.height - top_height);
        diff = (geometry.scene_dims.height - bottom_height) - top_height;
    }
    // Initialize the top and bottom pipes
    top_pipe_ = Column::from_top_left({geometry.scene_dims.width, 0}, {width_, top_height});
    bottom_pipe_ = Column::from_bottom_left({geometry.scene_dims.width, geometry.scene_dims.height},
                                            {width_, bottom_height});

    // Randomly determine if this obstacle should contain a coin
    int r = rng.between(0, 100);
    if (r < 30) {
        has_coin_ = true;
    } else {
        has_coin_ = false;
    }
}

Obstacle::Obstacle(Geometry const& geometry, int top_height, int bottom_height, bool with_coin)
        : width_ (geometry.obstacle_width)
        , velocity_ (geometry.background_velocity)
        , coin_ (ge211::Position {top_pipe_.center().x,
                                  (top_pipe_.bottom_left().y + bottom_pipe_.top_left().y) / 2},
                 geometry)
        , has_coin_ (with_coin)
{
    top_pipe_ = Column::from_top_left({geometry.scene_dims.width, 0}, {width_, top_height});
    bottom_pipe_ = Column::from_bottom_left({geometry.scene_dims.width, geometry.scene_dims.height - bottom_height},
                                            {width_, bottom_height});
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

// Returns coin_.
// PRECONDITION: has_coin_ is true
Coin Obstacle::coin() const
{
    return coin_;
}

// Returns width_
int Obstacle::width() const
{
    return width_;
}

// Returns velocity_
ge211::Dimensions Obstacle::velocity() const
{
    return velocity_;
}

// Sets the position of the top and bottom pipes via x-coordinate
void Obstacle::set_position(int x)
{
    top_pipe_.x = x;
    bottom_pipe_.x = x;
}

// Returns a new Obstacle but whose position has been updated by its velocity
Obstacle Obstacle::next()
{
    Obstacle result(*this);
    result.top_pipe_.x -= velocity_.width;
    result.bottom_pipe_.x -= velocity_.width;
    result.coin_.center_.x -= velocity_.width;
    return result;
}
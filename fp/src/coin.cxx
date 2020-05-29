#include "coin.hxx"
#include "obstacle.hxx"

Coin::Coin(Obstacle const& obstacle)
        : collected_(false)
{
    center_ = {obstacle.top_pipe().center().x,
               (obstacle.top_pipe().bottom_left().y + obstacle.bottom_pipe().top_left().y) / 2};
}

// Returns collected_
bool Coin::is_collected() const
{
    return collected_;
}

// Sets collected_ equal to true
void Coin::collect()
{
    collected_ = true;
}

// Returns the position of the top left of the coin's bounding box
ge211::Position Coin::top_left()
{
    return {center_.x - radius, center_.y - radius};
}

// Returns the position of the top right of the coin's bounding box
ge211::Position Coin::top_right()
{
    return {center_.x + radius, center_.y - radius};
}

// Returns the position of the bottom left of the coin's bounding box
ge211::Position Coin::bottom_left()
{
    return {center_.x - radius, center_.y + radius};
}

// Returns the position of the bottom right of the coin's bounding box
ge211::Position Coin::bottom_right()
{
    return {center_.x + radius, center_.y + radius};
}

// Returns a new Coin but whose position has been updated by its velocity
Coin Coin::next()
{
    Coin result(*this);
    result.center_.x -= horizontal_velocity;
    return result;
}
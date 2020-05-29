#include "coin.hxx"
#include "geometry.hxx"
#include "obstacle.hxx"

Coin::Coin(Obstacle const& obstacle, Geometry const& geometry)
        : center_ (ge211::Position {obstacle.top_pipe().center().x,
                                    (obstacle.top_pipe().bottom_left().y + obstacle.bottom_pipe().top_left().y) / 2})
        , radius_ (geometry.coin_radius)
        , velocity_ (geometry.background_velocity)
        , collected_ (false)
{ }

// Returns collected_
bool Coin::is_collected() const
{
    return collected_;
}

// Returns the radius of the coin
int Coin::radius() const
{
    return radius_;
}

// Returns the velocity of the coin
ge211::Dimensions Coin::velocity() const
{
    return velocity_;
}

// Sets collected_ equal to true
void Coin::collect()
{
    collected_ = true;
}

// Returns the position of the top left of the coin's bounding box
ge211::Position Coin::top_left() const
{
    return {center_.x - radius_, center_.y - radius_};
}

// Returns the position of the top right of the coin's bounding box
ge211::Position Coin::top_right() const
{
    return {center_.x + radius_, center_.y - radius_};
}

// Returns the position of the bottom left of the coin's bounding box
ge211::Position Coin::bottom_left() const
{
    return {center_.x - radius_, center_.y + radius_};
}

// Returns the position of the bottom right of the coin's bounding box
ge211::Position Coin::bottom_right() const
{
    return {center_.x + radius_, center_.y + radius_};
}

// Returns a new Coin but whose position has been updated by its velocity
Coin Coin::next()
{
    Coin result(*this);
    result.center_.x -= velocity_.width;
    return result;
}
#include "coin.hxx"
#include "geometry.hxx"

Coin::Coin()
        : center_ {0, 0}
{}

Coin::Coin(ge211::Position center, Geometry const& geometry)
        : center_ (center)
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
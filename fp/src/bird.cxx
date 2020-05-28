#include "bird.hxx"
#include "geometry.hxx"

// Computes where the bird should be when it's at the
// starting stage
static ge211::Position start_pos(Geometry const& geometry)
{
    int x = 20;
    int y = geometry.scene_dims.height/2;
    return {x, y};
}

// It won't compile without this, so you get it for free.
Bird::Bird(Geometry const& geometry)
        : radius_   (geometry.ball_radius)
        , velocity_ (geometry.ball_velocity0)
        , center_   (start_pos(geometry))
        , live_     (false)
{ }

ge211::Position Bird::top_left() const
{
    return {center_.x - radius_, center_.y - radius_};
}

bool Bird::hits_bottom(Geometry const& geometry) const
{
    return (center_.y+radius_ > geometry.scene_dims.height);
}

bool Bird::hits_top(Geometry const&) const
{
    return (center_.y-radius_< 0);
}


Bird Bird::next() const
{
    Ball result(*this);
    result.center_ += result.velocity_;
    return result;
}

bool Bird::hits_column(Column const& column) const {
    return ((center_.x+radius_ > column.top_left().x &&
             column.top_right().x >center_.x-radius_) &&
            (center_.y+radius_ > column.top_left().y &&
             column.bottom_left().y > center_.y-radius_));
}

bool Bird::hits_obstacle(Obstacle const& obstacle) const {
    return (hits_column(obstacle.top_pipe()) || hits_column(obstacle.bottom_pipe()))
}

bool Bird::pass_obstacle(Obstacle const& obstacle) const {
    return ((center_.x-radius_ > obstacle.top_pipe().top_right().x)
    && !hits_obstacle(obstacle));
}
bool hits_coin(Coin const& coin) const {
    return ((center_.x+radius_ > coin.top_left().x &&
             coin.top_right().x >center_.x-radius_) &&
            (center_.y+radius_ > coin.top_left().y &&
             coin.bottom_left().y > center_.y-radius_))
}

void boost_vertical(int boost) {
    velocity_.height += boost;
}

bool operator==(Bird const& b1, Bird const& b2)
{
    return (b1.center_==b2.center_ && b1.velocity_==b2.velocity_
    && b1.radius_==b2.radius_ && b1.live_==b2.live_);
}

bool operator!=(Bird const& b1, Bird const& b2)
{
    return !(b1 == b2);
}

#include "obstacle.hxx"

int const horizontal_velocity = 10;
int const width = 10;

Obstacle::Obstacle(ge211::Random& rng)
{
    int r = rng.between(1, 100); //replace end bound with scene dims height
    //replace x with scene dims width
    top_pipe_ = Column::from_top_left({100,0}, {width, r});

    r = rng.between(1, 100 - r);
    //replace x and y with scene dims width and height
    top_pipe_ = Column::from_bottom_left({100,100}, {width, r});

    r = rng.between(0, 100);
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

}
#include "model.hxx"
#include "bird.hxx"
#include "coin.hxx"
#include "geometry.hxx"
#include "obstacle.hxx"

int Model::high_score = 0;

Model::Model(Geometry const& geometry)
{ }

void Model::update()
{

}

// Returns the score from the current game
int Model::get_score()
{
    return score_;
}

// Returns the overall high score
int Model::get_high_score()
{
    return high_score;
}

// Start (or restart) the game. Make the dead bird alive, reinitialize the scene (obstacles and coins),
// and set the score equal to zero.
void Model::start()
{

}

// Returns game_end_
bool Model::game_end()
{
    return game_end_;
}

// Returns the bird
Bird Model::bird() const
{
    return bird_;
}

// Returns the vector of existing obstacles
std::vector<Obstacle> Model::obstacles() const
{
    return obstacles_;
}

// Returns the vector of existing coins
std::vector<Coin> Model::coins() const
{
    return coins_;
}
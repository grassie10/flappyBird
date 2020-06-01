#include "model.hxx"
#include "bird.hxx"
#include "coin.hxx"
#include "geometry.hxx"
#include "obstacle.hxx"

int Model::high_score = 0;

Model::Model(Geometry const& geometry)
    : geometry_(geometry)
    , bird_(geometry)
    , game_end_(true)
    , score_(0)

{
    ge211::Random& rng = ge211::Abstract_game::get_random();
    //obstacles and coins
    while (!game_end_){
        Obstacle new_obstacle(rng, geometry);
        new_obstacle.set_position(geometry.scene_dims.width-geometry.obstacle_width);
        obstacles_.push_back(new_obstacle);
        if (new_obstacle.has_coin()){
            coins_.push_back(new_obstacle.coin());
        }
    }

}

void Model::update()
{
    if (bird_.live_){
        game_end_ = false;
        for (Obstacle& o: obstacles_){
            Obstacle new_o = o.next();
            if (o.has_coin()){
                Coin c = o.coin();
            }
            Coin c = o.coin();
            if (bird_.hits_obstacle(new_o)){
                bird_.live_ = false;
                game_end_ = true;
                if (score_ > high_score){
                    high_score = score_;
                }
                return;
            }else if (bird_.pass_obstacle(new_o)) {
                std::swap(o, obstacles_.back());
                obstacles_.pop_back();
                score_ += 1;
                if (bird_.hits_coin(c)){
                    score_ +=1;
                }
                o = o.next();
                return;
            }
        }
    }else{
        game_end_ = true;
        if (score_ > high_score){
            high_score = score_;
        }
        return;
    }
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
    bird_.live_ = true;
    score_ = 0;
    obstacles_ = Model::obstacles_;
    coins_ = Model::coins_;
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
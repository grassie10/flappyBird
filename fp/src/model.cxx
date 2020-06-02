#include "model.hxx"
#include "bird.hxx"
#include "coin.hxx"
#include "geometry.hxx"
#include "obstacle.hxx"

int Model::high_score = 0;

Model::Model(Geometry const& geometry, ge211::Random& my_rng)
    : geometry_(geometry)
    , random_(my_rng)
    , bird_(geometry)
    , game_end_(true)
    , score_(0)
{
    //ge211::Random& my_rng = ge211::Abstract_game::get_random();
    //initialize one obstacle at beginning of game
    Obstacle new_obstacle(random_, geometry);
    new_obstacle.set_position(geometry.scene_dims.width - geometry.obstacle_width);
    obstacles_.push_back(new_obstacle);
}

void Model::update()
{
    if (bird_.live_){
        game_end_ = false;
        Bird next_bird = bird_.next();

        for (Obstacle& o: obstacles_) {
            Obstacle new_o = o.next();

            // check if the bird dies
            if (next_bird.hits_obstacle(new_o)
                || next_bird.hits_top(geometry_)
                || next_bird.hits_bottom(geometry_)) {
                bird_.live_ = false;
                game_end_ = true;
                if (score_ > high_score){
                    high_score = score_;
                }
                return;
            }

            // check if the bird passes an obstacle
            if (next_bird.pass_obstacle(new_o)) {
                score_ += 1;
            }

            // separately check if the bird hits the coin
            if (o.has_coin()) {
                Coin next_coin = new_o.coin();
                if (!next_coin.is_collected() && next_bird.hits_coin(next_coin)) {
                    score_ += 1;
                    o.coin_.collect();
                }
            }

            // update the obstacle
            o = o.next();
        }

        // update vector of obstacles
        // check if first obstacle has moved off of the left side of the screen
        if (obstacles_[0].top_pipe().top_right().x < 0) {
            obstacles_.erase(obstacles_.begin());
        }
        // add any obstacle that comes into the right of the screen
        if (geometry_.scene_dims.width - obstacles_[obstacles_.size() - 1].top_pipe().top_right().x
            >= geometry_.obstacle_spacing) {
            //ge211::Random& my_rng = ge211::Abstract_game::get_random();
            Obstacle new_obstacle(random_, geometry_);
            new_obstacle.set_position(geometry_.scene_dims.width);
            obstacles_.push_back(new_obstacle);
        }

        // update the bird
        bird_ = bird_.next();
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
    game_end_ = false;

    // clear and reinitialize obstacles_
    obstacles_.clear();
    //ge211::Random& my_rng = ge211::Abstract_game::get_random();
    Obstacle new_obstacle(random_, geometry_);
    new_obstacle.set_position(geometry_.scene_dims.width - geometry_.obstacle_width);
    obstacles_.push_back(new_obstacle);
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
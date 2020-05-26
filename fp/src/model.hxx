#pragma once

#include <ge211.hxx>

//
// Model constants:
//

// Each obstacle has the same width
const int obstacle_width;

// The vertical velocities of the top and bottom pipes for a moving obstacle
const ge211::Dimensions moving_obstacle_velocity;

// The vertical position boost that a bird gets when the player presses the space bar
const int bird_boost;

// The bird's constant positive horizontal velocity and positive (downward) vertical velocity
const ge211::Dimensions bird_velocity;

// The dimensions of the screen
const ge211::Dimensions scene_dims;

//
// Model classes:
//

//Each vertical column, including the top and bottom pipes and the gap in between
struct Obstacle
{
    // Rectangle representing the top pipe
    ge211::Rectangle top_pipe;

    // Rectangle representing the bottom pipe
    ge211::Rectangle bottom_pipe;

    // Height of the gap size in between the top and bottom pipes
    int gap_size;

    // Whether there will be a coin in the gap
    bool has_coin;

    // The color of both of the pipes
    ge211::Color obstacle_color;

    // Whether or not the pipes will move vertically
    bool movable;
};

// The whole state of the game
class Model {
    //
    // STATIC DATA MEMBERS
    //

    // The high score maintained across all games
    static int high_score;

    //
    // PRIVATE DATA MEMBERS
    //

    // The center of the bird
    ge211::Position bird_;

    // Whether the bird is currently alive (in play)
    bool bird_alive_;

    // The constantly changing vector of obstacles on the screen
    std::vector<Obstacle> obstacles_;

    // The top left of the coin
    ge211::Position coin_;

    // Whether the existing coin has been collected or not
    bool coin_alive_;

    // Whether the game is still ongoing
    bool game_end;

    // The score of the current game
    int score;

public:
    //
    // PUBLIC FUNCTIONS
    //

    // Returns the bird's position
    ge211::Position get_bird_position() const;

    // Views the states of all of the obstacles
    std::vector<Obstacle> const& get_obstacles() const;

    // Updates the model state for one time step
    void update();

    // Returns the score from the current game
    int get_score();

    // Returns the overall high score
    int get_high_score();

    // Restart the game
    void restart();

    // Give the bird a vertical position boost
    void boost_bird();

private:
    //
    // POSSIBLE HELPER FUNCTIONS
    //

    // Determines the position for a coin for a given obstacle
    ge211::Position coin_position(Obstacle);

    // Determines whether the bird hits a given object
    bool bird_hits_top() const;
    bool bird_hits_bottom() const;
    bool bird_hits_obstacle() const;
    bool bird_hits_coin() const;
};
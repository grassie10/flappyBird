#pragma once

#include <ge211.hxx>
#include "bird.hxx"
#include "coin.hxx"
#include "geometry.hxx"
#include "obstacle.hxx"

// The whole state of the game
class Model
{
    ///
    /// STATIC DATA MEMBERS
    ///

    // The high score maintained across all games
    static int high_score;

    // Whether any round has been played yet
    static bool first_start;

    ///
    /// PRIVATE DATA MEMBERS
    ///

    // The state of the bird
    Bird bird_;

    // The constantly changing vector of obstacles on the screen
    std::vector<Obstacle> obstacles_;

    // Whether the game is still ongoing
    bool game_end_;

    // The score of the current game
    int score_;

public:
    ///
    /// CONSTRUCTOR
    ///

    explicit Model(Geometry const& geometry, ge211::Random& my_rng);

    ///
    /// PUBLIC DATA MEMBERS
    ///

    // The geometry parameters of the model
    Geometry const geometry_;

    // For testing in model_test
    friend struct Test_access;

    ///
    /// PUBLIC FUNCTIONS
    ///

    // Updates the model state for one time step. Needs to update the bird, the obstacles,
    // and the coins. If the bird hits the top or bottom of the screen or any of the obstacles,
    // then the bird dies and the game ends.
    // Updates the score -- if the bird hits a coin, then the coin disappears and the score
    // increases by 1. If the bird passes through an obstacle, the score increases by 1.
    // Need to update obstacles_ and coins_ to make sure that they only contain those that are
    // shown on the screen (remove non-visible objects and add new objects accordingly).
    void update();

    // Returns the score from the current game
    int get_score();

    // Returns the overall high score
    int get_high_score();

    // Start (or restart) the game
    void start();

    // Returns game_end_
    bool game_end();

    // Returns the bird
    Bird bird() const;

    // Gives the bird a vertical boost
    void boost_bird();

    // Returns the vector of existing obstacles
    std::vector<Obstacle> obstacles() const;

    // Random object used to generate obstacle pipe heights and determine if an obstacle has a coin
    ge211::Random& random_;

private:
    ///
    /// POSSIBLE HELPER FUNCTIONS
    ///

};
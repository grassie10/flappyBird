#pragma once

#include <ge211.hxx>
#include "model.hxx"
#include <string>

extern ge211::Color const background_color, bird_color, coin_color, obstacle_color;

struct Obstacle_data
{
    Obstacle obstacle;

    // contains all the relevant information for the sprites created per obstacle
    ge211::Rectangle_sprite top_pipe_sprite;
    ge211::Position top_pipe_position;
    ge211::Rectangle_sprite bottom_pipe_sprite;
    ge211::Position bottom_pipe_position;
};

class View
{
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    Model& model_;

    ge211::Rectangle_sprite background_;
    ge211::Circle_sprite bird_sprite_;
    ge211::Circle_sprite coin_sprite_;
    std::vector<Obstacle_data> obstacle_sprites_;
    ge211::Text_sprite score_sprite_;
    ge211::Text_sprite high_score_sprite_;

    // The font for displaying the score at the end of a round
    ge211::Font sans30{"sans.ttf", 30};

public:

    ///
    /// CONSTRUCTOR
    ///

    explicit View(Model&);

    ///
    /// MEMBER FUNCTIONS
    ///

    void draw(ge211::Sprite_set& set);

    ge211::Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

    // Update obstacle_sprites_ and score_sprite_
    void update_sprites()
    {
        obstacle_sprites_.clear();

        for (Obstacle obstacle : model_.obstacles()) {
            ge211::Rectangle_sprite top_pipe_sprite({obstacle.width(), obstacle.top_pipe().height}, obstacle_color);
            ge211::Position top_pipe_pos(obstacle.top_pipe().top_left());
            ge211::Rectangle_sprite bottom_pipe_sprite({obstacle.width(), obstacle.bottom_pipe().height}, obstacle_color);
            ge211::Position bottom_pipe_pos(obstacle.bottom_pipe().top_left());

            Obstacle_data od {obstacle, top_pipe_sprite, top_pipe_pos, bottom_pipe_sprite, bottom_pipe_pos};
            obstacle_sprites_.push_back(od);
        }

        // update score_sprite_
        std::string score_text = "Score: "+std::to_string(model_.get_score());
        std::string high_score_text = "High Score: "+std::to_string(model_.get_high_score());
        score_sprite_ = ge211::Text_sprite {score_text, sans30};
        high_score_sprite_ = ge211::Text_sprite {high_score_text, sans30};
    }
};
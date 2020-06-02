#pragma once

#include <ge211.hxx>
#include "model.hxx"
#include <string>

extern ge211::Color const background_color, bird_color, coin_color, obstacle_color;
//extern ge211::Font const sans30;

class View
{
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    Model& model_;

    ge211::Rectangle_sprite background_;
    ge211::Circle_sprite bird_sprite_;
    ge211::Circle_sprite coin_sprite_;
    //sprites for obstacles will be created in view.cxx

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

};
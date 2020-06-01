#pragma once

#include <ge211.hxx>
#include "model.hxx"
#include <string>

class View
{
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    Model const& model_;

    ge211::Rectangle_sprite background_;
    ge211::Circle_sprite bird_sprite_;
    ge211::Circle_sprite coin_sprite_;
    //sprites for obstacles will be created in view.cxx

public:

    ///
    /// CONSTRUCTOR
    ///

    explicit View(Model const&);

    ///
    /// MEMBER FUNCTIONS
    ///

    void draw(ge211::Sprite_set& set);

    ge211::Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

};
#pragma once

#include "model.hxx"
#include "view.hxx"

class Controller : public ge211::Abstract_game
{
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    Model model_;
    View view_;

public:

    ///
    /// CONSTRUCTOR
    ///

    explicit Controller(Model&);

protected:
    ///
    /// Overridden member functions
    ///
    void on_key(ge211::Key key) override;
    void on_frame(double dt) override;

    // Delegated to view
    void draw(ge211::Sprite_set&) override;
    ge211::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;

};
#include "view.hxx"
#include <string>

ge211::Color const background_color {135, 206, 235};
ge211::Color const bird_color {255, 0, 0};
ge211::Color const coin_color {212, 175, 55};
ge211::Color const obstacle_color {0, 153, 0};

View::View(Model const& model)
        : model_(model)
        , background_({model.geometry_.scene_dims.width, model.geometry_.scene_dims.height}, background_color)
        , bird_sprite_(model.geometry_.bird_radius, bird_color)
        , coin_sprite_(model.geometry_.coin_radius, coin_color)
{ }

void View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(background_, {0, 0}, 0);
    set.add_sprite(bird_sprite_, model_.bird().top_left(), 1);
    for (Obstacle obstacle : model_.obstacles()) {
        //create and add sprites for top and bottom pipes in each obstacle
        ge211::Rectangle_sprite top_pipe_sprite({obstacle.width(), obstacle.top_pipe().height}, obstacle_color);
        ge211::Rectangle_sprite bottom_pipe_sprite({obstacle.width(), obstacle.bottom_pipe().height}, obstacle_color);
        set.add_sprite(top_pipe_sprite, obstacle.top_pipe().top_left(), 1);
        set.add_sprite(bottom_pipe_sprite, obstacle.bottom_pipe().top_left(), 1);

        //add coin sprite, if applicable
        if (obstacle.has_coin()) {
            set.add_sprite(coin_sprite_, obstacle.coin().top_left(), 1);
        }
    }
}

ge211::Dimensions View::initial_window_dimensions() const
{
    return model_.geometry_.scene_dims;
}


std::string View::initial_window_title() const
{
    return "Flappy Bird";
}
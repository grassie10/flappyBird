#include "view.hxx"
#include <string>

ge211::Color const background_color {135, 206, 235};
ge211::Color const bird_color {255, 0, 0};
ge211::Color const coin_color {212, 175, 55};
ge211::Color const obstacle_color {0, 153, 0};

View::View(Model& model)
        : model_(model)
        , background_({model.geometry_.scene_dims.width, model.geometry_.scene_dims.height}, background_color)
        , bird_sprite_(model.geometry_.bird_radius, bird_color)
        , coin_sprite_(model.geometry_.coin_radius, coin_color)
{
    update_sprites();
}

void View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(background_, {0, 0}, 0);
    set.add_sprite(bird_sprite_, model_.bird().top_left(), 1);

    for (Obstacle_data& ob_data : obstacle_sprites_) {
        set.add_sprite(ob_data.top_pipe_sprite, ob_data.top_pipe_position, 1);
        set.add_sprite(ob_data.bottom_pipe_sprite, ob_data.bottom_pipe_position, 1);

        // add the coin sprite for the given obstacle, if applicable
        if (ob_data.obstacle.has_coin() && !ob_data.obstacle.get_coin().is_collected()) {
            set.add_sprite(coin_sprite_, ob_data.obstacle.get_coin().top_left(), 1);
        }
    }

    //add score_sprite if round is over
    if (model_.game_end()) {
        set.add_sprite(score_sprite_, {model_.geometry_.scene_dims.width/2, model_.geometry_.scene_dims.height/2},
                2);
        set.add_sprite(high_score_sprite_, {model_.geometry_.scene_dims.width/2,
                                            (model_.geometry_.scene_dims.height/2) + 40},2);
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

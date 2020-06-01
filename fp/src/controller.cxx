#include "controller.hxx"

Controller::Controller(Model& model)
            : model_(model)
            , view_(model)
{ }

void Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code(' ')) {
        if (model_.game_end()) {
            model_.start();
        } else {
            model_.bird().boost_vertical(model_.geometry_.bird_boost);
        }
    }
}

void Controller::on_frame(double dt)
{
    model_.update();
}

void Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);
}

ge211::Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string Controller::initial_window_title() const
{
    return view_.initial_window_title();
}
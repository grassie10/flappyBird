#include "controller.hxx"

Controller::Controller(Geometry const& geometry)
            : model_(geometry, get_random())
            , view_(model_)
{ }

void Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code(' ')) {
        if (model_.game_end()) {
            model_.start();
        } else {
            model_.boost_bird();
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
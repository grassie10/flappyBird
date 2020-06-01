#include "model.hxx"
#include <catch.hxx>

// These tests should demonstrate at least six of the functional
// requirements.
//

TEST_CASE("bird hits top")
{
    Model m;
    m.bird_alive_ = true;

    m.bird_.y = 15;
    m.update();
    CHECK( m.bird_alive_ );
    m.bird_.y = 0;
    m.update();
    CHECK_FALSE ( m.bird_alive_ );

}

TEST_CASE("bird hits ground")
{
    Model m;
    m.bird_alive_ = true;

    m.bird_.y = m.scene_dims.y - 15;
    m.update();
    CHECK( m.bird_alive_ );
    m.bird_.y = m.scene_dims.y;
    m.update();
    CHECK_FALSE ( m.bird_alive_ );
}

TEST_CASE("bird hits obstacle")
{
    Model m;
    m.bird_alive_ = true;
    m.obstacles_.clear();

    struct Obstacle o;
    o.top_pipe = { 100, 0, 100, 300};
    o.bottom_pipe = {100, 400, 100, 100};

    m.bird_ = ge211::Position {50, 50};
    m.update();
    CHECK( m.bird_alive_ );
    m.bird_ = ge211::Position {150, 50};
    m.update();
    CHECK_FALSE( m.bird_alive_ );
}

TEST_CASE("collect coin")
{
    Model m;
    m.bird_alive_ = true;
    m.obstacles_.clear();
    m.coin_ = ge211::Position {100, 100};

    m.bird_ = ge211::Position {50, 50};
    m.update();
    CHECK( m.get_score() == 0 );
    CHECK( m.coin_alive_ );

    m.bird_ = ge211::Position {100, 100};
    m.update();
    CHECK( m.get_score() == 1 );
    CHECK_FALSE( m.coin_alive_ );
}

TEST_CASE("round stops when bird dies")
{
    Model m;
    m.bird_alive_ = true;

    CHECK_FALSE( m.game_end );
    m.bird_alive_ = false;
    CHECK( m.game_end );
}

TEST_CASE("updates and maintains high score")
{
    Model m;

    m.score = 5;
    m.bird_alive_ = false;
    m.update();
    CHECK( m.get_high_score() == 5 );

    m.score = 3;
    m.update();
    CHECK( m.get_high_score() == 5 );
}
#include "model.hxx"
#include <catch.hxx>

// These tests should demonstrate at least six of the functional
// requirements.

struct Random_test_access
{
    ge211::Random rnd;
};

struct Test_access
{
    Model& m_;

    Bird& bird()
    {
        return m_.bird_;
    }

    std::vector<Obstacle>& obstacles()
    {
        return m_.obstacles_;
    }
};
/*
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
*/
TEST_CASE("collect coin")
{
    Random_test_access rand;
    Geometry geometry;
    Model m(geometry, rand.rnd);
    Test_access t{m};
    m.start();
    t.obstacles().clear();
    Obstacle new_ob(m.geometry_, 100, 200, true);
    new_ob.set_position(100);
    t.obstacles().push_back(new_ob);

    CHECK( m.get_score() == 0 );
    CHECK( t.obstacles().size() == 1 );
    // check coin has correct position
    CHECK( t.obstacles()[0].coin.center_ == ge211::Position{110, 300});
    CHECK( t.obstacles()[0].coin.is_collected() == false );

    // coin isn't collected
    t.bird().center_ = ge211::Position {50, 50};
    m.update();
    CHECK( m.get_score() == 0 );
    CHECK( t.obstacles()[0].coin.is_collected() == false );
    // check that everything updated correctly
    CHECK( t.bird().center_ == ge211::Position {50, 60});
    CHECK( t.obstacles()[0].top_pipe().bottom_right() == ge211::Position {110, 100});
    CHECK( t.obstacles()[0].bottom_pipe().top_right() == ge211::Position {110, 500});
    CHECK( t.obstacles()[0].coin.center_ == ge211::Position{100, 300});
    CHECK( t.obstacles().size() == 2 );

    // coin is collected
    t.bird().center_ = ge211::Position {83, 283};
    m.update();
    CHECK( m.get_score() == 1 );
    CHECK( t.obstacles()[0].coin.is_collected() == true );
    // check that everything updated correctly
    CHECK( t.bird().center_ == ge211::Position {83, 293});
    CHECK( t.obstacles()[0].top_pipe().bottom_right() == ge211::Position {100, 100});
    CHECK( t.obstacles()[0].bottom_pipe().top_right() == ge211::Position {100, 500});
    CHECK( t.obstacles()[0].coin.center_ == ge211::Position{90, 300});
    CHECK( t.obstacles().size() == 2 );

    // score does not change when bird hits coin and obstacle.has_coin_ is false
    t.obstacles().clear();
    Obstacle new_ob2(m.geometry_, 250, 150, false);
    new_ob2.set_position(500);
    t.obstacles().push_back(new_ob2);

    CHECK( m.get_score() == 1 );
    CHECK( t.obstacles().size() == 1 );
    // check coin has correct position
    CHECK( t.obstacles()[0].coin.center_ == ge211::Position{510, 400});

    t.bird().center_ = ge211::Position {500, 390};
    m.update();
    CHECK( m.get_score() == 1 );
    // check that everything updated correctly
    CHECK( t.bird().center_ == ge211::Position {500, 400});
    CHECK( t.obstacles()[0].top_pipe().top_right() == ge211::Position {510, 0});
    CHECK( t.obstacles()[0].bottom_pipe().top_left() == ge211::Position {490, 550});
    CHECK( t.obstacles().size() == 2 );
}
/*
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
*/
// test if obstacles are removed and added to obstacles_ vector correctly
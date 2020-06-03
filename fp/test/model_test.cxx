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
TEST_CASE("bird hits top")
{
    Random_test_access rand;
    Geometry geometry;
    Model m(geometry, rand.rnd);
    Test_access t{m};
    t.bird().live_ = true;

    t.bird().center_.y = geometry.scene_dims.height/2;
    m.update();
    CHECK( t.bird().live_);
    t.bird().center_.y = - t.bird().velocity_.height*2;
    m.update();
    CHECK_FALSE ( t.bird().live_);

}

TEST_CASE("bird hits ground")
{
    Random_test_access rand;
    Geometry geometry;
    Model m(geometry, rand.rnd);
    Test_access t{m};
    t.bird().live_ = true;

    t.bird().center_.y = geometry.scene_dims.height/3;
    m.update();
    CHECK( t.bird().live_);
    t.bird().center_.y = geometry.scene_dims.height + 5;
    m.update();
    CHECK_FALSE ( t.bird().live_);
}

TEST_CASE("bird hits obstacle")
{
    Random_test_access rand;
    Geometry geometry;
    Model m(geometry, rand.rnd);
    Test_access t{m};
    t.bird().live_ = true;
    t.obstacles().clear();

    Obstacle new_ob(m.geometry_, 100, 200, true);
    new_ob.set_position(100);
    t.obstacles().push_back(new_ob);

    //hits bottom obstacle
    t.bird().center_ = ge211::Position {100, 495};
    m.update();
    CHECK_FALSE ( t.bird().live_);

    t.bird().live_ = true;
    //hits top obstacle
    t.bird().center_ = ge211::Position {100, 75};
    m.update();
    CHECK_FALSE ( t.bird().live_);

    // check nothing happens when model updates if bird is dead
    CHECK( t.bird().center_ == ge211::Position {100, 75} );
    CHECK( t.obstacles()[0].bottom_pipe().top_right() == ge211::Position {120, 500} );
    m.update();
    CHECK( t.bird().center_ == ge211::Position {100, 75} );
    CHECK( t.obstacles()[0].bottom_pipe().top_right() == ge211::Position {120, 500} );
}

TEST_CASE("bird passes obstacle") {
    Random_test_access rand;
    Geometry geometry;
    Model m(geometry, rand.rnd);
    Test_access t{m};
    t.bird().live_ = true;

    Obstacle new_ob(m.geometry_, 100, 200, false);
    new_ob.set_position(100);
    t.obstacles().push_back(new_ob);

    t.bird().center_ = ge211::Position {110, 280};
    m.update();
    CHECK( t.bird().live_);
}

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
    CHECK_FALSE( t.obstacles()[0].coin.is_collected() );

    // coin isn't collected
    t.bird().center_ = ge211::Position {50, 50};
    m.update();
    CHECK( m.get_score() == 0 );
    CHECK_FALSE( t.obstacles()[0].coin.is_collected() );
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
    CHECK( t.obstacles()[0].coin.is_collected() );
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

TEST_CASE("updates and maintains high score")
{
    Random_test_access rand;
    Geometry geometry;
    Model m(geometry, rand.rnd);
    Test_access t{m};

    // Round 1: get 2 points
    m.start();
    t.obstacles().clear();
    Obstacle new_ob(m.geometry_, 100, 100, true);
    new_ob.set_position(100);
    t.obstacles().push_back(new_ob);

    CHECK( m.get_score() == 0 );
    CHECK( m.get_high_score() == 0 );
    CHECK( t.obstacles()[0].coin.center_ == ge211::Position{110, 350});
    CHECK_FALSE( t.obstacles()[0].coin.is_collected() );

    // bird hits coin
    t.bird().center_ = ge211::Position {100, 331};
    m.update();
    CHECK( m.get_score() == 1 );
    CHECK( m.get_high_score() == 0 );
    CHECK( t.obstacles()[0].coin.is_collected() );
    CHECK( t.obstacles()[0].bottom_pipe().bottom_left() == ge211::Position {90, 700});

    m.update();
    CHECK( m.get_score() == 1 );
    CHECK( m.get_high_score() == 0 );
    CHECK( t.obstacles()[0].coin.is_collected() );
    CHECK( t.bird().center_ == ge211::Position {100, 351} );
    CHECK( t.obstacles()[0].bottom_pipe().top_right() == ge211::Position {100, 600});
    CHECK_FALSE( m.game_end() );

    // bird passes obstacle
    m.update();
    CHECK( m.get_score() == 2 );
    CHECK( m.get_high_score() == 0 );
    CHECK( t.bird().center_ == ge211::Position {100, 361} );
    CHECK( t.obstacles()[0].bottom_pipe().top_right() == ge211::Position {90, 600});
    CHECK_FALSE( m.game_end() );

    // bird hits bottom of screen and dies
    t.bird().center_ = ge211::Position {100, 700};
    m.update();
    CHECK( m.get_score() == 2 );
    CHECK( m.get_high_score() == 2 );
    CHECK( m.game_end() );

    // Round 2: Get 1 point
    m.start();
    t.obstacles().clear();
    new_ob = Obstacle(m.geometry_, 200, 200, true);
    new_ob.set_position(300);
    t.obstacles().push_back(new_ob);

    CHECK( m.get_score() == 0 );
    CHECK( m.get_high_score() == 2 );
    CHECK( t.obstacles()[0].coin.center_ == ge211::Position{310, 350});
    CHECK_FALSE( t.obstacles()[0].coin.is_collected() );

    // bird passes obstacle
    t.bird().center_ = ge211::Position {318, 400};
    m.update();
    CHECK( m.get_score() == 1 );
    CHECK( m.get_high_score() == 2 );
    CHECK_FALSE( t.obstacles()[0].coin.is_collected() );

    // bird hits bottom of screen and dies
    t.bird().center_ = ge211::Position {800, 700};
    m.update();
    CHECK( m.get_score() == 1 );
    CHECK( m.get_high_score() == 2 );   // high score doesn't change
    CHECK( m.game_end() );

    // Round 3: Get 3 points
    m.start();
    t.obstacles().clear();
    new_ob = Obstacle(m.geometry_, 100, 100, false);
    new_ob.set_position(300);
    t.obstacles().push_back(new_ob);
    new_ob = Obstacle(m.geometry_, 100, 100, false);
    new_ob.set_position(400);
    t.obstacles().push_back(new_ob);
    new_ob = Obstacle(m.geometry_, 100, 100, false);
    new_ob.set_position(500);
    t.obstacles().push_back(new_ob);

    CHECK( m.get_score() == 0 );
    CHECK( m.get_high_score() == 2 );

    // bird passes first obstacle
    t.bird().center_ = ge211::Position {320, 400};
    m.update();
    CHECK( m.get_score() == 1 );
    CHECK( m.get_high_score() == 2 );

    // bird passes second obstacle
    t.bird().center_ = ge211::Position {410, 400};
    m.update();
    CHECK( m.get_score() == 2 );
    CHECK( m.get_high_score() == 2 );

    // bird passes third obstacle
    t.bird().center_ = ge211::Position {500, 400};
    m.update();
    CHECK( m.get_score() == 3 );
    CHECK( m.get_high_score() == 2 );

    // bird hits obstacle and dies
    t.bird().center_ = ge211::Position {456, 595};
    m.update();
    CHECK( m.get_score() == 3 );
    CHECK( m.get_high_score() == 3 );
    CHECK( m.game_end() );
}

// test if obstacles are removed and added to obstacles_ vector correctly
TEST_CASE("obstacles removed and added to obstacles_ vector correctly")
{
    // NOT COMPLETED
    Random_test_access rand;
    Geometry geometry;
    Model m(geometry, rand.rnd);
    Test_access t{m};

    // Round 1: get 2 points
    m.start();
    t.obstacles().clear();
    Obstacle new_ob(m.geometry_, 100, 100, true);
    new_ob.set_position(100);
    t.obstacles().push_back(new_ob);
}
// check boosting the bird vertically
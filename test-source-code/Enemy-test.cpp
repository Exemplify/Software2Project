#include "doctest.h"
#include "../game-source-code/BackEndSystems/EnemyFactory.h"
#include "../game-source-code/FrontEndSystems/Enemy.h"
#include "../game-source-code/FrontEndSystems/Scene.h"
#include "../game-source-code/Vector2D.hpp"

TEST_CASE("Enemy Random Movement Test"){
    auto count =  0;
    while(count<3)
    {
        count = 2;
		EnemyFactory enemyFactory;
        auto enem_ptr = enemyFactory.getGameObject();
		auto enem = *std::dynamic_pointer_cast<Enemy>(enem_ptr);
        if (enem.getMoveType() == EnemyMoveType::linear && count == 0)
        {
            auto enemPosition1 = enem.getPosition();
            enem.Update();
            auto enemPosition2 = enem.getPosition();
            
            SUBCASE("Linear Movement Test")
            {
                CHECK(doctest::Approx(enemPosition2.rtpVector().at(0)) == enemPosition1.rtpVector().at(0)+100);
                CHECK(doctest::Approx(enemPosition2.rtpVector().at(1)) == enemPosition1.rtpVector().at(1));
                CHECK(doctest::Approx(enemPosition2.rtpVector().at(2)) == enemPosition1.rtpVector().at(2));
            }
            count++;
        }
        
        if (enem.getMoveType() == EnemyMoveType::spiral && count == 1)
        {
            auto enemPosition1 = enem.getPosition();
            enem.Update();
            auto enemPosition2 = enem.getPosition();
            
            SUBCASE("Spiral Movement Test")
            {
                CHECK(doctest::Approx(enemPosition2.rtpVector().at(0)) == enemPosition1.rtpVector().at(0)+10);
                CHECK(doctest::Approx(enemPosition2.rtpVector().at(1)) == enemPosition1.rtpVector().at(1)+M_PI);
                CHECK(doctest::Approx(enemPosition2.rtpVector().at(2)) == enemPosition1.rtpVector().at(2));
            }
            count++;
        }
        
        if (enem.getMoveType() == EnemyMoveType::parabolic && count == 2)
        {
            auto enemPosition1 = enem.getPosition();
            enem.Update();
            auto enemPosition2 = enem.getPosition();
            
            auto parabolic_a = -0.002824019;
            double deltaY = parabolic_a * pow((enemPosition1.xypVector().at(0)+ 100),2);
            SUBCASE("Parabolic Movement Test")
            {

                CHECK(doctest::Approx(enemPosition2.xypVector().at(0)) == enemPosition1.xypVector().at(0)+100);
                CHECK(doctest::Approx(enemPosition2.xypVector().at(1)) == deltaY);
                CHECK(doctest::Approx(enemPosition2.rtpVector().at(2)) == enemPosition1.rtpVector().at(2));
            }
            count++;
        }
    }
}
#include <gtest/gtest.h>
#include "SpaceBattle/Move/MovingObject.h"
#include "SpaceBattle/Interfaces/IMovingObject.h"
#include "SpaceBattle/Move/RotatingObject.h"
#include "SpaceBattle/Objects/SpaceShipObject.h"

//Тесты на валидном классе
TEST(MovingObjectTest, CheckGetPositionFunc) {
	int startX = 12;
	int startY = 5;
	int x = 0;
	int y = 0;

	MovingObject mob(startX, startY, 1, 1, 1);

	mob.getPosition(x, y);

	EXPECT_EQ(startX, x);
	EXPECT_EQ(startY, y);
}

TEST(MovingObjectTest, CheeckUpdatePositionFunc) {
	int startX = 12;
	int startY = 5;

	int newX = 0;
	int newY = 0;

	int velocityX = -1;
	int velocityY = 1;

	int endX = startX + velocityX;
	int endY = startY + velocityY;

	MovingObject mob(startX, startY, velocityX, velocityY, 1);
	mob.updatePosition();
	mob.getPosition(newX, newY);

	EXPECT_EQ(newX, endX);
	EXPECT_EQ(newY, endY);

}

TEST(MovingObjectTest, CheckGetSpeedFunc) {
	int speed = 7;
	int speedCheck;

	MovingObject mob(1, 1, 1, 1, speed);
	mob.getSpeed(speedCheck);

	EXPECT_EQ(speed, speedCheck);
}

TEST(MovingObjectTest, ConstructExceptionArgument) {
	EXPECT_THROW(MovingObject mob(1, 1, 2, 2, 1), std::invalid_argument);
}

//Тесты на не валидном классе через mock-объект
class BrokenMovingObject : public IMovingObject {
	private:
		int m_x, m_y, m_XVelocity, m_YVelocity;
	public:
		void getPosition(int& x, int& y) const override {
			throw std::runtime_error("Cannot read position of this object");
		}
		
		void getVectorVelocity(int& xVelocity, int& yVelocity) const override{
			xVelocity = m_XVelocity;
			yVelocity = m_YVelocity;
			throw std::runtime_error("Cannot read position of this object");
		}

		void updatePosition() override {
			try {
				int x, y;
				getPosition(x, y);
				x = x + m_XVelocity;
				y = y + m_YVelocity;
			}
			catch (const std::exception& e ) {
				throw std::runtime_error("Cannot uopdate position object");
			}
		}

		void getSpeed(int& speed) const override{}
};

//Попытка получить значение положэения
TEST(BrokenMovingObjectTest, GetPositionFunc) {
	BrokenMovingObject brob;
	int x, y;

	EXPECT_THROW(brob.getPosition(x, y), std::runtime_error);
}

//Попытка обновить позици, без возмжности получения значения скорости
TEST(BrokenMovingObjectTest, UpdatePositionFunc) {
	BrokenMovingObject brob;

	EXPECT_THROW(brob.updatePosition(), std::runtime_error);
}


//Тесты для класса RotatingObject
TEST(RotatingObjectTest, ConstructExceptionArgument) {
	EXPECT_THROW(RotatingObject rotb(-1), std::invalid_argument);
}

TEST(RotatingObjectTest, TurnCounterclockwise) {
	RotatingObject rotb(7);
	
	int startIndexRotate;
	rotb.getIndexRotate(startIndexRotate);

	rotb.turnCounterclockwise();

	int newIndexRotate;
	rotb.getIndexRotate(newIndexRotate);

	EXPECT_EQ(startIndexRotate, newIndexRotate + 1);
}

TEST(RotatingObjectTest, TurnCounterclockwiseAbowMinIndexRotate) {
	RotatingObject rotb(0);

	rotb.turnCounterclockwise();

	int maxIndexRotate;
	int indexRotate;

	rotb.getMaxIndexRotate(maxIndexRotate);
	rotb.getIndexRotate(indexRotate);

	EXPECT_EQ(indexRotate, maxIndexRotate);
}


TEST(RotatingObjectTest, TurnClockwise) {
	RotatingObject rotb(4);

	int startIndexRotate;
	rotb.getIndexRotate(startIndexRotate);

	rotb.turnClockwise();

	int newIndexRotate;
	rotb.getIndexRotate(newIndexRotate);

	EXPECT_EQ(startIndexRotate, newIndexRotate - 1);
}

TEST(RotatingObjectTest, TurnClockwiseBellowMaxIndexRotate) {
	RotatingObject rotb(7);

	int minIndexRotate;
	int indexRotate;

	rotb.turnClockwise();

	rotb.getMinIndexRotate(minIndexRotate);
	rotb.getIndexRotate(indexRotate);

	EXPECT_EQ(indexRotate, minIndexRotate);
}


//Тесты для композитного объекта космический корабль
TEST(SpaceShipObjectTest, GetPositionFunc) {
	SpaceShipObject ship(1, 1, 1, 1, 1, 1);
	int x, y;

	EXPECT_NO_THROW(ship.getPosition(x, y));
}

TEST(SpaceShipObjectTest, GetVelocityFunc) {
	SpaceShipObject ship(1, 1, 1, 1, 1, 1);
	int xVelocity, yVelocity;

	EXPECT_NO_THROW(ship.getVectorVelocity(xVelocity, yVelocity));
}

TEST(SpaceShipObjectTest, GetIndexRotateFunc) {
	SpaceShipObject ship(1, 1, 1, 1, 1, 1);
	int indexRotate;

	EXPECT_NO_THROW(ship.getIndexRotate(indexRotate));
}

TEST(SpaceShipObjectTest, UpdatePositionFunc) {
	SpaceShipObject ship(1, 1, 1, 1, 1, 1);

	EXPECT_NO_THROW(ship.updatePosition());
}

TEST(SpaceShipObjectTest, TurnClockwiseFunc) {
	SpaceShipObject ship(1, 1, 1, 1, 1, 1);

	EXPECT_NO_THROW(ship.turnClockwise());
}

TEST(SpaceShipObjectTest, TurnCounterclockwiseFunc) {
	SpaceShipObject ship(1, 1, 1, 1, 1, 1);

	EXPECT_NO_THROW(ship.turnCounterclockwis());
}

TEST(SpaceShipObjectTest, SetVectorVelocityFunc) {
	SpaceShipObject ship(1, 1, 1, 1, 2, 1);

	int startXVelocity, startYVelocity;
	ship.getVectorVelocity(startXVelocity, startYVelocity);

	ship.setVectorVelocity();

	int newXVelocity, newYVelocity;
	ship.getVectorVelocity(newXVelocity, newYVelocity);

	EXPECT_NE(startXVelocity, newXVelocity);
	EXPECT_NE(startYVelocity, newYVelocity);
}
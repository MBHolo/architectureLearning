
#include <iostream>
#include <vector>
#include "../src/SpaceBattle/Objects/SpaceShipObject.h"

int main()
{
    setlocale(LC_ALL, "RU");

    SpaceShipObject ship(1, 1, 1, 1, 6, 3);

    int x, y;
    int xVelocity, yVelocity;
    int indexRotate;
    int speed;

    ship.getPosition(x, y);
    std::cout << "Корабль. Позиция X: " << x << ", Позиция Y: " << y << std::endl;

    ship.getVectorVelocity(xVelocity, yVelocity);
    ship.getSpeed(speed);
    std::cout << "Скорость X: " << xVelocity << ", Скорость Y : " << yVelocity  << std::endl;

    int key = 1;

    while (key != 0) {

        std::cout << "Если хотите сдвинуть корабль, нажмите - 1" << std::endl;
        std::cout << "Если хотите повернуть корабль по часовой стрелке, нажмите - 2" << std::endl;
        std::cout << "Если хотите повернуть корабль против часовой стрелке, нажмите - 3" << std::endl;
        std::cin >> key;

        if (key == 1) {
            ship.updatePosition();
            ship.getPosition(x, y);
            ship.getVectorVelocity(xVelocity, yVelocity);
            ship.getSpeed(speed);
            std::cout << "Вектор скорости равен: ( " << xVelocity * speed << " , " << yVelocity * speed << " )" << std::endl;
            std::cout << "Корабль. Новая позиция X : " << x << " ,Новая позиция Y : " << y << std::endl;
            continue;
        }

        if (key == 2) {
            ship.turnClockwise();
            ship.getSpeed(speed);
            ship.setVectorVelocity();
            ship.getVectorVelocity(xVelocity, yVelocity);
            std::cout << "Вектор скорости равен: ( " << xVelocity * speed << " , " << yVelocity * speed << " )" << std::endl;
            std::cout << "Корабль. Новая позиция X : " << x << " ,Новая позиция Y : " << y << std::endl;
            continue;
        }

        if (key == 3) {
            ship.turnCounterclockwis();
            ship.getSpeed(speed);
            ship.setVectorVelocity();
            ship.getVectorVelocity(xVelocity, yVelocity);
            std::cout << "Вектор скорости равен: ( " << xVelocity * speed << " , " << yVelocity * speed << " )" << std::endl;
            std::cout << "Корабль. Новая позиция X : " << x << " ,Новая позиция Y : " << y << std::endl;
            continue;
        }


    }

    
    return 0;
}


#pragma once
#include "settings.h"

void CheckCollisVragi(Vragi& YopAngelo, Player& player) {
    if (player.sprite.getGlobalBounds().intersects(YopAngelo.sprite.getGlobalBounds()) && YopAngelo.health > 0) {
        sf::FloatRect playerBounds = player.sprite.getGlobalBounds();
        sf::FloatRect enemyBounds = YopAngelo.sprite.getGlobalBounds();

        // ���������� ����������� �������� �� ���� X � Y
        float intersectX = std::max(0.f, std::min(playerBounds.left + playerBounds.width, enemyBounds.left + enemyBounds.width) - std::max(playerBounds.left, enemyBounds.left));
        float intersectY = std::max(0.f, std::min(playerBounds.top + playerBounds.height, enemyBounds.top + enemyBounds.height) - std::max(playerBounds.top, enemyBounds.top));

        // ����������, �� ����� ��� ������� ������������ ������
        if (intersectX > intersectY) {
            if (playerBounds.top < enemyBounds.top) {
                // ����� ��������� ������ �� �����, ���������� ������ �����, � ����� ����
                player.sprite.move(0.f, -intersectY);
              
            }
            else {
                // ����� ��������� ����� �� �����, ���������� ������ ����, � ����� �����
                player.sprite.move(0.f, intersectY);
               
            }
        }
        else {
            if (playerBounds.left < enemyBounds.left) {
                // ����� ��������� ����� �� �����, ���������� ������ �����, � ����� ������
                player.sprite.move(-intersectX, 0.f);
               
            }
            else {
                // ����� ��������� ������ �� �����, ���������� ������ ������, � ����� �����
                player.sprite.move(intersectX, 0.f);
              
            }
        }
    }
}

void CheckCollisNPC(NPC& YopAngelo, Player& player) {
    if (player.sprite.getGlobalBounds().intersects(YopAngelo.sprite.getGlobalBounds())) {
        sf::FloatRect playerBounds = player.sprite.getGlobalBounds();
        playerBounds.left += 5.f;
        playerBounds.width -= 10.f;
        playerBounds.top += 50.f;
        playerBounds.height -= 50.f;

        if (playerBounds.intersects(YopAngelo.sprite.getGlobalBounds())) {
            sf::FloatRect enemyBounds = YopAngelo.sprite.getGlobalBounds();

            // ���������� ����������� �������� �� ���� X � Y
            float intersectX = std::max(0.f, std::min(playerBounds.left + playerBounds.width, enemyBounds.left + enemyBounds.width) - std::max(playerBounds.left, enemyBounds.left));
            float intersectY = std::max(0.f, std::min(playerBounds.top + playerBounds.height, enemyBounds.top + enemyBounds.height) - std::max(playerBounds.top, enemyBounds.top));

            // ����������, �� ����� ��� ������� ������������ ������
            if (intersectX > intersectY) {
                if (playerBounds.top < enemyBounds.top) {
                    // ����� ��������� ������ �� �����, ���������� ������ �����, � ����� ����
                    player.sprite.move(0.f, -intersectY);

                }
                else {
                    // ����� ��������� ����� �� �����, ���������� ������ ����, � ����� �����
                    player.sprite.move(0.f, intersectY);

                }
            }
            else {
                if (playerBounds.left < enemyBounds.left) {
                    // ����� ��������� ����� �� �����, ���������� ������ �����, � ����� ������
                    player.sprite.move(-intersectX, 0.f);

                }
                else {
                    // ����� ��������� ������ �� �����, ���������� ������ ������, � ����� �����
                    player.sprite.move(intersectX, 0.f);

                }
            }
        }
    }
}


void CheckCollisMap(Map& YopAngelo, Player& player) {
    if (player.sprite.getGlobalBounds().intersects(YopAngelo.sprite.getGlobalBounds())) {
        sf::FloatRect playerBounds = player.sprite.getGlobalBounds();
        playerBounds.left += 5.f;
        playerBounds.width -= 10.f;
        playerBounds.top += 50.f;
        playerBounds.height -= 50.f;

        if (playerBounds.intersects(YopAngelo.sprite.getGlobalBounds())) {
            sf::FloatRect enemyBounds = YopAngelo.sprite.getGlobalBounds();

            // ���������� ����������� �������� �� ���� X � Y
            float intersectX = std::max(0.f, std::min(playerBounds.left + playerBounds.width, enemyBounds.left + enemyBounds.width) - std::max(playerBounds.left, enemyBounds.left));
            float intersectY = std::max(0.f, std::min(playerBounds.top + playerBounds.height, enemyBounds.top + enemyBounds.height) - std::max(playerBounds.top, enemyBounds.top));

            // ����������, �� ����� ��� ������� ������������ ������
            if (intersectX > intersectY) {
                if (playerBounds.top < enemyBounds.top) {
                    // ����� ��������� ������ �� �����, ���������� ������ �����, � ����� ����
                    player.sprite.move(0.f, -intersectY);

                }
                else {
                    // ����� ��������� ����� �� �����, ���������� ������ ����, � ����� �����
                    player.sprite.move(0.f, intersectY);

                }
            }
            else {
                if (playerBounds.left < enemyBounds.left) {
                    // ����� ��������� ����� �� �����, ���������� ������ �����, � ����� ������
                    player.sprite.move(-intersectX, 0.f);

                }
                else {
                    // ����� ��������� ������ �� �����, ���������� ������ ������, � ����� �����
                    player.sprite.move(intersectX, 0.f);

                }
            }
        }
    }
}

  /*��� ����������� 
  void CheckCollisVragi(Vragi& YopAngelo, Player& player) {
    if (player.sprite.getGlobalBounds().intersects(YopAngelo.sprite.getGlobalBounds()) && YopAngelo.health > 0) {
        sf::FloatRect playerBounds = player.sprite.getGlobalBounds();
        sf::FloatRect enemyBounds = YopAngelo.sprite.getGlobalBounds();

        // ���������� ����������� �������� �� ���� X � Y
        float intersectX = std::max(0.f, std::min(playerBounds.left + playerBounds.width, enemyBounds.left + enemyBounds.width) - std::max(playerBounds.left, enemyBounds.left));
        float intersectY = std::max(0.f, std::min(playerBounds.top + playerBounds.height, enemyBounds.top + enemyBounds.height) - std::max(playerBounds.top, enemyBounds.top));

        // ����������, �� ����� ��� ������� ������������ ������
        if (intersectX > intersectY) {
            if (playerBounds.top < enemyBounds.top) {
                // ����� ��������� ������ �� �����, ���������� ������ �����, � ����� ����
                player.sprite.move(0.f, -intersectY);
                YopAngelo.sprite.move(0.f, intersectY);
            }
            else {
                // ����� ��������� ����� �� �����, ���������� ������ ����, � ����� �����
                player.sprite.move(0.f, intersectY);
                YopAngelo.sprite.move(0.f, -intersectY);
            }
        }
        else {
            if (playerBounds.left < enemyBounds.left) {
                // ����� ��������� ����� �� �����, ���������� ������ �����, � ����� ������
                player.sprite.move(-intersectX, 0.f);
                YopAngelo.sprite.move(intersectX, 0.f);
            }
            else {
                // ����� ��������� ������ �� �����, ���������� ������ ������, � ����� �����
                player.sprite.move(intersectX, 0.f);
                YopAngelo.sprite.move(-intersectX, 0.f);
            }
        }
    }
}*/
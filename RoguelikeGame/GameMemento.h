#pragma once
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

namespace RoguelikeSpace
{
    struct GameMemento
    {
        sf::Vector2f ballPosition;
        sf::Vector2f ballVelocity;
        sf::Vector2f platformPosition;
        int score = 0;
        int currentLevel = 0;
    };
}
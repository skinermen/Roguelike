﻿#pragma once
#include <SFML/Graphics.hpp>

namespace RogaliqueGame
{
    class GameObject
    {
    public:
        virtual ~GameObject() = default;
        
        virtual void Update(sf::RenderWindow& window, float deltaTime) = 0;
        virtual void Draw(sf::RenderWindow& window) const = 0;
        
        virtual void SetPosition(const sf::Vector2f& pos) = 0;
        virtual sf::Vector2f GetPosition() const = 0;
    };
}
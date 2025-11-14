#include <algorithm>
#include <cmath>

#include "Player.h"
#include "Settings.h"

namespace RoguelikeSpace
{
    namespace
    {
        sf::Vector2f Normalize(const sf::Vector2f& vector)
        {
            const float lengthSquared = vector.x * vector.x + vector.y * vector.y;
            if (lengthSquared == 0.f)
            {
                return sf::Vector2f();
            }

            const float length = std::sqrt(lengthSquared);
            return sf::Vector2f(vector.x / length, vector.y / length);
        }
    }

    Player::Player()
    {
        const float radius = 16.f;
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(radius, radius);

        SetPosition({ SETTINGS.SCREEN_WIDTH * 0.5f, SETTINGS.SCREEN_HEIGHT * 0.5f });
    }

    void Player::Update(sf::RenderWindow&, float deltaTime)
    {
        sf::Vector2f direction;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direction.y -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction.y += 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direction.x -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direction.x += 1.f;
        }

        if (direction.x != 0.f || direction.y != 0.f)
        {
            direction = Normalize(direction);
            const sf::Vector2f newPosition = shape.getPosition() + direction * movementSpeed * deltaTime;
            const float radius = shape.getRadius();
            const float minX = radius;
            const float maxX = SETTINGS.SCREEN_WIDTH - radius;
            const float minY = radius;
            const float maxY = SETTINGS.SCREEN_HEIGHT - radius;

            sf::Vector2f clampedPosition = newPosition;
            clampedPosition.x = std::min(std::max(clampedPosition.x, minX), maxX);
            clampedPosition.y = std::min(std::max(clampedPosition.y, minY), maxY);
            shape.setPosition(clampedPosition);
        }
    }

    void Player::Draw(sf::RenderWindow& window) const
    {
        window.draw(shape);
    }

    void Player::SetPosition(const sf::Vector2f& pos)
    {
        const float radius = shape.getRadius();
        const float minX = radius;
        const float maxX = SETTINGS.SCREEN_WIDTH - radius;
        const float minY = radius;
        const float maxY = SETTINGS.SCREEN_HEIGHT - radius;

        sf::Vector2f clampedPosition = pos;
        clampedPosition.x = std::min(std::max(clampedPosition.x, minX), maxX);
        clampedPosition.y = std::min(std::max(clampedPosition.y, minY), maxY);
        shape.setPosition(clampedPosition);
    }

    sf::Vector2f Player::GetPosition() const
    {
        return shape.getPosition();
    }
}
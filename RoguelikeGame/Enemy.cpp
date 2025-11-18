#include <algorithm>
#include <cmath>
#include <random>

#include "Enemy.h"
#include "Settings.h"

namespace RoguelikeSpace
{
    namespace
    {
        float DistanceSquared(const sf::Vector2f& lhs, const sf::Vector2f& rhs)
        {
            const float dx = lhs.x - rhs.x;
            const float dy = lhs.y - rhs.y;
            return dx * dx + dy * dy;
        }

        sf::Vector2f ClampToBounds(const sf::Vector2f& position, float radius)
        {
            const float minX = SETTINGS.WALL_THICKNESS + radius;
            const float maxX = SETTINGS.SCREEN_WIDTH - SETTINGS.WALL_THICKNESS - radius;
            const float minY = SETTINGS.WALL_THICKNESS + radius;
            const float maxY = SETTINGS.SCREEN_HEIGHT - SETTINGS.WALL_THICKNESS - radius;

            sf::Vector2f clamped = position;
            clamped.x = std::min(std::max(clamped.x, minX), maxX);
            clamped.y = std::min(std::max(clamped.y, minY), maxY);
            return clamped;
        }

        sf::Vector2f Normalize(const sf::Vector2f& vector)
        {
            const float lengthSquared = vector.x * vector.x + vector.y * vector.y;
            if (lengthSquared == 0.f)
            {
                return {};
            }

            const float length = std::sqrt(lengthSquared);
            return { vector.x / length, vector.y / length };
        }
    }

    Enemy::Enemy()
    {
        const float radius = 12.f;
        shape.setRadius(radius);
        shape.setFillColor(sf::Color(220, 20, 60));
        shape.setOrigin(radius, radius);

        SetPosition({ radius, radius });
    }

    void Enemy::Update(sf::RenderWindow&, float deltaTime)
    {
        if (!isChasing)
        {
            return;
        }

        const sf::Vector2f currentPosition = shape.getPosition();
        const sf::Vector2f toPlayer = targetPosition - currentPosition;
        const sf::Vector2f direction = Normalize(toPlayer);
        if (direction.x == 0.f && direction.y == 0.f)
        {
            return;
        }

        const sf::Vector2f movement = direction * movementSpeed * deltaTime;
        sf::Vector2f newPosition = currentPosition + movement;

        const float distanceToPlayerSquared = DistanceSquared(currentPosition, targetPosition);
        if (DistanceSquared(currentPosition, newPosition) > distanceToPlayerSquared)
        {
            newPosition = targetPosition;
        }

        SetPosition(newPosition);
    }

    void Enemy::Draw(sf::RenderWindow& window) const
    {
        window.draw(shape);
    }

    void Enemy::SetPosition(const sf::Vector2f& pos)
    {
        const sf::Vector2f clamped = ClampToBounds(pos, shape.getRadius());
        shape.setPosition(clamped);
    }

    sf::Vector2f Enemy::GetPosition() const
    {
        return shape.getPosition();
    }

    void Enemy::UpdatePlayerPosition(const sf::Vector2f& playerPosition)
    {
        targetPosition = playerPosition;

        const float radiusSquared = detectionRadius * detectionRadius;
        const float distanceSquared = DistanceSquared(shape.getPosition(), playerPosition);
        isChasing = distanceSquared <= radiusSquared;
    }

    void Enemy::SpawnAwayFrom(const sf::Vector2f& positionToAvoid, float minDistance)
    {
        const sf::Vector2f spawnPosition = GenerateSpawnPosition(positionToAvoid, minDistance);
        SetPosition(spawnPosition);
    }

    sf::Vector2f Enemy::GenerateSpawnPosition(const sf::Vector2f& positionToAvoid, float minDistance) const
    {
        static std::mt19937 engine(std::random_device{}());
        const float radius = shape.getRadius();
        std::uniform_real_distribution<float> distX(radius, SETTINGS.SCREEN_WIDTH - radius);
        std::uniform_real_distribution<float> distY(radius, SETTINGS.SCREEN_HEIGHT - radius);

        const float minDistanceSquared = minDistance * minDistance;
        constexpr int maxAttempts = 64;

        for (int attempt = 0; attempt < maxAttempts; ++attempt)
        {
            const sf::Vector2f candidate(distX(engine), distY(engine));
            if (DistanceSquared(candidate, positionToAvoid) >= minDistanceSquared)
            {
                return candidate;
            }
        }

        const sf::Vector2f center(SETTINGS.SCREEN_WIDTH * 0.5f, SETTINGS.SCREEN_HEIGHT * 0.5f);
        const sf::Vector2f direction = positionToAvoid - center;
        sf::Vector2f fallback = positionToAvoid + sf::Vector2f(direction.x >= 0.f ? -minDistance : minDistance,
            direction.y >= 0.f ? -minDistance : minDistance);
        return ClampToBounds(fallback, radius);
    }
}
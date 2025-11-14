#pragma once
#include "GameObject.h"

namespace RoguelikeSpace
{
    class Enemy final : public GameObject
    {
    public:
        Enemy();

        void Update(sf::RenderWindow& window, float deltaTime) override;
        void Draw(sf::RenderWindow& window) const override;

        void SetPosition(const sf::Vector2f& pos) override;
        sf::Vector2f GetPosition() const override;

        void SpawnAwayFrom(const sf::Vector2f& positionToAvoid, float minDistance);

    private:
        sf::Vector2f GenerateSpawnPosition(const sf::Vector2f& positionToAvoid, float minDistance) const;

        sf::CircleShape shape;
    };
}
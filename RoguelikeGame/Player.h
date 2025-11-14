#pragma once
#include "GameObject.h"

namespace RoguelikeSpace
{
    class Player final : public GameObject
    {
    public:
        Player();

        void Update(sf::RenderWindow& window, float deltaTime) override;
        void Draw(sf::RenderWindow& window) const override;

        void SetPosition(const sf::Vector2f& pos) override;
        sf::Vector2f GetPosition() const override;

    private:
        sf::CircleShape shape;
        float movementSpeed = 220.f;
    };
}
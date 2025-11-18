#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace RoguelikeSpace
{
    class Walls
    {
    public:
        Walls();

        void Draw(sf::RenderWindow& window) const;
        float GetThickness() const { return thickness; }
        bool IsKinematic() const { return isKinematic; }

    private:
        void BuildWalls();

        sf::Texture texture;
        std::vector<sf::Sprite> tiles;
        float thickness = 0.f;
        const bool isKinematic = true;
    };
}
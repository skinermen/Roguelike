#include "Walls.h"

#include <iostream>

#include "Settings.h"

namespace RoguelikeSpace
{
    Walls::Walls()
    {
        const std::string texturePath = SETTINGS.RESOURCES_PATH + "wall.png";
        if (!texture.loadFromFile(texturePath))
        {
            std::cerr << "Failed to load wall texture from " << texturePath << '\n';
            return;
        }

        thickness = static_cast<float>(texture.getSize().x);
        BuildWalls();
    }

    void Walls::BuildWalls()
    {
        tiles.clear();

        if (thickness <= 0.f)
        {
            return;
        }

        const float width = SETTINGS.SCREEN_WIDTH;
        const float height = SETTINGS.SCREEN_HEIGHT;

        for (float x = 0.f; x < width; x += thickness)
        {
            sf::Sprite top(texture);
            top.setPosition(x, 0.f);
            tiles.emplace_back(top);

            sf::Sprite bottom(texture);
            bottom.setPosition(x, height - thickness);
            tiles.emplace_back(bottom);
        }

        for (float y = thickness; y < height - thickness; y += thickness)
        {
            sf::Sprite left(texture);
            left.setPosition(0.f, y);
            tiles.emplace_back(left);

            sf::Sprite right(texture);
            right.setPosition(width - thickness, y);
            tiles.emplace_back(right);
        }
    }

    void Walls::Draw(sf::RenderWindow& window) const
    {
        for (const auto& tile : tiles)
        {
            window.draw(tile);
        }
    }
}
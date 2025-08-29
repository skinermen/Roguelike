﻿#pragma once
#include <SFML/Graphics.hpp>
#include "MenuBase.h"

namespace RogaliqueGame
{
    class MainMenu : public MenuBase
    {
    public:
        void Init(const sf::Font& font) override;
        void Draw(sf::RenderWindow& window) override;
        void OnConfirm() override;
    };
}

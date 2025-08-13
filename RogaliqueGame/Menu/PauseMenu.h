#pragma once
#include "MenuBase.h"

namespace RogaliqueGame
{
    class PauseMenu : public MenuBase
    {
    public:
        void Init(const sf::Font& font) override;
        void Draw(sf::RenderWindow& window) override;
        void OnConfirm() override;
    };
}
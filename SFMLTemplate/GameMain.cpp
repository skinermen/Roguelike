#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"

using namespace SpaceRogalique;

int main()
{
	SpaceEngine::RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "Rogalique"));
	SpaceEngine::ResourceSystem::Instance()->LoadTexture("ball", "Resources/Textures/ball.png");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();
	
	SpaceEngine::Engine::Instance()->Run();
}



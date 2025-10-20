#include "Player.h"
#include "ResourceSystem.h"

namespace SpaceRogalique
{
	Player::Player()
	{
		gameObject = SpaceEngine::GameWorld::Instance()->CreateGameObject();
		auto playerRenderer = gameObject->AddComponent<SpaceEngine::SpriteRendererComponent>();

		//playerRenderer->SetTexture(*SpaceEngine::ResourceSystem::Instance()->GetTextureShared("ball"));
		//playerRenderer->SetPixelSize(32, 32);

		auto playerCamera = gameObject->AddComponent<SpaceEngine::CameraComponent>();
		playerCamera->SetWindow(&SpaceEngine::RenderSystem::Instance()->GetMainWindow());
		playerCamera->SetBaseResolution(1280, 720);

		auto playerInput = gameObject->AddComponent<SpaceEngine::InputComponent>();
	}

	SpaceEngine::GameObject* Player::GetGameObject()
	{
		return gameObject;
	}
}

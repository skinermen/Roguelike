#pragma once

#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"

namespace SpaceRogalique
{
	class Player
	{
	public:
		Player();
		SpaceEngine::GameObject* GetGameObject();

	private:
		SpaceEngine::GameObject* gameObject;
	};
}


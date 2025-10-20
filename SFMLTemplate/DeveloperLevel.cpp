#include "DeveloperLevel.h"

using namespace SpaceEngine;

namespace SpaceRogalique
{
	void DeveloperLevel::Start()
	{
		player = std::make_shared<Player>();
	}

	void DeveloperLevel::Restart()
	{
		Stop();
		Start();
	}

	void DeveloperLevel::Stop()
	{
		GameWorld::Instance()->Clear();
	}
}

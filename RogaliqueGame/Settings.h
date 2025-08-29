#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace RogaliqueGame
{
	class GameWorld
	{
	private:
		GameWorld() = default;

	public:
		static GameWorld& Instance()
		{
			static GameWorld gameWorld;
			return gameWorld;
		}
		
		const std::string GAME_NAME = "RogaliqueGame";
		const std::string RESOURCES_PATH = "Resources/";
		const std::string FONT_PATH = RESOURCES_PATH + "Fonts/Roboto-Regular.ttf";
		const std::string LEVELS_CONFIG_PATH = "levels.txt";
		const std::string LEADERBOARD_FILENAME = "leaderboard.txt";
		const std::string DEFAULT_NAME = "XYZ";
		
		// Size
		const int LEADERBOARD_HEIGHT = 58;
		const int SIZE_LEADERBOARD = 10;
		const int SIZE_MINI_LEADERBOARD = 3;
		const int BORDER_SIZE = 10;
		const float SCREEN_WIDTH = 800.f;
		const float SCREEN_HEIGHT = 600.f;
		
		// Other
		const float PAUSE_LENGTH = 1.f;
		const float MOUSE_MOVE_THRESHOLD = 1.f; // Threshold for determining the mouse movement (in pixels)
		const int INITIAL_LIVES = 3;
	};
}
#define SETTINGS RogaliqueGame::GameWorld::Instance()


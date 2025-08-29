#include <random>

#include "Game.h"
#include "Application.h"
#include "GameState.h"

namespace RogaliqueGame
{
	Game::Game() { Init(); } 
	Game::~Game() = default;

	bool Game::hasGameStarted = false;
	void Game::ResetGameStartedFlag() { hasGameStarted = false; }

	void Game::Init()
	{
		ui.Init();
		ui.SetNextLevelCallback([this]() { StartNextLevel(); });
		hasGameStarted = false;
		STATES.SwitchState(GameState::MainMenu);
	}

	void Game::InitStartNewGame()
	{
		lives = SETTINGS.INITIAL_LIVES;
		ui.UpdateLives(lives);
		SaveState();
	}

	void Game::StartNextLevel()
	{
		++currentLevelIndex;
		lives = SETTINGS.INITIAL_LIVES;
		ui.UpdateLives(lives);
		SaveState();
	}

	void Game::Update(float currentTime, sf::RenderWindow& window)
	{
		GameState currentState = STATES.GetCurrentState();
		GameState previousState = STATES.GetPreviousState();
	
		if (currentState == GameState::Exit)
			{ Shutdown(window); return; }

		if (currentState == GameState::MainMenu)
			{ hasGameStarted = false; }

		if (currentState == GameState::Playing && !hasGameStarted)
		{
			InitStartNewGame();
			lastUpdateTime = currentTime;
			hasGameStarted = true;
		}
		else if (currentState == GameState::Playing && previousState == GameState::PauseMenu)
			{ lastUpdateTime = currentTime; }

		float deltaTime = currentTime - lastUpdateTime;
		lastUpdateTime = currentTime;

		if (currentState == GameState::Playing)
			{ UpdatePlayingState(window, deltaTime); }
	}

	void Game::UpdatePlayingState(sf::RenderWindow& window, float deltaTime)
	{
		HandleCollisions();
		
		ui.UpdateLives(lives);
	}
	
	void Game::HandleEvent(const sf::Event& event)
	{
		switch (STATES.GetCurrentState())
		{
		case GameState::MainMenu:
		case GameState::PauseMenu:
		case GameState::GameOver:
		case GameState::Options:
		case GameState::Winner:
		case GameState::ConfirmationMenu:
		case GameState::NameInputMenu:
		ui.HandleEvent(event);
			break;

		case GameState::Playing:
			if (event.key.code == sf::Keyboard::P)
			{
				// STATES.PushState(GameState::PauseMenu);
				// ui.ResetSelectionForState(GameState::PauseMenu);
			}
			if (event.key.code == sf::Keyboard::Escape)
			{
				STATES.PushState(GameState::MainMenu);
				ui.ResetSelectionForState(GameState::MainMenu);
			}
			break;
			
		case GameState::Leaderboard:
			if (event.key.code == sf::Keyboard::B)
			{
				STATES.SwitchState(GameState::MainMenu);
				ui.ResetSelectionForState(GameState::Leaderboard);
			}
			break;
			
		default:
			break;
		}
	}

	void Game::HandleCollisions()
	{
		static std::default_random_engine eng(std::random_device{}());
		static std::uniform_real_distribution<float> dist(0.f, 1.f);
	}

	void Game::SaveState()
	{
		savedState.currentLevel = currentLevelIndex;
	}

	void Game::RestoreState()
	{
		
	}

	void Game::Draw(sf::RenderWindow& window)
	{		
		ui.Draw(window);
	}

	void Game::Shutdown(sf::RenderWindow& window)
	{
		window.close();
	}
}


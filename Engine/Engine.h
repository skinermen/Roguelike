#pragma once

#include "SFML/Graphics.hpp"

namespace EngineSpace
{
	class Engine
	{
	public:
		Engine(const Engine& app) = delete;
		Engine& operator= (const Engine&) = delete;

		static Engine* Instance();

		void Run();

	private:
		Engine();
		~Engine() = default;
	};
}
#pragma once

namespace EngineSpace
{
	class ColliderComponent;
	struct Trigger
	{
	public:
		Trigger(ColliderComponent* newFirst, ColliderComponent* newSecond) :
			first(newFirst), second(newSecond) {
		};
	private:
		ColliderComponent* first;
		ColliderComponent* second;
	};
}
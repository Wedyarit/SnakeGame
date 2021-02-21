#pragma once

// Enumaration classes //
namespace Game
{
	enum class CellType
	{
		FOOD, EMPTY
	};

	enum class Direction
	{
		NONE,
		RIGHT,
		LEFT,
		UP,
		DOWN
	};

	enum class GameStatus
	{
		ACTIVE,
		INACTIVE,
		IN_MENU
	};
}
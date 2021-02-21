#pragma once
#include "View/View.h"
#include "Utils/GameOptions.h"
#include "Model.h"
#include <chrono>
#include <thread>

namespace Utils
{
	class ThreadManager
	{
	private:
		char _key;

	public:
		// Constructor
		ThreadManager()
		{
			this->_key = '\0';
			std::thread keyListener(View::View::control, std::ref(this->_key));
			std::thread gameCycle(Model::gameCycle, std::ref(_key));
			keyListener.join();
			gameCycle.join();
		}
	};
}
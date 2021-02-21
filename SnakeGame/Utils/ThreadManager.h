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
		char key;

	public:
		ThreadManager()
		{
			this->key = '\0';
			std::thread keyListener(View::View::control, std::ref(this->key));
			std::thread gameCycle(Model::gameCycle, std::ref(key));
			keyListener.join();
			gameCycle.join();
		}
	};
}
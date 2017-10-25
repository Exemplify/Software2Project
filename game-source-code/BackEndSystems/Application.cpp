#include "Application.h"

Application::Application(std::shared_ptr<RepositioryInterface> repository, std::shared_ptr<GameManager> gameManager)
{
	_repository = repository;
	if(gameManager == nullptr)
	{
		_gameManager = std::make_shared<GameManager>(repository);
	}
	else
	{
		_gameManager = gameManager;
	}
}

const std::shared_ptr<RepositioryInterface> Application::getGameRepository()
{
	return _repository;
}

void Application::LoadScene(int index)
{
	_gameManager->LoadScene(index);
}
void Application::CloseApplication()
{
	_gameManager->Exit();
}
void Application::RunApplication()
{
	_gameManager->GameLoop();
}
const unsigned int Application::currentSceneIndex()
{
	return _gameManager->getSceneIndex();
}

std::shared_ptr<RepositioryInterface> Application::_repository = nullptr;
std::shared_ptr<GameManager> Application::_gameManager = nullptr;
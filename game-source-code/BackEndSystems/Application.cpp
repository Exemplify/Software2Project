#include "Application.h"

Application::Application(std::shared_ptr<RepositioryInterface> repository)
{
	if(_repository == nullptr)
	{
		_repository = repository;
		_gameManager = std::make_shared<GameManager>(repository);
	}
	else 
	{
		throw MultipleRepositoryIntialisations();
	}
}
const std::shared_ptr<RepositioryInterface> Application::getGameRepository()
{
	return _repository;
}
std::shared_ptr<RepositioryInterface> Application::_repository = nullptr;
std::shared_ptr<GameManager> Application::_gameManager = nullptr;

void InitialiseApplication(std::shared_ptr<RepositioryInterface> repository);
const std::shared_ptr<RepositioryInterface> getGameRepository();
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
#include "Application.h"

void Application::InitialiseApplication(std::shared_ptr<RepositioryInterface> repository)
{
	if(_repository == nullptr)
	{
		_repository = repository;
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
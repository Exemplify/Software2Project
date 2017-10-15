#ifndef APPLICATION_INTER_H 
#define APPLICATION_INTER_H

#include "RepositoryInterface.h"
#include "GameManager.h"
#include <memory>
#include "DatabaseInterface.h"

class MultipleRepositoryIntialisations{};

class Application
{
public:
	Application(std::shared_ptr<RepositioryInterface> repository);
	static const std::shared_ptr<RepositioryInterface> getGameRepository();
	static void LoadScene(int index);
	static void CloseApplication();
	void RunApplication();
private:
	static std::shared_ptr<RepositioryInterface> _repository;
	static std::shared_ptr<GameManager> _gameManager;
};
#endif 
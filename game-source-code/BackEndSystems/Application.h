#ifndef APPLICATION_INTER_H 
#define APPLICATION_INTER_H

#include "RepositoryInterface.h"
#include <memory>
#include "DatabaseInterface.h"

class MultipleRepositoryIntialisations{};

class Application
{
public:
	static void InitialiseApplication(std::shared_ptr<RepositioryInterface> repository);
	static const std::shared_ptr<RepositioryInterface> getGameRepository();
//	static void LoadScene(int index);
//	static void Exit();
private:
	static std::shared_ptr<RepositioryInterface> _repository;
};
#endif 
#include "EnemyController.h"
#include "Character.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/GameTime.h"
#include <memory>
#include <assert.h> 
#include "Enemy.h"


/// will need to be modified to incorporate the delay component
// Default constructor used to initialise enumerator type
EnemyController::EnemyController(unsigned int max_enemies, double enemySpawnDelay):
GameObject(),
 MAX_NUMBER_OF_ENEMIES{max_enemies},
ENEMY_SPAWN_DELAY{enemySpawnDelay}
{
	_timeBetweenSpawns = ENEMY_SPAWN_DELAY;
	_type = GameObjectType::enemyController;
}
void EnemyController::Update()
{
	SpawnEnemyCountDown();
}

// instantiates an enemy into the current scene after a certain time has passed
void EnemyController::SpawnEnemyCountDown()
{
	/// needs to be replaced with delay functions
	auto deltaTime = GameTime::getDeltaTime();
	_timeBetweenSpawns -= deltaTime;
	// ensures that only the maximum number of enemies is spawned
	if(_timeBetweenSpawns <= 0 && enemyCount < MAX_NUMBER_OF_ENEMIES)
	{
		// spawns an enemy and resets the delay
		SpawnEnemy();
		_timeBetweenSpawns = ENEMY_SPAWN_DELAY;
	}
}

// adds an enemy object to the current list of gameobjects in the specific scne
void EnemyController::SpawnEnemy()
{
	/// needs to be updated to use _scene variable from GameObject 
	auto scene = GameManager::activeScene;
	// Constructs the enemy object and adds it to the scene
	auto enemy = Application::getGameRepository()->getGameObjectbyTypeDuringRuntime(GameObjectType::enemy);
	auto enemyCast = std::dynamic_pointer_cast<Enemy>(enemy);
	assert(enemyCast != nullptr);
	enemyCast->AssignEnemyController(shared_from_this());

	scene->Instantiate(enemy);
	// increases the number of enemies that have been spawned
	enemyCount++;
}
void EnemyController::EnemyOutofBounds()
{
	enemyCount--;
}
// is called by the enemy when it is killed
void EnemyController::EnemyKilled()
{
	// Increases the number of enemies killed 
	numberOfEnemiesKilled++;
	// checks if the number of enemies killed is equal to the max number of enemies
	if(numberOfEnemiesKilled == MAX_NUMBER_OF_ENEMIES)
	{
		// Loads the win Screen when all the enemies have been killed
		const auto WINNING_SCENE = 2;
		Application::LoadScene(WINNING_SCENE);
	}
}

#include "EnemyController.h"
#include "../BackEndSystems/GameManager.h"
#include "../BackEndSystems/GameTime.h"
#include <memory>
#include <assert.h> 
#include "Enemy.h"


// Default constructor used to initialise enumerator type
EnemyController::EnemyController(const GameObject& gameObject, unsigned int max_enemies, double enemySpawnDelay):
GameObject(gameObject),
numberOfEnemiesKilled{0},
 MAX_NUMBER_OF_ENEMIES{max_enemies},
_enemySpawnDelay{enemySpawnDelay},
enemyCount{0}
{
	_type = GameObjectType::enemyController;
}
void EnemyController::Update()
{
	SpawnEnemyCountDown();
}

// instantiates an enemy into the current scene after a certain time has passed
void EnemyController::SpawnEnemyCountDown()
{
	// ensures that only the maximum number of enemies is spawned
	if(_enemySpawnDelay.DelayFinished() && enemyCount < MAX_NUMBER_OF_ENEMIES)
	{
		// spawns an enemy and resets the delay
		SpawnEnemy();
		_enemySpawnDelay.resetDelay();
		// increases the number of enemies that have been spawned
		enemyCount++;
	}
}

// adds an enemy object to the current list of gameobjects in the specific scne
void EnemyController::SpawnEnemy()
{
	// Constructs the enemy object and adds it to the scene
	auto enemy = Application::getGameRepository()->getGameObjectbyTypeDuringRuntime(GameObjectType::enemy);
	auto enemyCast = std::dynamic_pointer_cast<Enemy>(enemy);
	// Code should fail if a non enemy is returned
	assert(enemyCast != nullptr);
	enemyCast->AssignEnemyController(shared_from_this());
	_scene->Instantiate(enemy);
}
// Spawns a new enemy as the one that goes out of bounds is destroyed
void EnemyController::EnemyOutofBounds()
{
	SpawnEnemy();
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

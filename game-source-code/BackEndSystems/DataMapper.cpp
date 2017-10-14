#include "DataMapper.h"


DataMapper::DataMapper(std::string gameobject_datafile, std::string gamestate_datafile):
_gameobject_datafile{gameobject_datafile},
_gamestate_datafile{gamestate_datafile}
{}

void DataMapper::UpdateGameTimeDatabase(std::shared_ptr<DatabaseInterface> database)
{
	UpdateGameObjectDatabaseInfo(database);
	UpdateGameStateDatabaseInfo(database);
}
void DataMapper::UpdateGameObjectDatabaseInfo(std::shared_ptr<DatabaseInterface> database)
{

	ReadFromFile gameobjectdataFileReader{_gameobject_datafile};
	auto vectorOfGameData =  gameobjectdataFileReader.ExtractDataFromFile();
	std::string ID;
	for(const auto& gameStringData: vectorOfGameData)
	{
		if(	gameStringData[0] == 'I')
		{
			ID = GetIDFromString(gameStringData);
		}
		else 
		{
			auto gameObjectData = getObjectDataFromString(gameStringData);
			database->setGameObjectData(ID,gameObjectData);
		}
	}
}

void DataMapper::UpdateGameStateDatabaseInfo(std::shared_ptr<DatabaseInterface> database)
{
	ReadFromFile gameobjectdataFileReader{_gamestate_datafile};
	auto vectorOfStateData =  gameobjectdataFileReader.ExtractDataFromFile();
	GameStateData gameStateData;
	auto gamestate_stringdata = SplitGameObjectDataString(vectorOfStateData[0]);
	gameStateData.screen_size_x = StringConversions::string2uint(gamestate_stringdata[0]);
	gameStateData.screen_size_y = StringConversions::string2uint(gamestate_stringdata[1]);
	gameStateData.gameName = gamestate_stringdata[2];
	database->setGameStateData(gameStateData);
}
std::string DataMapper::GetIDFromString(const std::string& ID_Line)
{
	return ID_Line.substr(3);
}

GameObjectData DataMapper::getObjectDataFromString(const std::string& DataLine)
{
	auto gameObject_stringData = SplitGameObjectDataString(DataLine);
	GameObjectData gameObjectData;
	gameObjectData.PosX = StringConversions::string2double(gameObject_stringData[0]);
	gameObjectData.PosY = StringConversions::string2double(gameObject_stringData[1]);
	gameObjectData.scaleX = StringConversions::string2double(gameObject_stringData[2]);
	gameObjectData.scaleY = StringConversions::string2double(gameObject_stringData[3]);
	gameObjectData.graphic_name = gameObject_stringData[4];
	gameObjectData.graphic_location = gameObject_stringData[5];
	gameObjectData.move_speed = StringConversions::string2double(gameObject_stringData[6]);
	gameObjectData.collider_size = StringConversions::string2double(gameObject_stringData[7]);
	gameObjectData.player_shoot_delay = StringConversions::string2double(gameObject_stringData[8]);
	gameObjectData.player_shoot_speed = StringConversions::string2double(gameObject_stringData[9]);
	gameObjectData.player_projectile_destry_region = StringConversions::string2double(gameObject_stringData[10]);
	gameObjectData.enemy_spawn_delay = StringConversions::string2double(gameObject_stringData[11]);
	gameObjectData.enemy_shoot_delay = StringConversions::string2double(gameObject_stringData[12]);
	gameObjectData.enemy_shoot_speed = StringConversions::string2double(gameObject_stringData[13]);
	gameObjectData.max_enemies = StringConversions::string2uint(gameObject_stringData[14]);
	return gameObjectData;
	

}

std::vector<std::string> DataMapper::SplitGameObjectDataString(const std::string& DataLine)
{
	std::vector<std::string> gameObjectData;
	std::istringstream iss(DataLine);
	std::copy(std::istream_iterator<std::string>(iss),
				std::istream_iterator<std::string>(),
				std::back_inserter(gameObjectData));
	
	return gameObjectData;
	
}

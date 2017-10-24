#ifndef GAME_INFO_H
#define GAME_INFO_H
#include <string>

/**
 * @class GameObjectData
 * @brief A struct that is used to represent all of the information used for game object initialisation
 */
struct GameObjectData
{
	GameObjectData()
	{}
	GameObjectData(
	double p_x, 
	double p_y, 
	double s_x, 
	double s_y, 
	std::string g_n, 
	std::string g_l, 
	double m_s, 
	double col_siz, 
	double p_sh_del, 
	double p_sh_sp,
	double p_pro_dest_reg,
	double enm_spa_del,
	double enm_sh_del,
	double enm_an_sp,
	double para_coef,
	unsigned int m_enm
	);
	/**
	 * @brief Determines if two GameObjectDatas are equal
	 */
	bool operator==( const GameObjectData& rhs) const;
	
	// Base GameObject information 
	
	// Position
	double PosX = 0;
	double PosY = 0;
	// Scale 
	double scaleX = 1;
	double scaleY = 1;
	
	// Graphic Object
	std::string graphic_name = "Null";
	std::string graphic_location = "NullGraphic.png";
	
	// Physics Object Information
	double move_speed = 0;
	double collider_size = 0;
	
	// Player Information
	double player_shoot_delay = 0;
	double player_shoot_speed = 0;
	double player_projectile_destry_region = 0;
	
	// Enemy Informtation 
	double enemy_spawn_delay = 0;
	double enemy_shoot_delay = 0;
	double enemy_angular_speed = 0;
	double parabolic_coeff = 0;
	unsigned int max_enemies = 0;
};

/**
 * @class GameStateData
 * @brief A struct used to contain all of the basic game information
 */
struct GameStateData
{
	GameStateData()
	{}
	GameStateData(unsigned int scr_sz_x, unsigned int scr_sz_y, std::string gameName);
	bool operator ==(const GameStateData& rhs) const;
	unsigned int screen_size_x = 1920;
	unsigned int screen_size_y = 1080;
	std::string gameName = "Game"; 
};


#endif 
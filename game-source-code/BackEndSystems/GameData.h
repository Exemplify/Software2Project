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
	bool operator==( const GameObjectData& rhs) const;
	
	// Base GameObject information 
	
	// Position
	double PosX;
	double PosY;
	// Scale 
	double scaleX;
	double scaleY;
	
	// Graphic Object
	std::string graphic_name;
	std::string graphic_location;
	
	// Physics Object Information
	double move_speed;
	double collider_size;
	
	// Player Information
	double player_shoot_delay;
	double player_shoot_speed;
	double player_projectile_destry_region;
	
	// Enemy Informtation 
	double enemy_spawn_delay;
	double enemy_shoot_delay;
	double enemy_angular_speed;
	double parabolic_coeff;
	unsigned int max_enemies;
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
	unsigned int screen_size_x;
	unsigned int screen_size_y;
	std::string gameName; 
};


#endif 
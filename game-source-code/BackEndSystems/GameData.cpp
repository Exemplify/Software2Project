#include "GameData.h"

GameObjectData::GameObjectData(
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
			double enm_sh_sp,
			unsigned int m_enm):
PosX{p_x},
PosY{p_y},
scaleX{s_x},
scaleY{s_y},
graphic_name{g_n},
graphic_location{g_l},
move_speed{m_s},
collider_size{col_siz},
player_shoot_delay{p_sh_del}, 
player_shoot_speed{p_sh_sp},
player_projectile_destry_region{p_pro_dest_reg},
enemy_spawn_delay{enm_spa_del},
enemy_shoot_delay{enm_sh_del},
enemy_shoot_speed{enm_sh_sp},
max_enemies{m_enm}
{}
bool GameObjectData::operator==(const GameObjectData& rhs) const
{
	return 	collider_size == rhs.collider_size 			&&
			enemy_shoot_delay == rhs.enemy_shoot_delay 	&&
			enemy_shoot_speed == rhs.enemy_shoot_speed	&&
			enemy_spawn_delay == rhs.enemy_spawn_delay	&&
			graphic_location == rhs.graphic_location	&&
			graphic_name == rhs.graphic_name			&&
			max_enemies == rhs.max_enemies				&&
			move_speed == rhs.move_speed				&&
			player_projectile_destry_region == rhs.player_projectile_destry_region &&
			player_shoot_delay == rhs.player_shoot_delay &&
			player_shoot_speed == rhs.player_shoot_speed &&
			PosX == rhs.PosX							&&
			PosY == rhs.PosY							&&
			scaleX == rhs.scaleX						&&
			scaleY == rhs.scaleY;
}


GameStateData::GameStateData(unsigned int scr_sz_x, unsigned int scr_sz_y, std::string g_name):
screen_size_x{scr_sz_x},
screen_size_y{scr_sz_y},
gameName{g_name}
{}
bool GameStateData::operator ==(const GameStateData& rhs) const
{
	return 	screen_size_x == rhs.screen_size_x 	&&
			screen_size_y == rhs.screen_size_y 	&&
			gameName == rhs.gameName;
	
}
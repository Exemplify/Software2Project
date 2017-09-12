#ifndef GAME_MAN_H
#define GAME_MAN_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using std::string;

struct WindowSettings
{
    unsigned int screenWidth = 1920;
	unsigned int screenHeight = 1080;
	string Style = "Default";
	string game_name = "MyGame";
};

class GameManager
{
	
public:
	GameManager();
	void BeginGameLoop();
	void Quit();
private:
    // Variables
	WindowSettings _defaultSetup;
	RenderWindow _gameWindow;
    
    // Methods
    void initialiseWindow();
};




#endif

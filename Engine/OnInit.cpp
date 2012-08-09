#include <string.h>
#include "Main.h"

bool Engine::onInit() {
    
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Debug::error(Debug::ENGINE, Debug::FATAL, "SDL_Init failed!");
		return false;
	}
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	if ((display = SDL_SetVideoMode(VIEW_WIDTH, VIEW_HEIGHT, 32, SDL_OPENGL /*| SDL_HWSURFACE | SDL_DOUBLEBUF*/)) == NULL) {
        Debug::error(Debug::ENGINE, Debug::FATAL, "SDL_SetVideoMode failed!");
		return false;
	}

	SDL_WM_SetCaption("Aurora Game Engine v0.0.0", NULL);

    if (entity1.onLoad("res/yoshi.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (entity2.onLoad("res/yoshi2.png", 64, 64, 8) == false) {
        return false;
    }
    
    entity1.y = 256;
    entity2.x = 1000;
    
    Entity::entityList.push_back(&entity1);
    Entity::entityList.push_back(&entity2);
    
    if (player.onLoad("res/yoshi.png", 64, 64, 8) == false) {
        return false;
    }
    
    if (player2.onLoad("res/yoshi.png", 64, 64, 8) == false) {
        return false;
    }
    
    player.x = 3520;
    
    player2.x = 100;
    
    Entity::entityList.push_back(&player);
    Entity::entityList.push_back(&player2);
    
    Camera::cameraControl.targetMode = TARGET_MODE_CENTER;
    Camera::cameraControl.setTarget(&player.x, &player.y);
    
    if (Area::areaControl.onLoad("res/maps/1.area") == false) {
        return false;
    }
    
    SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

	//fprintf(stderr, "Initializations successful!\n");
    Debug::info(Debug::ENGINE, "Initializations successful!");
	return true;
}
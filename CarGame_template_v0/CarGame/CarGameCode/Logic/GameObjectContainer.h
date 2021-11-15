#ifndef CARGAME_GAMEOBJECTCONTAINER_H
#define CARGAME_GAMEOBJECTCONTAINER_H

#include <vector>
#include "GameObjects/GameObject.h"
#include "GameObjects/Collider.h"
#include "..//..//checkML.h"
using namespace std;

//class GameObject;
//class Collider;

class GameObjectContainer {
    vector<GameObject*> gameObjects;
public:

    GameObjectContainer(){};
    ~GameObjectContainer();
    void update();
    void draw();
    void drawDebug();
    void add(GameObject *gameObject);
    void removeDead();
    bool hasCollision(GameObject *g);
    vector<Collider *> getCollisions(GameObject *g);

	vector<GameObject*> getGameobjects() { return gameObjects; }
};


#endif //CARGAME_GAMEOBJECTCONTAINER_H

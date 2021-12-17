#pragma once
#include "../GameObjects/GameObject.h"

class GoodObject : public GameObject
{
protected:
	bool alive;
public:
	static int instances;
	GoodObject(Game* game) : GameObject(game) {
		alive = true;
	};
	~GoodObject() override = default;
	virtual void update() override;
	bool toDelete() override;

	void onEnter() override;
	void onDelete() override;
	void static reset();
	
	virtual SDL_Rect getCollider();

	virtual void receiveWave();
};


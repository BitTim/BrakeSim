#pragma once

#include <vector>
#include "../objects/object.hh"

class PhysicsWorld {
private:
	std::vector<Object*> m_objects;

public:
	// Management
	void AddObject(Object* object);
	void RemoveObject(Object* object);

	// Activity
	void step(float dt);
	void render();
}
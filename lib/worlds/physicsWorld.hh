#pragma once

#include <vector>
#include "../objects/object.hh"

class PhysicsWorld {
private:
	std::vector<Object*> m_objects;

public:
	// --------------------------------
	// Management
	// --------------------------------

	void AddObject(Object* object) {
		m_objects.push_back(object);
	}

	void RemoveObject(Object* object) {
		if (!object) return;
		auto itr = std::find(m_objects.begin(), m_objects.end(), object);
		if(itr == m_objects.end()) return;
		m_objects.erase(itr);
	}

	// --------------------------------
	// Activity
	// --------------------------------
	
	void Step(float dt) {
		for(Object* pbj : m_objects) {
			obj->force += obj->mass * Vector2.GRAVITY;
			
			obj->velocity += obj->force / obj->mass * dt;
			obj->position += obj->velocity * dt;

			obj->force = Vector2.ZERO;
		}
	}

	void render() {
		
	}
}
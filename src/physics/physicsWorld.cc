#include "../../lib/physics/physicsWorld.hh"

// --------------------------------
// Management
// --------------------------------

void PhysicsWorld::AddObject(Object* object) {
	m_objects.push_back(object);
}

void PhysicsWorld::RemoveObject(Object* object) {
	if (!object) return;
	auto itr = std::find(m_objects.begin(), m_objects.end(), object);
	if(itr == m_objects.end()) return;
	m_objects.erase(itr);
}

// --------------------------------
// Activity
// --------------------------------

void PhysicsWorld::step(float dt) {
	for(Object* pbj : m_objects) {
		obj->force += obj->mass * Vector2.GRAVITY;
		
		obj->velocity += obj->force / obj->mass * dt;
		obj->position += obj->velocity * dt;

		obj->force = Vector2.ZERO;
	}
}

void PhysicsWorld::render() {
	
}
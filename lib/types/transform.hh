#pragma once

#include "vector2.hh"

class Transform
{
	Vector2 position;
	Vector2 scale;
	Vector2 rotation;

	Transform() {}
	Transform(Vector2 position, Vector2 scale, Vector2 rotation);

	// Constants
	static const Transform ORIGIN = Transform(Vector2::ZERO, Vector2::UNIT, Vector2::ZERO);

	// Calculations
};
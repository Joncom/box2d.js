#include <emscripten/bind.h>
#include "Box2D/Collision/Shapes/b2Shape.h"

using namespace emscripten;

// b2Vec2
float32 b2Vec2GetX(const b2Vec2& s) { return s.x; }
void b2Vec2SetX(b2Vec2& s, float32 x) { s.x = x; }
float32 b2Vec2GetY(const b2Vec2& s) { return s.y; }
void b2Vec2SetY(b2Vec2& s, float32 y) { s.y = y; }

// b2MassData
float32 b2MassDataGetMass(const b2MassData& s) { return s.mass; }
void b2MassDataSetMass(b2MassData& s, float32 mass) { s.mass = mass; }
b2Vec2 b2MassDataGetCenter(const b2MassData& s) { return s.center; }
void b2MassDataSetCenter(b2MassData& s, b2Vec2 center) { s.center = center; }
float32 b2MassDataGetI(const b2MassData& s) { return s.I; }
void b2MassDataSetI(b2MassData& s, float32 I) { s.I = I; }

EMSCRIPTEN_BINDINGS(box2d_embindings) {
	class_<b2Vec2>("b2Vec2")
		.constructor<>()
		.property("x", &b2Vec2GetX, &b2Vec2SetX)
		.property("y", &b2Vec2GetY, &b2Vec2SetY)
		;
	class_<b2MassData>("b2MassData")
		.constructor<>()
		.property("mass", &b2MassDataGetMass, &b2MassDataSetMass)
		.property("center", &b2MassDataGetCenter, &b2MassDataSetCenter)
		.property("I", &b2MassDataGetI, &b2MassDataSetI)
		;
}
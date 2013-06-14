#include <emscripten/bind.h>
#include "Box2D/Collision/Shapes/b2Shape.h"

using namespace emscripten;

float32 b2MassDataGetMass(const b2MassData& s) { return s.mass; }
void b2MassDataSetMass(b2MassData& s, float32 mass) { s.mass = mass; }

b2Vec2 b2MassDataGetCenter(const b2MassData& s) { return s.center; }
void b2MassDataSetCenter(b2MassData& s, b2Vec2 center) { s.center = center; }

float32 b2MassDataGetI(const b2MassData& s) { return s.I; }
void b2MassDataSetI(b2MassData& s, float32 I) { s.I = I; }

EMSCRIPTEN_BINDINGS(box2d_embindings) {
	class_<b2MassData>("b2MassData")
		.constructor<>()
		.property("mass", &b2MassDataGetMass, &b2MassDataSetMass)
		.property("center", &b2MassDataGetCenter, &b2MassDataSetCenter)
		.property("I", &b2MassDataGetI, &b2MassDataSetI)
		;
}
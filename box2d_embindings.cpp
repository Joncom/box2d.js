#include <emscripten/bind.h>
#include "Box2D/Collision/Shapes/b2Shape.h"

using namespace emscripten;

float32 b2MassDataGetMass(const b2MassData& s) { return s.mass; }
void b2MassDataSetMass(b2MassData& s, float32 mass) { s.mass = mass; }

EMSCRIPTEN_BINDINGS(box2d_embindings) {
	class_<b2MassData>("b2MassData")
		.constructor<>()
		.property("mass", &b2MassDataGetMass, &b2MassDataSetMass)
		;
}
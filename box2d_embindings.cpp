#include <emscripten/bind.h>
#include "Box2D/Collision/Shapes/b2Shape.h"
#include "Box2D/Collision/b2Collision.h"

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

// b2ManifoldPoint
b2Vec2 b2ManifoldPointGetLocalPoint(const b2ManifoldPoint& s) { return s.localPoint; }
void b2ManifoldPointSetLocalPoint(b2ManifoldPoint& s, b2Vec2 localPoint) { s.localPoint = localPoint; }
float32 b2ManifoldPointGetNormalImpulse(const b2ManifoldPoint& s) { return s.normalImpulse; }
void b2ManifoldPointSetNormalImpulse(b2ManifoldPoint& s, float32 normalImpulse) { s.normalImpulse = normalImpulse; }
float32 b2ManifoldPointGetTangentImpulse(const b2ManifoldPoint& s) { return s.tangentImpulse; }
void b2ManifoldPointSetTangentImpulse(b2ManifoldPoint& s, float32 tangentImpulse) { s.tangentImpulse = tangentImpulse; }
b2ContactID b2ManifoldPointGetID(const b2ManifoldPoint& s) { return s.id; }
void b2ManifoldPointSetID(b2ManifoldPoint& s, b2ContactID id) { s.id = id; }

// b2Manifold
std::vector<b2ManifoldPoint> b2ManifoldGetPoints(const b2Manifold& s) {
	std::vector<b2ManifoldPoint> vector(std::begin(s.points), std::end(s.points));
	return vector;
}
void b2ManifoldSetPoints(b2Manifold& s, std::vector<b2ManifoldPoint> vector) {
	std::copy(vector.begin(), vector.end(), s.points);
}
b2Vec2 b2ManifoldGetLocalNormal(const b2Manifold& s) { return s.localNormal; }
void b2ManifoldSetLocalNormal(b2Manifold& s, b2Vec2 localNormal) { s.localNormal = localNormal; }
b2Vec2 b2ManifoldGetLocalPoint(const b2Manifold& s) { return s.localPoint; }
void b2ManifoldSetLocalPoint(b2Manifold& s, b2Vec2 localPoint) { s.localPoint = localPoint; }
b2Manifold::Type b2ManifoldGetType(const b2Manifold& s) { return s.type; }
void b2ManifoldSetType(b2Manifold& s, b2Manifold::Type type) { s.type = type; }
int32 b2ManifoldGetPointCount(const b2Manifold& s) { return s.pointCount; }
void b2ManifoldSetPointCount(b2Manifold& s, int32 pointCount) { s.pointCount = pointCount; }

EMSCRIPTEN_BINDINGS(box2d_embindings) {

	// b2Math.h
	class_<b2Vec2>("b2Vec2")
		.constructor<>()
		.property("x", &b2Vec2GetX, &b2Vec2SetX)
		.property("y", &b2Vec2GetY, &b2Vec2SetY)
		;


	// b2Shape.h
	class_<b2MassData>("b2MassData")
		.constructor<>()
		.property("mass", &b2MassDataGetMass, &b2MassDataSetMass)
		.property("center", &b2MassDataGetCenter, &b2MassDataSetCenter)
		.property("I", &b2MassDataGetI, &b2MassDataSetI)
		;


	// b2Collision.h
	register_vector<std::vector<b2ManifoldPoint>>("b2ManifoldPoint");
	class_<b2ManifoldPoint>("b2ManifoldPoint")
		.constructor<>()
		.property("localPoint", &b2ManifoldPointGetLocalPoint, &b2ManifoldPointSetLocalPoint)
		.property("normalImpulse", &b2ManifoldPointGetNormalImpulse, &b2ManifoldPointSetNormalImpulse)
		.property("tangentImpulse", &b2ManifoldPointGetTangentImpulse, &b2ManifoldPointSetTangentImpulse)
		.property("id", &b2ManifoldPointGetID, &b2ManifoldPointGetID)
		;
	class_<b2Manifold>("b2Manifold")
		.constructor<>()
		.property("points", &b2ManifoldGetPoints, &b2ManifoldSetPoints)
		.property("localNormal", &b2ManifoldGetLocalNormal, &b2ManifoldSetLocalNormal)
		.property("localPoint", &b2ManifoldGetLocalPoint, &b2ManifoldSetLocalPoint)
		.property("type", &b2ManifoldGetType, &b2ManifoldSetType)
		.property("pointCount", &b2ManifoldGetPointCount, &b2ManifoldSetPointCount)
		;

}
#include "vec2.h"

using namespace dappy;
using namespace math;

vec2::vec2()
{
	x = 0.0f;
	y = 0.0f;
}

vec2::vec2(const float & xx, const float & yy)
{
	x = xx;
	y = yy;
}

vec2 & vec2::add(const vec2 & ref)
{
	x += ref.x;
	y += ref.y;
	return *this;
}
vec2 & vec2::sub(const vec2 & ref)
{
	x -= ref.x;
	y -= ref.y;
	return *this;
}
vec2 & vec2::mult(const vec2 & ref)
{
	x *= ref.x;
	y *= ref.y;
	return *this;
}
vec2 & vec2::divide(const vec2 & ref)
{
	x /= ref.x;
	y /= ref.y;
	return *this;
}


vec2& dappy::math::vec2::operator+=(const vec2 & ref)
{
	return this->add(ref);
}
vec2 & dappy::math::vec2::operator-=(const vec2 & ref)
{
	return this->sub(ref);
}
vec2 & dappy::math::vec2::operator/=(const vec2 & ref)
{
	return this->divide(ref);
}
vec2 & dappy::math::vec2::operator*=(const vec2 & ref)
{
	return this->mult(ref);
}


bool dappy::math::vec2::operator==(const vec2 & def)
{
	return x == def.x && y == def.y;
}
bool dappy::math::vec2::operator!=(const vec2 & def)
{
	return x != def.x || y != def.y;
}

std::ostream & dappy::math::operator<<(std::ostream & stream, const vec2 & ref)
{
	stream << "vec2 : (" << ref.x << " , " << ref.y << ")";	return stream; 
}

vec2 dappy::math::operator+( vec2 ref, const vec2 & def)
{
	return ref.add(def);
}
vec2 dappy::math::operator-(vec2 ref, const vec2 & def)
{
	return ref.sub(def);
}
vec2 dappy::math::operator/(vec2 ref, const vec2 & def)
{
	return ref.divide(def);
}
vec2 dappy::math::operator*(vec2 ref, const vec2 & def)
{
	return ref.mult(def);
}



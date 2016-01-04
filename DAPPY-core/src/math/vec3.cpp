#include "vec3.h"

using namespace dappy;
using namespace math;

vec3::vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

vec3::vec3(const float & xx, const float & yy, const float & zz)
{
	x = xx;
	y = yy;
	z = zz;
}

vec3 & vec3::add(const vec3 & ref)
{
	x += ref.x;
	y += ref.y;
	z += ref.z;

	return *this;
}
vec3 & vec3::sub(const vec3 & ref)
{
	x -= ref.x;
	y -= ref.y;
	z -= ref.z;
	return *this;
}
vec3 & vec3::mult(const vec3 & ref)
{
	x *= ref.x;
	y *= ref.y;
	z *= ref.z;
	return *this;
}
vec3 & vec3::divide(const vec3 & ref)
{
	x /= ref.x;
	y /= ref.y;
	z /= ref.z;
	return *this;
}


vec3& dappy::math::vec3::operator+=(const vec3 & ref)
{
	return this->add(ref);
}
vec3 & dappy::math::vec3::operator-=(const vec3 & ref)
{
	return this->sub(ref);
}
vec3 & dappy::math::vec3::operator/=(const vec3 & ref)
{
	return this->divide(ref);
}
vec3 & dappy::math::vec3::operator*=(const vec3 & ref)
{
	return this->mult(ref);
}


bool dappy::math::vec3::operator==(const vec3 & def)
{
	return x == def.x && y == def.y && z == def.z;
}
bool dappy::math::vec3::operator!=(const vec3 & def)
{
	return x != def.x || y != def.y || y != def.y;
}

std::ostream & dappy::math::operator<<(std::ostream & stream, const vec3 & ref)
{																		   
	stream << "vec3 : (" << ref.x << " , " << ref.y << " , " << ref.z << ")";	return stream; 
}

vec3 dappy::math::operator+( vec3 ref, const vec3 & def)
{
	return ref.add(def);
}
vec3 dappy::math::operator-(vec3 ref, const vec3 & def)
{
	return ref.sub(def);
}
vec3 dappy::math::operator/(vec3 ref, const vec3 & def)
{
	return ref.divide(def);
}
vec3 dappy::math::operator*(vec3 ref, const vec3 & def)
{
	return ref.mult(def);
}



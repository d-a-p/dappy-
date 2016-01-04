#include "vec4.h"

using namespace dappy;
using namespace math;

vec4::vec4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}
  
vec4::vec4(const float & xx, const float & yy, const float & zz, const float & ww)
{
	x = xx;
	y = yy;
	z = zz;
	w = ww;
}

vec4 & vec4::add(const vec4 & ref)
{
	x += ref.x;
	y += ref.y;
	z += ref.z;
	w += ref.w;
	return *this;
}
vec4 & vec4::sub(const vec4 & ref)
{
	x -= ref.x;
	y -= ref.y;
	z -= ref.z;
	w -= ref.w;
	return *this;
}
vec4 & vec4::mult(const vec4 & ref)
{
	x *= ref.x;
	y *= ref.y;
	z *= ref.z;
	w *= ref.w;
	return *this;
}
vec4 & vec4::divide(const vec4 & ref)
{
	x /= ref.x;
	y /= ref.y;
	z /= ref.z;
	w /= ref.w;
	return *this;
}


vec4& dappy::math::vec4::operator+=(const vec4 & ref)
{
	return this->add(ref);
}
vec4 & dappy::math::vec4::operator-=(const vec4 & ref)
{
	return this->sub(ref);
}
vec4 & dappy::math::vec4::operator/=(const vec4 & ref)
{
	return this->divide(ref);
}
vec4 & dappy::math::vec4::operator*=(const vec4 & ref)
{
	return this->mult(ref);
}


bool dappy::math::vec4::operator==(const vec4 & def)
{
	return x == def.x && y == def.y && z == def.z && w == def.w;
}
bool dappy::math::vec4::operator!=(const vec4 & def)
{
	return x != def.x || y != def.y || y != def.y || w != def.w;
}

std::ostream & dappy::math::operator<<(std::ostream & stream, const vec4 & ref)
{																		   
	stream << "vec4 : (" << ref.x << " , " << ref.y << " , " << ref.z << " , " << ref.w << ")";	return stream; 
}

vec4 dappy::math::operator+( vec4 ref, const vec4 & def)
{
	return ref.add(def);
}
vec4 dappy::math::operator-(vec4 ref, const vec4 & def)
{
	return ref.sub(def);
}
vec4 dappy::math::operator/(vec4 ref, const vec4 & def)
{
	return ref.divide(def);
}
vec4 dappy::math::operator*(vec4 ref, const vec4 & def)
{
	return ref.mult(def);
}



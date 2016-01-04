#pragma once
#include<iostream>

namespace dappy { namespace math {

	struct vec3 {

		float x, y, z;

		vec3();
		vec3(const float&x, const float&y, const float&z);

		vec3& add(const vec3&);
		vec3& sub(const vec3&);
		vec3& mult(const vec3&);
		vec3& divide(const vec3&);

		friend std::ostream& operator<< (std::ostream& stream ,const vec3&);

		friend vec3 operator+( vec3 ref ,const vec3& def);
		friend vec3 operator-(vec3 ref, const vec3& def);
		friend vec3 operator/(vec3 ref, const vec3& def);
		friend vec3 operator*(vec3 ref, const vec3& def);

		vec3& operator+=(const vec3& ref);
		vec3& operator/=(const vec3& ref);
		vec3& operator*=(const vec3& ref);
		vec3& operator-=(const vec3& ref);

		bool operator==( const vec3& def);
		bool operator!=(const vec3& def);

	};



} }
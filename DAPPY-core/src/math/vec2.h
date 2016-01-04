#pragma once
#include<iostream>

namespace dappy { namespace math {

	struct vec2 {

		float x, y;

		vec2();
		vec2(const float&x, const float&y);

		vec2& add(const vec2&);
		vec2& sub(const vec2&);
		vec2& mult(const vec2&);
		vec2& divide(const vec2&);

		friend std::ostream& operator<< (std::ostream& stream ,const vec2&);

		friend vec2 operator+( vec2 ref ,const vec2& def);
		friend vec2 operator-(vec2 ref, const vec2& def);
		friend vec2 operator/(vec2 ref, const vec2& def);
		friend vec2 operator*(vec2 ref, const vec2& def);

		vec2& operator+=(const vec2& ref);
		vec2& operator/=(const vec2& ref);
		vec2& operator*=(const vec2& ref);
		vec2& operator-=(const vec2& ref);

		bool operator==( const vec2& def);
		bool operator!=(const vec2& def);

	};



} }
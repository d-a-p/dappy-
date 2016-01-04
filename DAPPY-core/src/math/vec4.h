#pragma once
#include<iostream>

namespace dappy { namespace math {

	struct vec4 {

		float x, y, z, w;

		vec4();
		vec4(const float&x, const float&y, const float&z, const float&w);

		vec4& add(const vec4&);
		vec4& sub(const vec4&);
		vec4& mult(const vec4&);
		vec4& divide(const vec4&);

		friend std::ostream& operator<< (std::ostream& stream ,const vec4&);

		friend vec4 operator+( vec4 ref ,const vec4& def);
		friend vec4 operator-(vec4 ref, const vec4& def);
		friend vec4 operator/(vec4 ref, const vec4& def);
		friend vec4 operator*(vec4 ref, const vec4& def);

		vec4& operator+=(const vec4& ref);
		vec4& operator/=(const vec4& ref);
		vec4& operator*=(const vec4& ref);
		vec4& operator-=(const vec4& ref);

		bool operator==( const vec4& def);
		bool operator!=(const vec4& def);

	};



} }
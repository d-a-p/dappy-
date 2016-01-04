#define _USE_MATH_DEFINES
#include<math.h>
#include"maths.h"
#include"math_func.h"

using namespace dappy;
using namespace math;

dappy::math::mat4::mat4()
{
	for (int i = 0; i < 4 * 4  ;i++)
	{
		elements[i] = 0;
	}

}

dappy::math::mat4::mat4(float dia)
{
	for (int i = 0; i < 4 * 4  ; i++)
	{
		elements[i] = 0;
	}

	elements[0 + 0 * 4] = dia;
	elements[1 + 1 * 4] = dia;
	elements[2 + 2 * 4] = dia;
	elements[3 + 3 * 4] = dia;

}

mat4& dappy::math::mat4::identity()
{
	mat4* mat = new mat4(1.0);
	return *mat;
}

mat4 & dappy::math::mat4::multiply(const mat4 & ref)
{
	float data[16];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			float sum = 0;
			for (int k = 0; k < 4; k++)
			{
				//sum += elements[j + k * 4] * ref.elements[k+i*4];
				sum += elements[i + k * 4] * ref.elements[k + j * 4];
			}
			data[i+j*4] = sum;
		}
	}
	memcpy(elements, data, 4 * 4 * sizeof(float));

	return *this;
}

mat4& dappy::math::mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
{
	mat4* result = new mat4(1.0f);

	result->elements[0 + 0 * 4] = 2.0f / (right - left);
	result->elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result->elements[2 + 2 * 4] = 2.0f / (near - far);

	result->elements[0 + 3 * 4] = (right + left) / (left - right);
	result->elements[1 + 3 * 4] = (top + bottom) / (bottom - top);
	result->elements[2 + 3 * 4] = (near + far) / (near - far);

	
	return *result;
}

mat4 dappy::math::mat4::perspective(float fov, float aspratio, float near, float far)
{
	mat4 result(1.0f);

	float q = 1.0f / tan(toRadians((0.5f)*fov));
	float a = q / aspratio;

	float b = (near + far) / (near - far);
	float c = (2.0f * near * far) / (near - far);

	result.elements[0 + 0 * 4] = a;
	result.elements[1 + 1 * 4] = q;
	result.elements[2 + 2 * 4] = b;
	result.elements[2 + 3 * 4] = c;
	result.elements[3 + 2 * 4] = -1.0f;


	return result;
}

mat4 dappy::math::operator*(mat4 left, const mat4 & right)
{
	return left.multiply(right);
}

vec3 dappy::math::operator*(const mat4 & left, const vec3 & right)
{
	return left.multiply(right);
}

vec4 dappy::math::operator*(const mat4 & left, const vec4 & right)
{
	return left.multiply(right);
}

mat4 dappy::math::mat4::translation(const vec3 & translation)
{
	mat4 tra(1.0f);

	tra.elements[0 + 3 * 4] = translation.x;
	tra.elements[1 + 3 * 4] = translation.y;
	tra.elements[2 + 3 * 4] = translation.z;

	return tra;
}

mat4 dappy::math::mat4::rotation(float angle, const vec3 & axis)
{
	mat4 result(1.0f);

	float rad = toRadians(angle);
	float s = sin(rad);
	float c = cos(rad);
	float omc = 1.0f - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	result.elements[0 + 0 * 4] = x*omc + c;
	result.elements[1 + 0 * 4] = y*x*omc + z*s;
	result.elements[2 + 0 * 4] = x*z*omc - y*s;

	result.elements[0 + 1 * 4] = x*y*omc - z*s;
	result.elements[1 + 1 * 4] = y*omc + c;
	result.elements[2 + 1 * 4] = y*z*omc + x*s;		

	result.elements[0 + 2 * 4] = x*z*omc + y*s;
	result.elements[1 + 2 * 4] = y*z*omc - x*s;
	result.elements[2 + 2 * 4] = z*omc +  c;


	return result;
}

mat4 dappy::math::mat4::scale(const vec3 & scale)
{
	mat4 result(1.0f);
	
	result.elements[0 + 0 * 4] = scale.x;
	result.elements[1 + 1 * 4] = scale.y;
	result.elements[2 + 2 * 4] = scale.z;

	return result;
}

mat4 & dappy::math::mat4::operator*=(const mat4 & ref)
{
	return multiply(ref);
}

vec3 dappy::math::mat4::multiply(const vec3 & other) const
{
	return vec3(
		columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
		columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
		columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
		);
}

vec4 dappy::math::mat4::multiply(const vec4 & other) const
{
	return vec4(
		columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x * other.w,
		columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y * other.w,
		columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z * other.w,
		columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[3].w * other.w
		);
}


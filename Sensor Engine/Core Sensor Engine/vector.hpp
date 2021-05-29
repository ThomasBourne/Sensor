#pragma once
#include "errors.h"
namespace sensor {
	template <typename T> class vec2 { //class for vector 2 containing basic operands and coordinates of the vector 2
	public:
		T x; //x poition of vec2
		T y; //y poition of vec2

		vec2 operator + (const vec2<T>& v) { //adds both the x and y values (into another vec2<T>)
			vec2<T> add;
			add.x = this->x + v.x;
			add.y = this->y + v.y;
			return add;
		}

		vec2 operator - (const vec2<T>& v) { //subtracts both the x and y values (into another vec2<T>)
			vec2<T> add;
			add.x = this->x - v.x;
			add.y = this->y - v.y;
			return add;
		}

		vec2 operator * (const vec2<T>& v) { //subtracts both the x and y values (into another vec2<T>)
			vec2<T> add;
			add.x = this->x * v.x;
			add.y = this->y * v.y;
			return add;
		}

		vec2(T x = (T)0, T y = (T)0) { //generates a new vec2<T> with default (T)0 for x and y. Will return -1 for x and y if invalid type passed through
			if (!(typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(double))) { //checks valid vec2
				ThrowError(_ERROR_SHAPE::INVALID_TYPE);
				this->x = -1;
				this->y = -1;
			}
			else {
				this->x = x;
				this->y = y;
			}
		}

		void transform(char axis, T amount) {
			switch (axis) {
			case ('x'):
				this->x += amount;
				break;
			case ('y'):
				this->y += amount;
				break;
			default: //ThrowError() with new error
				ThrowError(_ERROR_SHAPE::INVALID_AXIS);
				break;
			}
		}

		static vec2<T> transform(vec2<T> obj, char axis, T amount) { //dont need overload with vec2<T> input as + overload exists
			switch (axis) {
			case ('x'):
				obj.x += amount;
				break;
			case ('y'):
				obj.y += amount;
				break;
			default: //ThrowError() with new error
				ThrowError(_ERROR_SHAPE::INVALID_AXIS);
				break;
			}
			return obj;
		}

		static void printv(vec2<T> vec) { //print the x and y pos in format [x, y]
			if (typeid(T) == typeid(int)) { //checks what type should be printed and throws error otherwise
				std::printf("%i, %i", vec.x, vec.y);
			}
			else if (typeid(T) == typeid(float) || typeid(T) == typeid(double)) {
				std::printf("%f, %f", vec.x, vec.y);
			}
			else {
				ThrowError(_ERROR_SHAPE::INVALID_VEC);
			}
			std::cout << std::endl;
		}
	};

	typedef vec2<int>		vec2i;
	typedef vec2<float>		vec2f;
	typedef vec2<double>	vec2d;
}
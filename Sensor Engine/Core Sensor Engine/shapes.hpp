#pragma once
#include <list>
#include <windows.h>
#include "window.h"
#include "vector.hpp"

const double PI = 3.141592653589793;


namespace sensor {
	template <typename T> class line { //class for creating a line shape compatable with sensor engine
	public:
		vec2<T> p1; //coord of point one of the line
		vec2<T> p2; //coord of point two of the line


		void move(vec2<T> amount) {
			this->p1 = this->p1 + amount;
			this->p2 = this->p2 + amount;
		}

		void move(char axis, T amount) {
			switch (axis)
			{
			case('x'):
				this->p1.x += amount;
				this->p2.x += amount;
				break;
			case('y'):
				this->p1.y += amount;
				this->p2.y += amount;
				break;
			default:
				ThrowError(_ERROR_SHAPE::INVALID_VEC);
				break;
			}
		}

		line(vec2<T> p1, vec2<T> p2) { //generates a new line shape and takes in two coordinates
			this->p1 = p1;
			this->p2 = p2;
		}

		void Point2(vec2<T> point1, T angle, T len) { //DOES NOT WORK	
			this->p2.x = point1.x + (len + (T)(std::round(std::cos((double)angle * PI / 180.0))));
			this->p2.y = point1.y + (len + (T)(std::round(std::sin((double)angle * PI / 180.0))));
		}

		line(vec2<T> p1, T angle, T len) { //generates a new line shape and takes in one coordinate, length of the line, and the angle at which the line is at (also scale up for triangles)
			//angle += (T)360;
			this->p1 = p1;
			Point2(p1, angle, len);
		}

		static void printl(line<T> l) { //print the x and y pos in format [x, y]
			if (typeid(T) == typeid(int)) { //checks what type should be printed and throws error otherwise
				std::printf("%i, %i    %i, %i", l.p1.x, l.p1.y, l.p2.x, l.p2.y);
			}
			else if (typeid(T) == typeid(float) || typeid(T) == typeid(double)) {
				std::printf("%f, %f    %f, %f", l.p1.x, l.p1.y, l.p2.x, l.p2.y);
			}
			std::cout << std::endl;
		}
		void render(HDC hdc) {
			HPEN hLinePen;
			COLORREF qLineColor;
			qLineColor = RGB(255, 0, 0);
			hLinePen = CreatePen(PS_SOLID, 7, qLineColor);
			HPEN hPenOld = (HPEN)SelectObject(hdc, hLinePen);

			MoveToEx(hdc, this->p1.x, this->p1.x, NULL);
			LineTo(hdc, this->p2.x, this->p2.y);

			SelectObject(hdc, hPenOld);
			DeleteObject(hLinePen);

		}
	};

	typedef line<int>		linei;
	typedef line<float>		linef;
	typedef line<double>	lined;


	template <typename T> class tri {
	public:
		vec2<T> p1; //point 1 of of triangle
		vec2<T> p2; //point 2 of of triangle
		vec2<T> p3; //point 3 of of triangle

		tri(vec2<T> p1, vec2<T> p2, vec2<T> p3) {
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
		}


		void move(vec2<T> amount) {
			this->p1 = this->p1 + amount;
			this->p2 = this->p2 + amount;
			this->p3 = this->p3 + amount;
		}

		void move(char axis, T amount) {
			switch (axis)
			{
			case('x'):
				this->p1.x += amount;
				this->p2.x += amount;
				this->p3.x += amount;
				break;
			case('y'):
				this->p1.y += amount;
				this->p2.y += amount;
				this->p3.y += amount;
				break;
			default:
				ThrowError(_ERROR_SHAPE::INVALID_VEC);
				break;
			}
		}

		static void printt(tri<T> obj) {
			if (typeid(T) == typeid(int)) {
				std::printf("%i, %i : %i, %i : %i, %i\n", obj.p1.x, obj.p1.y, obj.p2.x, obj.p2.y, obj.p3.x, obj.p3.y);
			}
			else if (typeid(T) == typeid(float) || typeid(T) == typeid(double)) {
				std::printf("%f, %f : %f, %f : %f, %f\n", obj.p1.x, obj.p1.y, obj.p2.x, obj.p2.y, obj.p3.x, obj.p3.y);
			}
			else {
				ThrowError(_ERROR_SHAPE::INVALID_VEC);
			}
		}
	};

	typedef tri<int>		trii;
	typedef tri<float>		trif;
	typedef tri<double>		trid;

	template <typename T> class rect { //add create rect with 2 triangles
	public:
		vec2<T> p1; //pos of corner 1
		vec2<T> p2; //pos of corner 2
		vec2<T> p3; //pos of corner 3
		vec2<T> p4; //pos of corner 4

		rgb colour = Colour.black;

		rect(vec2<T> p1, vec2<T> p2, vec2<T> p3, vec2<T> p4) {
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
			this->p4 = p4;
		}
		rect(T width, T height, vec2<T> startPos) {
			this->p1 = startPos;
			this->p2 = vec2<T>::transform(startPos, 'x', width);
			this->p3 = vec2<T>::transform(startPos, 'y', height);
			this->p4 = vec2<T>(this->p2.x, this->p3.y);
		}

		void move(vec2<T> amount) {
			this->p1 = this->p1 + amount;
			this->p2 = this->p2 + amount;
			this->p3 = this->p3 + amount;
			this->p4 = this->p4 + amount;
		}

		void move(char axis, T amount) {
			switch (axis)
			{
			case('x'):
				this->p1.x += amount;
				this->p2.x += amount;
				this->p3.x += amount;
				this->p4.x += amount;
				break;
			case('y'):
				this->p1.y += amount;
				this->p2.y += amount;
				this->p3.y += amount;
				this->p4.y += amount;
				break;
			default:
				ThrowError(_ERROR_SHAPE::INVALID_VEC);
				break;
			}
		}

		static void printr(rect<T> obj) {
			std::cout << obj.p1.x << ", " << obj.p1.y << "    :    " << obj.p2.x << ", " << obj.p2.y << std::endl;
			std::cout << obj.p3.x << ", " << obj.p3.y << "    :    " << obj.p4.x << ", " << obj.p4.y << std::endl;
		}
		void render(HDC hdc) {
			HBRUSH brush{ CreateSolidBrush(sensor::rgb::convert(colour)) };

			RECT rect { this->p1.x, this->p1.y, this->p2.x, this->p4.y };
			FillRect(hdc, &rect, brush);
			DeleteObject(brush);

		}
	};

	typedef rect<int>		recti;
	typedef rect<float>		rectf;
	typedef rect<double>	rectd;
}
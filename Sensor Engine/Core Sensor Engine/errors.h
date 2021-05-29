#pragma once
#include <iostream>
namespace _ERROR_SHAPE {
	const char INVALID_TYPE[] = "ERROR WITH SHAPE PERAM: INVALID DATA TYPE CREATED WITH sensor::shapeType<TYPE> OR sensor::vec2<TYPE>\n";
	const char INVALID_VEC[] = "ERROR WITH sensor::vec2<T>::printv() PERAM: vec2<T> with type T passed in was illegal as only int, float and double types allowed\n";
	const char INVALID_AXIS[] = "ERROR WITH PARSING AXIS SPECIFIED IN vec2<T>::transform()";
}
namespace sensor {
	void ThrowError(const char Error[]) {
		std::cout << Error << std::endl;
	}
}
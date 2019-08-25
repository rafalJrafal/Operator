#ifndef TEMP_H
#define TEMP_H

#include "BaseClass.h"

namespace OperatorTest {

const char TEMPLATE_LOG_FILENAME [] = "TemplateLog.txt";

template <class Tm, int val = 0> class Temp : public BaseClass {
	public:
		Temp(int);
		Tm * operator [] (int);
		
	private:
		int mParameter;
		static const unsigned int mSize = 100;
		
		Tm * mArray[mSize];
};

template <class Tm, int val>
Temp<Tm, val>::Temp(int value) : BaseClass(TEMPLATE_LOG_FILENAME), mParameter(value) {
	log = LogSystem::LogSystem::instance(TEMPLATE_LOG_FILENAME);
	log->log("Start: val = %d", val);
}

template <class Tm, int val>
Tm* Temp<Tm, val>::operator [] (int index) {
	log->log("Operator [] index %d", index);
	return mArray[index];
}

}

#endif

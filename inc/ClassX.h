#ifndef CLASSX_H
#define CLASSX_H

#include "BaseClass.h"

namespace OperatorTest {

class ClassX : public BaseClass {
	public:
		ClassX() {
			log->log("Constructor ClassX this - %p", this);
		}
		ClassX(const ClassX & copy) {
			log->log("Copy Constructor ClassX this - %p, copy from - %p", this, &copy);
		}
		~ClassX() {
			log->log("Destructor ClassX this - %p", this);
		}
		const ClassX & operator = (const int & value) {
			log->log("Operator = (int) value = %d", value);
			mValue = value;
			return *this;
		}
		
	private:
		int mValue;
	public:
		void set(int value) {
			mValue = value;
		}
		int get() {
			return mValue;
		}
};

}

#endif

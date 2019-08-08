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
			log->log("Operator = (int) for %p value = %d", this, value);
			mValue = value;
			return *this;
		}
		const ClassX & operator = (const ClassX & value) {
			log->log("Operator = (ClassX) for %p value = %d from %p", this, value.mValue, &value);
			mValue = value.mValue;
			return *this;
		}
		const ClassX & operator ++ (int) {
			log->log("Operator ClassX++ for %p value = %d", this, mValue);
			this->mValue++;
			return *this;
		}
		const ClassX & operator ++ () {
			log->log("Operator ++ClassX for %p value = %d", this, mValue);
			this->mValue++;
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

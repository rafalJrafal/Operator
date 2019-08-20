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
			LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			sLog->log("Destructor ClassX this - %p", this);
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
		const ClassX & operator + (const ClassX & value) {
			log->log("Operator + ClassX for %p", this);
			this->mValue += value.mValue;
			return *this;
		}
/*		void * operator new (size_t size) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			ClassX * p = ::new ClassX();
			sLog->log("Operator new ClassX %p size = %d.", p, size);
			return p;
		}
		void * operator new (size_t size, const char * file, int line) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			ClassX * p = new(file, line) ClassX();
			sLog->log("Operator new ClassX %p size = %d.", p, size);
			return p;
		}
		void * operator new (size_t size, unsigned int numAllocations) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			sLog->log("Operator new ClassX size = %d, num alloc = %d", size, numAllocations);
			for (int i = 0; i < numAllocations; i++) {
				ClassX * p = ::new ClassX;
				sLog->log("Operator new ClassX %p tmpAlloc = %d", p, i);
				delete p;				
			}
			ClassX * p = ::new ClassX();
			sLog->log("Operator new ClassX %p size = %d.", p, size);
			return p;
		}
		void * operator new (size_t size, unsigned int numAllocations, const char * file, int line) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			sLog->log("Operator new ClassX size = %d, num alloc = %d", size, numAllocations);
			for (int i = 0; i < numAllocations; i++) {
				ClassX * p = ::new ClassX;
				sLog->log("Operator new ClassX %p tmpAlloc = %d", p, i);
				delete p;				
			}
			ClassX * p = ::new ClassX();
			sLog->log("Operator new ClassX %p size = %d.", p, size);
			return p;
		}
		void * operator new [] (size_t size) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			const unsigned int numberOfElements = size/sizeof(ClassX);
			ClassX * p = ::new ClassX[numberOfElements];
			sLog->log("Operator new ClassX %p size = %d sizefo(ClassX) = %d, numberOfElements = %d.", 
				p, size, sizeof(ClassX), numberOfElements);
			return p;
		}
		void * operator new [] (size_t size, const char * file, int line) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			const unsigned int numberOfElements = size/sizeof(ClassX);
			ClassX * p = new (file, line) ClassX[numberOfElements];
			sLog->log("Operator new ClassX %p size = %d sizefo(ClassX) = %d, numberOfElements = %d.", 
				p, size, sizeof(ClassX), numberOfElements);
			return p;
		}
		void operator delete (void * p) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			sLog->log("Operator delete ClassX %p", p);
			ClassX * x_p = (ClassX*)p;
			::delete x_p;
		}
		void operator delete [] (void * p) {
			static LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			sLog->log("Operator delete [] ClassX %p", p);
			ClassX * x_p = (ClassX*)p;
			::delete [] x_p;
		} */
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

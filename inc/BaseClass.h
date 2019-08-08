#ifndef BASECLASS_H
#define BASECLASS_H

#include "../../LogSystem/inc/LogSystem.h"

namespace OperatorTest {

class BaseClass {
	public:
		BaseClass() {
			log = LogSystem::LogSystem::instance("operator.txt");
			log->log("Constructor BaseClass this - %p", this);
		}
		~BaseClass() {
			log->log("Destructor BaseClass this - %p", this);
		}
		BaseClass(const BaseClass& copy) {
			log->log("Copy Constructor BaseClass this - %p copy from %d", this, &copy);
		}
	protected:
		LogSystem::LogSystem * log;
};

}

#endif

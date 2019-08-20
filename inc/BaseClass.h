#ifndef BASECLASS_H
#define BASECLASS_H

#include "../../LogSystem/inc/LogSystem.h"

namespace OperatorTest {

const char OPERATOR_LOG_FILENAME [] = "operator.txt";

class BaseClass {
	public:
		BaseClass() {
			log = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			log->log("Constructor BaseClass this - %p", this);
		}
		~BaseClass() {
			LogSystem::LogSystem * sLog = LogSystem::LogSystem::instance(OPERATOR_LOG_FILENAME);
			sLog->log("Destructor BaseClass this - %p", this);
		}
		BaseClass(const BaseClass& copy) {
			log->log("Copy Constructor BaseClass this - %p copy from %d", this, &copy);
		}
	protected:
		LogSystem::LogSystem * log;
};

}

#endif

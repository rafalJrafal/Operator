#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
#include "../../SystemCalls/inc/MemoryMonitorInclude.h"

#include "../../LogSystem/inc/LogSystem.h"

namespace OperatorTest {

const char OPERATOR_LOG_FILENAME [] = "operator.txt";

class BaseClass {
	public:
		BaseClass() {
			log = NamespaceLog::LogSystem::instance(OPERATOR_LOG_FILENAME);
			log->log("Constructor BaseClass this - %p", this);
		}
		BaseClass(const char * fileName) {
			log = NamespaceLog::LogSystem::instance(fileName);
			log->log("Constructor BaseClass this - %p", this);
		}
		~BaseClass() {
			NamespaceLog::LogSystem * sLog = NamespaceLog::LogSystem::instance(OPERATOR_LOG_FILENAME);
			sLog->log("Destructor BaseClass this - %p", this);
		}
		BaseClass(const BaseClass& copy) {
			log->log("Copy Constructor BaseClass this - %p copy from %d", this, &copy);
		}
	protected:
		NamespaceLog::LogSystem * log;
};

}

#endif

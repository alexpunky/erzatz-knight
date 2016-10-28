#include "Logger.hpp"

using namespace ErzatzKnight;

FileLogger * FileLogger::instance = new FileLogger("erzatz.log");

FileLogger * FileLogger::getInstance() {
	return FileLogger::instance;
}
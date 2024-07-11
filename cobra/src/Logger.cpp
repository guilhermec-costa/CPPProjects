#include "Logger.h"
#include <iostream>

time_t* Logger::m_rawtime = new time_t;
tm* Logger::m_timeinfo = new tm;

Logger::Logger() 
{}
Logger& Logger::operator=(const Logger&) {
	return *this;
}

Logger::Logger(Logger const&) {}

Logger& Logger::s_get_instance()
{
	static Logger* logger = new Logger();
	return *logger;
}

void Logger::log(const char* msg)
{
	std::cout << msg << std::endl;
}

void Logger::log_err(const char* err)
{
	time(m_rawtime);
	struct tm tmp = *localtime(m_rawtime);
	*m_timeinfo = tmp;
	std::cerr << "[ERROR] >> " << err << " at " << asctime(m_timeinfo) << std::endl;
}

Logger::~Logger()
{
	delete m_rawtime;
	delete m_timeinfo;
}
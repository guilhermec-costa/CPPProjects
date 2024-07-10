#include "Logger.h"
#include <iostream>
#include <ctime>

Logger::Logger()
{
	m_rawtime = new time_t;
	if (m_rawtime == nullptr) 
	{
		std::cerr << "Falha ao alocar memória para m_rawtime" << std::endl;
		std::abort();
	}
	m_timeinfo = new tm;
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
	std::cout << "[ERROR] >> " << err << " at " << asctime(m_timeinfo) << std::endl;
}

Logger::~Logger()
{
	delete m_rawtime;
	delete m_timeinfo;
}
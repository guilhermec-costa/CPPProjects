#pragma once
#include <ctime>

class Logger
{
private:
	Logger();
	Logger(const Logger&);
	Logger& operator=(const Logger&);
	~Logger();
public:
	static Logger& s_get_instance();
	static void log(const char*);
	static void log_err(const char*);
private:
	static time_t* m_rawtime;
	static struct tm* m_timeinfo;
};

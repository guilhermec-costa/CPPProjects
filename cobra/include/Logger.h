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
	void log(const char*);
	void log_err(const char*);
private:
	time_t* m_rawtime;
	struct tm* m_timeinfo;
};

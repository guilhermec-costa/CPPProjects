#ifndef LOGGER_H
#define LOGGER_H
#include <ctime>

class Logger
{
public:
	Logger();
	~Logger();
	void log(const char*);
	void log_err(const char*);
private:
	time_t* m_rawtime;
	struct tm* m_timeinfo;
};

#endif LOGGER_H
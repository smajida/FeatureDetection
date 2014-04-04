/*
 * Logger.cpp
 *
 *  Created on: 01.03.2013
 *      Author: Patrik Huber
 */

#include "logging/Logger.hpp"
#include "logging/Appender.hpp"

namespace logging {

Logger::Logger(string name) : name(name), appenders() {}

Logger::~Logger() {}

void Logger::log(const Loglevel logLevel, string logMessage)
{
	for (shared_ptr<Appender> appender : appenders) {
		appender->log(logLevel, name, logMessage);
	}
}

void Logger::addAppender(shared_ptr<Appender> appender)
{
	appenders.push_back(appender);
}

void Logger::trace(const string logMessage)
{
	log(Loglevel::Trace, logMessage);
}

void Logger::debug(const string logMessage)
{
	log(Loglevel::Debug, logMessage);
}

void Logger::info(const string logMessage)
{
	log(Loglevel::Info, logMessage);
}

void Logger::warn(const string logMessage)
{
	log(Loglevel::Warn, logMessage);
}

void Logger::error(const string logMessage)
{
	log(Loglevel::Error, logMessage);
}

void Logger::panic(const string logMessage)
{
	log(Loglevel::Panic, logMessage);
}

} /* namespace logging */

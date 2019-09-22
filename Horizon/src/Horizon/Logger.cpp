#include "Logger.h"    
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Horizon {

	std::shared_ptr<spdlog::logger> Logger::coreLogger;
	std::shared_ptr<spdlog::logger> Logger::clientLogger;


	void Logger::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$"); // Sets color and format of "[TIME] LOGGER: MSG"

		coreLogger = spdlog::stderr_color_mt("HORIZON");
		coreLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stderr_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}
}
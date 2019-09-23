#pragma once
#pragma 

#include "Core.h"   
#include "spdlog/spdlog.h"

#pragma warning(push)
#pragma warning(disable:4251)

namespace Horizon {

	class HORIZON_API Logger
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger> getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger> getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

// Horizon logger macros
#define HZ_CORE_TRACE(...) ::Horizon::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::Horizon::Logger::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::Horizon::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Horizon::Logger::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Horizon::Logger::getCoreLogger()->critical(__VA_ARGS__)

// Client logger macros
#define HZ_TRACE(...) ::Horizon::Logger::getClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...) ::Horizon::Logger::getClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...) ::Horizon::Logger::getClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...) ::Horizon::Logger::getClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...) ::Horizon::Logger::getClientLogger()->critical(__VA_ARGS__)


#pragma warning(pop)
#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Apteuic { 

	class APTU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

	

}

//Core Logging Macros
#define APTU_CORE_TRACE(...) ::Apteuic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define APTU_CORE_INFO(...)  ::Apteuic::Log::GetCoreLogger()->info(__VA_ARGS__)
#define APTU_CORE_WARN(...)  ::Apteuic::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define APTU_CORE_ERROR(...) ::Apteuic::Log::GetCoreLogger()->error(__VA_ARGS__)
#define APTU_CORE_FATAL(...) ::Apteuic::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Logging Macros
#define APTU_TRACE(...) ::Apteuic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define APTU_INFO(...)  ::Apteuic::Log::GetClientLogger()->info(__VA_ARGS__)
#define APTU_WARN(...)  ::Apteuic::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APTU_ERROR(...) ::Apteuic::Log::GetClientLogger()->error(__VA_ARGS__)
#define APTU_FATAL(...) ::Apteuic::Log::GetClientLogger()->critical(__VA_ARGS__)
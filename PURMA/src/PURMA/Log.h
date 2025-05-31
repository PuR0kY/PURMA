#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace PURMA {

	class PUR_API Log
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

// Core log macros
// NOTE: #define tells preprocessor to create symbolic replacement (search-and-replace) before compilation even begins
#define PUR_CORE_TRACE(...) ::PURMA::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PUR_CORE_INFO(...)  ::PURMA::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PUR_CORE_WARN(...)  ::PURMA::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PUR_CORE_ERROR(...) ::PURMA::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PUR_CORE_FATAL(...) ::PURMA::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
// NOTE: 
#define PUR_TRACE(...)		::PURMA::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PUR_INFO(...)		::PURMA::Log::GetClientLogger()->info(__VA_ARGS__)
#define PUR_WARN(...)		::PURMA::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PUR_ERROR(...)		::PURMA::Log::GetClientLogger()->error(__VA_ARGS__)
#define PUR_FATAL(...)		::PURMA::Log::GetClientLogger()->fatal(__VA_ARGS__)

// Math macros
#define SQUARE(x) ((x) * (x))
#define PI 3.14159

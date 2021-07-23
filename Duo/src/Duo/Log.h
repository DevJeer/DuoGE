#pragma once

#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Duo {
	class DUO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log macros
#define DUO_CORE_TRACE(...)		::Duo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DUO_CORE_INFO(...)		::Duo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DUO_CORE_WARN(...)		::Duo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DUO_CORE_ERROR(...)		::Duo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DUO_CORE_CRITICAL(...)  ::Duo::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log macros
#define DUO_TRACE(...)		::Duo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DUO_INFO(...)		::Duo::Log::GetClientLogger()->info(__VA_ARGS__)
#define DUO_WARN(...)		::Duo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DUO_ERROR(...)		::Duo::Log::GetClientLogger()->error(__VA_ARGS__)
#define DUO_CRITICAL(...)	::Duo::Log::GetClientLogger()->critical(__VA_ARGS__)
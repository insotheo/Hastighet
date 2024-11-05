#ifndef HE_LOG_HPP
#define HE_LOG_HPP

#include <chrono>
#include <ctime>
#include <iomanip>

#include "Core.h"

namespace Hastighet{

    class HASTIGHET_API Log{
    public:
        static void trace(const std::string& message, const std::string& sender);
        static void info(const std::string& message, const std::string& sender);
        static void warn(const std::string& message, const std::string& sender);
        static void error(const std::string& message, const std::string& sender);
    private:
        static std::string getLocalTime();
    };

}

#define HASTIGHET_CORE_LOG_TRACE(msg) Hastighet::Log::trace(std::string(msg), "HastighetEngine")  
#define HASTIGHET_CORE_LOG_INFO(msg) Hastighet::Log::info(std::string(msg), "HastighetEngine")  
#define HASTIGHET_CORE_LOG_WARN(msg) Hastighet::Log::warn(std::string(msg), "HastighetEngine")  
#define HASTIGHET_CORE_LOG_ERROR(msg) Hastighet::Log::error(std::string(msg), "HastighetEngine")  

#define HASTIGHET_CLIENT_LOG_TRACE(msg) Hastighet::Log::trace(std::string(msg), "Client")  
#define HASTIGHET_CLIENT_LOG_INFO(msg) Hastighet::Log::info(std::string(msg), "Client")  
#define HASTIGHET_CLIENT_LOG_WARN(msg) Hastighet::Log::warn(std::string(msg), "Client")  
#define HASTIGHET_CLIENT_LOG_ERROR(msg) Hastighet::Log::error(std::string(msg), "Client")  

#endif
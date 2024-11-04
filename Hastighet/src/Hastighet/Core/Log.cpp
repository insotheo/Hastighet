#include "Log.hpp"

/*
RESET_COLOR "\033[0m"
RED_TEXT "\033[1;31m"
GREEN_TEXT "\033[1;32m"
YELLOW_TEXT "\033[1;33m"
BLUE_TEXT "\033[1;34m"
WHITE_TEXT "\033[1;37m"
*/

namespace Hastighet{

    std::string Log::getLocalTime(){
        auto now = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);
        struct tm time_info;
        localtime_s(&time_info, &current_time);
        char time_buffer[26];
        std::strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", &time_info);
        return time_buffer;
    }

    void Log::trace(const std::string& message, const std::string& sender){
        std::cout 
        << "\033[1;34m" //blue
        << "[" << getLocalTime() << "] " << sender << ": " << "\"" << message << "\""
        << "\033[0m" << "\n";
    }

    void Log::info(const std::string& message, const std::string& sender){
        std::cout 
        << "\033[1;32m" //green 
        << "[" << getLocalTime() << "] " << sender << ": " << "\"" << message << "\""
        << "\033[0m" << "\n";
    }

    void Log::warn(const std::string& message, const std::string& sender){
        std::cout 
        << "\033[1;33m" //yellow
        << "[" << getLocalTime() << "] " << sender << ": " << "\"" << message << "\""
        << "\033[0m" << "\n";
    }

    void Log::error(const std::string& message, const std::string& sender){
        std::cout 
        << "\033[1;31m" //red
        << "[" << getLocalTime() << "] " << sender << ": " << "\"" << message << "\""
        << "\033[0m" << "\n";
    }

}
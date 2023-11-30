#include <iostream>
#include <string>

// Enumeration for log severity levels
enum class LogSeverity { SEVERE, ERROR, WARNING, INFO };

// Structure representing the log context
struct LogContext {
    LogSeverity severity;
    const char* message;
};

// External SDAOSlogger function
extern void SDAOSlogger(const LogContext& logcontext);

// Singleton Logger class using the Facade pattern
class Logger {
public:
    // Get the singleton instance
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    // Log functions for different severity levels
    void logSevere(const std::string& message) {
        log({LogSeverity::SEVERE, message.c_str()});
    }

    void logError(const std::string& message) {
        log({LogSeverity::ERROR, message.c_str()});
    }

    void logWarning(const std::string& message) {
        log({LogSeverity::WARNING, message.c_str()});
    }

    void logInfo(const std::string& message) {
        log({LogSeverity::INFO, message.c_str()});
    }

private:
    // Private constructor to enforce Singleton pattern
    Logger() {}

    // Private log function to handle the SDAOSlogger
    void log(const LogContext& logContext) {
        SDAOSlogger(logContext);
    }
};

int main() {
    // Example usage of the Logger
    Logger& logger = Logger::getInstance();

    logger.logSevere("This is a severe error!");
    logger.logError("This is an error!");
    logger.logWarning("This is a warning!");
    logger.logInfo("This is an informational message");

    return 0;
}

from enum import Enum

class Severity(Enum):
    WARNING = 1
    ERROR = 2
    UNRECOVERABLE = 3

class Logger:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(Logger, cls).__new__(cls)
            cls._instance.log_file = None
        return cls._instance

    @classmethod
    def Startup(cls, log_file_name):
        cls._instance.log_file = open(log_file_name, 'a')

    @classmethod
    def Shutdown(cls):
        if cls._instance.log_file:
            cls._instance.log_file.close()

    @classmethod
    def LogMessage(cls, severity, service, error_text):
        if cls._instance.log_file:
            cls._instance.log_file.write(f"[{severity.name}] - Service: {service} - Error: {error_text}\n")
        else:
            print("Error: Log file not initialized.")

# Test program
if __name__ == "__main__":
    log_file_name = input("Enter log file name: ")
    Logger.Startup(log_file_name)

    while True:
        severity_input = input("Enter severity (WARNING, ERROR, UNRECOVERABLE) or 'quit' to exit: ").upper()

        if severity_input == "QUIT":
            break

        if severity_input in Severity.__members__:
            severity = Severity[severity_input]
            service = input("Enter service name: ")
            error_text = input("Enter error message: ")
            Logger().LogMessage(severity, service, error_text)
        else:
            print("Invalid severity level. Please enter WARNING, ERROR, UNRECOVERABLE, or quit.")

    Logger.Shutdown()

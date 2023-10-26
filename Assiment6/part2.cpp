#include <iostream>
#include <string>

struct Office {
    std::string m_street;
    std::string m_city;
    int m_cubicle;
};

class Employee {
private:
    std::string m_name;
    Office* m_office;

    Employee(std::string n, Office* o) : m_name(n), m_office(o) {}

public:
    Employee(const Employee& rhs) : m_name{rhs.m_name}, m_office{new Office{*rhs.m_office}} {}

    Employee& operator=(const Employee& rhs) {
        if (this == &rhs) return *this;
        m_name = rhs.m_name;
        m_office = new Office{*rhs.m_office};
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& o) {
        return os << o.m_name << " works at " << o.m_office->m_street << " " << o.m_office->m_city
                  << " seats @" << o.m_office->m_cubicle;
    }

    ~Employee() {
        delete m_office;
    }

    friend class EmployeeFactory;
};

class EmployeeFactory {
public:
    static Employee createEmployee(std::string name, std::string street, std::string city, int cubicle) {
        Office* office = new Office{street, city, cubicle};
        return Employee(name, office);
    }
};

int main() {
    Employee john = EmployeeFactory::createEmployee("John Doe", "123 Main St", "Cityville", 42);
    std::cout << john << std::endl;

    Employee jane = EmployeeFactory::createEmployee("Jane Smith", "456 Elm St", "Townsville", 23);
    std::cout << jane << std::endl;

    // When the objects go out of scope, the destructor will delete the dynamically allocated office objects.
    return 0;
}

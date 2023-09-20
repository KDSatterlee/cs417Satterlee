#include <iostream>
#include <string>
#include <functional>

struct S {
    std::string firstName;
    std::string lastName;
    std::string address;
};

size_t hashStruct(const S& s) {
    size_t hashFirstName = std::hash<std::string>{}(s.firstName);
    size_t hashLastName = std::hash<std::string>{}(s.lastName);
    size_t hashAddress = std::hash<std::string>{}(s.address);

    // Combine the hashes using XOR (^)
    return hashFirstName ^ hashLastName ^ hashAddress;
}

int main() {
    S s = {"John", "Doe", "123 Main St."};
    size_t hashValue = hashStruct(s);
    
    std::cout << "Hash Value: " << hashValue << std::endl;
    
    return 0;
}

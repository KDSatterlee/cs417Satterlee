#include <iostream>
#include <string>
#include <functional>

struct S {
    std::string firstName;
    std::string lastName;
    std::string address;
};

struct HashS {
    std::size_t operator()(const S& s) const {
        std::size_t hashFirstName = std::hash<std::string>{}(s.firstName);
        std::size_t hashLastName = std::hash<std::string>{}(s.lastName);
        std::size_t hashAddress = std::hash<std::string>{}(s.address);

        // Combine the hashes using XOR (^)
        return hashFirstName ^ hashLastName ^ hashAddress;
    }
};

int main() {
    S s = {"John", "Doe", "123 Main St."};
    HashS hashFunction;
    std::size_t hashValue = hashFunction(s);
    
    std::cout << "Hash Value: " << hashValue << std::endl;
    
    return 0;
}

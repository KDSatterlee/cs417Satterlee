#ifndef NOTETAKINGAPP_HPP
#define NOTETAKINGAPP_HPP

#include "IndexCard.hpp"
#include <map>
#include <vector>

class NoteTakingApp {
private:
    std::map<std::string, IndexCard> indexCards;

public:
    void insert(const IndexCard& card);
    IndexCard* search(const std::string& keyword);
    std::vector<IndexCard> getAllCards() const;
};

#endif

#include "NoteTakingApp.hpp"

void NoteTakingApp::insert(const IndexCard& card) {
    indexCards[card.getKeyword()] = card;
}

IndexCard* NoteTakingApp::search(const std::string& keyword) {
    auto it = indexCards.find(keyword);
    if (it != indexCards.end()) {
        return &it->second;
    }
    return nullptr;
}

std::vector<IndexCard> NoteTakingApp::getAllCards() const {
    std::vector<IndexCard> cards;
    for (const auto& pair : indexCards) {
        cards.push_back(pair.second);
    }
    return cards;
}

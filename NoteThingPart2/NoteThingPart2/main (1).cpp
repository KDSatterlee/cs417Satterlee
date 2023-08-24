#include <iostream>
#include "IndexCard.hpp"
#include "NoteTakingApp.hpp"

int main() {
    NoteTakingApp app;

    IndexCard card1(1, "keyword1", "content1");
    IndexCard card2(2, "keyword2", "content2");
    IndexCard card3(3, "keyword3", "content3");

    app.insert(card1);
    app.insert(card2);
    app.insert(card3);

    IndexCard* result = app.search("keyword2");

    if (result) {
        std::cout << "Found card with keyword 'keyword2':" << std::endl;
        std::cout << "Index: " << result->getIndexNumber() << std::endl;
        std::cout << "Keyword: " << result->getKeyword() << std::endl;
        std::cout << "Content: " << result->getContent() << std::endl;
    } else {
        std::cout << "Card not found." << std::endl;
    }

    std::vector<IndexCard> cards = app.getAllCards();
    std::cout << "All cards:" << std::endl;
    for (const IndexCard& card : cards) {
        std::cout << "Index: " << card.getIndexNumber() << ", Keyword: " << card.getKeyword() << ", Content: " << card.getContent() << std::endl;
    }

    return 0;
}

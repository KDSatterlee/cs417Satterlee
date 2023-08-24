#include "IndexCard.hpp"

IndexCard::IndexCard() : indexNumber(0), keyword(""), content("") {}

IndexCard::IndexCard(int index, const std::string& key, const std::string& cont)
    : indexNumber(index), keyword(key), content(cont) {}

int IndexCard::getIndexNumber() const {
    return indexNumber;
}

const std::string& IndexCard::getKeyword() const {
    return keyword;
}

const std::string& IndexCard::getContent() const {
    return content;
}

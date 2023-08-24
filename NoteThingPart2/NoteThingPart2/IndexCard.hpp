#ifndef INDEXCARD_HPP
#define INDEXCARD_HPP

#include <string>

class IndexCard {
private:
    int indexNumber;
    std::string keyword;
    std::string content;

public:
    IndexCard();
    IndexCard(int index, const std::string& key, const std::string& cont);

    int getIndexNumber() const;
    const std::string& getKeyword() const;
    const std::string& getContent() const;
};

#endif

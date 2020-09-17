#pragma once
template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    end--;
    for (auto it = (end - begin) / 2; begin != end && it > 0; begin++, end--, it--) {
        if (*begin != *end)
            return false;
    }
    return true;
}
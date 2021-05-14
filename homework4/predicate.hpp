using namespace std;

#include <string>

template<typename TIterator, typename TPredicate>
bool anyOf(TIterator begin, TIterator end, TPredicate func) {
    while (begin != end) {
        if (func(*begin)) {
            return true;
        }
        ++begin;
    }
    return false;
}

template<typename TIterator, typename TPredicate>
bool allOf(TIterator begin, TIterator end, TPredicate func) {
    while (begin != end) {
        if (!func(*begin)) {
            return false;
        }
        ++begin;
    }
    return true;
}

template<typename TIterator, typename TPredicate>
bool noneOf(TIterator begin, TIterator end, TPredicate func) {
    while (begin != end) {
        if (func(*begin)) {
            return false;
        }
        ++begin;
    }
    return true;
}

template<typename TIterator, typename TPredicate>
bool oneOf(TIterator begin, TIterator end, TPredicate func) {
    int count = 0;
    while (begin != end) {
        if (func(*begin)) {
            ++count;
        }
        ++begin;
    }
    return count == 1;
}


template<typename TIterator, typename TCompare = std::less<>>
bool isSorted(TIterator begin, TIterator end, TCompare func = TCompare()) {
    while (begin != end - 1) {
        if (!func(*begin, *(begin + 1))) {
            return false;
        }
        ++begin;
    }
    return true;
}


template<class TIterator, typename TPredicate>
bool isPartitioned(TIterator begin, TIterator end, TPredicate func) {
    TIterator i = begin;
    while (begin != end) {
        if (!func(*begin)) {
            i = begin;
            break;
        }
        ++begin;
    }

    while (i != end) {
        if (func(*i)) {
            return false;
        }
        ++i;
    }
    return true;
}

template<typename TIterator, typename T>
TIterator findNot(TIterator begin, TIterator end, const T &value) {
    while (begin != end) {
        if (*begin != value) {
            return begin;
        }
        ++begin;
    }
    return end;
}

template<typename TIterator, typename T>
TIterator findBackward(TIterator begin, TIterator end, const T &value) {
    TIterator tmp = end;
    while (begin != end) {
        if (*begin == value) {
            tmp = begin;
        }
        ++begin;
    }
    return tmp;
}

template<typename TIterator, typename TPredicate>
bool isPalindrome(TIterator begin, TIterator end, TPredicate func) {
    --end;
    while (distance(begin, end) > 0) {
        if (!func(*begin, *end)) {
            return false;
        }
        ++begin;
        --end;
    }
    return true;
}
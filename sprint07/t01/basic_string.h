#pragma once
#include <iostream>

namespace CBL {
template <class T>
class BasicString {
public:
    using iterator = T*;
    static const size_t npos = -1ul;

    BasicString() = default;

    BasicString(const BasicString<T>& str) : BasicString(str.begin(), str.end()) {}

    BasicString(const BasicString<T>& str, size_t pos, size_t len = npos) : BasicString(str.begin() + pos, len == npos ? str.end() : str.begin() + (len + pos)) {}

    explicit BasicString(const T* str) {
        int size = 0;
        for (; str[size]; size++);
        m_buffer = new T[size + 1];
        m_size = size;
        m_buffer[m_size + 1] = 0;
        for (int i = 0; i < size; i++) {
            m_buffer[i] = str[i];
        }
    }

    BasicString(const T* str, size_t n) {
        m_buffer = new T[n + 1];
        m_size = n;
        m_buffer[m_size + 1] = 0;
        for (size_t i = 0; i < n; i++) {
            m_buffer[i] = *(str + i);
        }
    }

    BasicString(size_t n, T c) {
        m_size = n;
        m_buffer = new T[m_size + 1];
        m_buffer[m_size + 1] = 0;
        for (size_t i = 0; i < n; i++) {
            m_buffer[i] = c;
        }
    }

    BasicString(iterator first, iterator last) {
        m_size = std::distance(first, last);
        m_buffer = new T[m_size + 1];
        m_buffer[m_size + 1] = 0;
        int i = 0;
        for (auto f = first; f != last; f++, i++) {
            m_buffer[i] = *f;
        }
    }

    virtual ~BasicString() {
        delete[] m_buffer;
    }
    // iterators

    iterator begin() const {
        return m_buffer;
    }

    iterator end() const {
        return m_buffer + m_size;
    }

    // capacity
    size_t length() const {
        return m_size;
    }

    T& operator[](size_t index) const {
        return *(m_buffer + index);
    }

    T& at(size_t index) const {
        if (index >= m_size)
            throw "index > size";
        return m_buffer[index];
    }

    T& back() const {
        return m_buffer[m_size - 1];
    }

    T& front() const {
        return m_buffer[0];
    }
    // modifiers
    BasicString<T>& operator=(const BasicString<T>& str) {
        if (this != &str) {
            m_size = str.m_size;
            m_buffer = new T[m_size];
            std::copy(str.begin(), str.end(), m_buffer);
        }
        return *this;
    }

    BasicString<T>& operator=(const T* str) {
        return operator=(BasicString(
            str));
    }

    BasicString<T>& operator=(const T c) {
        *this = BasicString(1, c);
        return *this;
    }

    BasicString<T>& operator+=(const BasicString<T>& str) {
        size_t size = m_size + str.m_size + 1;
        T* m_buff = new T[size];
        m_buff[size] = 0;
        size_t i = 0;
        for (; i < m_size; i++) {
            m_buff[i] = m_buffer[i];
        }
        for (int j = 0; i < size - 1; i++, j++) {
            m_buff[i] = str[j];
        }
        delete[] m_buffer;
        m_buffer = m_buff;
        m_size = size - 1;
        return *this;
    }

    BasicString<T>& operator+=(const T* str) {
        return operator+=(BasicString(str));
    }

    BasicString<T>& operator+=(const T c) {
        return operator+=(BasicString(1, c));
    }

    void append(const BasicString<T>& str) {
        operator+=(str);
    }

    void append(const T* str) {
        operator+=(BasicString(str));
    }

    void append(const T* str, size_t n) {
        operator+=(BasicString(str, str + n));
    }

    void append(size_t n, T c) {
        operator+=(BasicString(n, c));
    }

    void append(iterator first, iterator last) {
        operator+=(BasicString(first, last));
    }

    void swap(BasicString<T>& str) {
        T* m_buff = str.c_str;
        size_t size = str.m_size;

        str.m_buffer = m_buffer;
        str.m_size = m_size;
        m_buffer = m_buff;
        m_size = size;
    }
    // string operations
    const T* c_str() const {
        return m_buffer;
    }
    virtual int compare(const BasicString<T>& str) const {
        for (size_t i = 0; str[i] || m_buffer[i]; i++) {
            if (str[i] != m_buffer[i])
                return m_buffer[i] - str[i];
        }
        return 0;
    }
    virtual int compare(const T* str) const {
        for (size_t i = 0; str[i] || m_buffer[i]; i++) {
            if (str[i] != m_buffer[i])
                return m_buffer[i] - str[i];
        }
        return 0;
    }

protected:
    size_t m_size{0};
    T* m_buffer{nullptr};
};

class String : public BasicString<char> {
public:
    using BasicString<char>::BasicString;
    using BasicString<char>::operator=;
    using BasicString<char>::operator+=;
    using BasicString<char>::operator[];
    int compare(const BasicString<char>& str) const override {
        for (size_t i = 0; str[i] || m_buffer[i]; i++) {
            if (str[i] != m_buffer[i])
                return m_buffer[i] - str[i];
        }
        return 0;
    }

    int compare(const char* str) const override {
        for (size_t i = 0; str[i] || m_buffer[i]; i++) {
            if (str[i] != m_buffer[i])
                return m_buffer[i] - str[i];
        }
        return 0;
    }
    size_t find(const String& str, size_t pos = 0) const {
        for (; pos < this->m_size; pos++) {
            if (this[pos].compare(str) == 0) {
                return pos;
            }
        }
        return npos;
    }

    size_t find(const char* str, size_t pos = 0) const {
        for (; pos < this->m_size; pos++) {
            if (this[pos].compare(str) == 0) {
                return pos;
            }
        }
        return npos;
    }

    size_t find(char c, size_t pos = 0) const {
        for (; pos < this->m_size; pos++) {
            if (this->m_buffer[pos] == c) {
                return pos;
            }
        }
        return npos;
    }

    size_t rfind(const String& str, size_t pos = 0) const {
        for (pos = this->m_size; pos > 0; pos--) {
            if (this[pos].compare(str) == 0) {
                return pos;
            }
        }
        return npos;
    }
    
    size_t rfind(const char* str, size_t pos = 0) const {
        for (pos = this->m_size; pos > 0; pos--) {
            if (this[pos].compare(str) == 0) {
                return pos;
            }
        }
        return npos;
    }
    size_t rfind(char c, size_t pos = 0) const {
        for (pos = this->m_size; pos > 0; pos--) {
            if (this->m_buffer[pos] == c) {
                return pos;
            }
        }
        return npos;
    }
};

class WString : public BasicString<wchar_t> {
public:
    using BasicString<wchar_t>::BasicString;
    using BasicString<wchar_t>::operator=;
    using BasicString<wchar_t>::operator+=;
    using BasicString<wchar_t>::operator[];

    int compare(const BasicString<wchar_t>& str) const override {
        for (size_t i = 0; str[i] || m_buffer[i]; i++) {
            if (str[i] != m_buffer[i])
                return m_buffer[i] - str[i];
        }
        return 0;
    }

    int compare(const wchar_t* str) const override {
        for (size_t i = 0; str[i] || m_buffer[i]; i++) {
            if (str[i] != m_buffer[i])
                return m_buffer[i] - str[i];
        }
        return 0;
    }

    size_t find(const WString& str, size_t pos = 0) const {
        for (; pos < this->m_size; pos++) {
            if (this[pos].compare(str) == 0) {
                return pos;
            }
        }
        return npos;
    }
    size_t find(const wchar_t* str, size_t pos = 0) const {
        for (; pos < this->m_size; pos++) {
            if (this[pos].compare(str) == 0) {
                std::cout << pos <<std::endl;
                return pos;
            }
        }
        return npos;
    }
    size_t find(wchar_t c, size_t pos = 0) const {
        for (; pos < this->m_size; pos++) {
            if (this->m_buffer[pos] == c) {
                return pos;
            }
        }
        return npos;
    }
    size_t rfind(const WString& str, size_t pos = 0) const {
        for (pos = this->m_size; pos > 0; pos--) {
            if (this[pos].compare(str) == 0) {
                return pos;
            }
        }
        return npos;
    }
    size_t rfind(const wchar_t* str, size_t pos = 0) const {
        for (pos = this->m_size; pos > 0; pos--) {
            if (this[pos].compare(str) == 0) {
                return pos;
            }
        }
        return npos;
    }
    size_t rfind(wchar_t c, size_t pos = 0) const {
        for (pos = this->m_size; pos > 0; pos--) {
            if (this->m_buffer[pos] == c) {
                return pos;
            }
        }
        return npos;
    }
};
}  // namespace CBL

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString v(lhs);
    v += rhs;
    return v;
}

template <class T>
CBL::BasicString<T> operator+(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator+(CBL::BasicString(lhs), rhs);
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator+(lhs, CBL::BasicString(rhs));
}

template <class T>
CBL::BasicString<T> operator+(const T lhs, const CBL::BasicString<T>& rhs) {
    return operator+(CBL::BasicString(1, lhs), rhs);
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T rhs) {
    return operator+(lhs, CBL::BasicString(1, rhs));
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T>
bool operator==(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator==(CBL::BasicString(lhs), rhs);
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator==(lhs, CBL::BasicString(rhs));
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(operator==(lhs, rhs));
}

template <class T>
bool operator!=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(operator==(lhs, rhs));
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(operator==(lhs, rhs));
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T>
bool operator<(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator<(lhs, rhs);
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator<(lhs, rhs);
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return (operator<(lhs, rhs) || operator==(lhs, rhs));
}

template <class T>
bool operator<=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator<=(lhs, rhs);
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator<=(lhs, rhs);
}

template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return (!operator<(lhs, rhs));
}

template <class T>
bool operator>(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator>(lhs, rhs);
}

template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator>(lhs, rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return (!operator<(lhs, rhs));
}

template <class T>
bool operator>=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator>=(lhs, rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator>=(lhs, rhs);
}
/* Derived class additional member functions */

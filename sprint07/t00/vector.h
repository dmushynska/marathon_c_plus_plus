#pragma once
#include <iostream>
#include <memory>

inline void getCapacity(size_t size, size_t &capacity) {
    if (capacity == 0) {
        capacity = 2;
    }
    while (size > capacity) {
        capacity *= 2;
    }
}

namespace CBL {
template <class T>
class Vector {
public:
    using iterator = T*;
    Vector() = default;

    explicit Vector(size_t size) {
        m_size += size;
        getCapacity(m_size, m_capacity);
        m_buffer = new T[m_capacity];
    }

    Vector(size_t size, const T& value) {
        m_size = size;
        getCapacity(m_size, m_capacity);
        m_buffer = new T[m_capacity];

        for (size_t i = 0; i < size; i++) {
            m_buffer[i] = value;
        }
    }

    Vector(iterator first, iterator last) {
        m_size = std::distance(first, last);
        getCapacity(m_size, m_capacity);
        m_buffer = new T[m_capacity];
        int i = 0;

        for (auto f = first; f != last; f++, i++) {
            m_buffer[i] = *f;
        }
    }

    Vector(const std::initializer_list<T>& lst) {
        m_size = lst.size();
        getCapacity(m_size, m_capacity);
        m_buffer = new T[m_capacity];

        int i = 0;
        for (auto f = lst.begin(); f != lst.end(); f++, i++) {
            m_buffer[i] = *f;
        }
    }

    Vector(const Vector<T>& other) {
        *this = other;
    }

    ~Vector() {
        delete[] m_buffer;
    }

    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_buffer = new T[m_capacity];
            std::copy(other.begin(), other.end(), m_buffer);
        }
        return *this;
    }

    bool operator==(const Vector<T>& other) const {
        return std::equal(begin(), end(), other.begin(), other.end());
    }

    bool operator!=(const Vector<T>& other) const {
        return !operator==(other);
    }

    bool operator<(const Vector<T>& other) const {
        return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
    }

    bool operator>(const Vector<T>& other) const {
        return (!operator<(other));
    }

    bool operator<=(const Vector<T>& other) const {
        return (operator==(other) || operator<(other));
    }

    bool operator>=(const Vector<T>& other) const {
        return !operator<=(other);
    }

    iterator begin() const {
        return m_buffer;
    }

    iterator end() const {
        return m_buffer + m_size;
    }

    // capacity
    size_t size() const {
        return m_size;
    }

    size_t capacity() const {
        return m_capacity;
    }

    bool isEmpty() const {
        return m_size == 0;
    }

    void resize(size_t size, const T& value = T()) {
        reserve(size);
        for (size_t i = m_size; i < size; i++) {
            m_buffer[i] = value;
        }
        m_size = size;
    }

    void reserve(size_t size) {
        if (m_capacity < size) {
            getCapacity(size, m_capacity);
            T* m_buff = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++) {
                m_buff[i] = std::move(m_buffer[i]);
            }
            delete[] m_buffer;
            m_buffer = m_buff;
        }
    }

    // element access
    T& operator[](size_t index) const {
        return *(m_buffer + index);
    }

    T& at(size_t index) const {
        if (index >= m_size)
            throw "index > size";
        return m_buffer[index];
    }

    T* data() const {
        return m_buffer;
    }

    // modifiers
    void push_back(const T& value) {
        reserve(m_size + 1);
        m_buffer[m_size] = value;
        m_size++;
    }

    void pop_back() {
        if (m_size > 0)
            m_size--;
    }

    iterator insert(iterator pos, const T& value) {
        reserve(m_size + 1);
        for (iterator it = end(); it != pos; it--) {
            *it = *(it - 1);
        }
        *(pos) = value;
        m_size++;
        return pos;
    }

    iterator erase(iterator pos) {
        for (iterator next = pos + 1; next != end(); ++next) {
            *(next - 1) = *(next);
        }
        m_size--;
        return pos;
    }

    iterator erase(iterator first, iterator last) {
        size_t size = std::distance(first, last);
        m_size -= size;
        auto& it = first;
        for (it = first; it != last; it++) {
            *(it) = *(it + size);
        }
        if (m_size > 0)
            return last + 1;
        else
            return nullptr;
    }

    void clear() {
        m_size = 0;
    }

private:
    size_t m_size{0};
    size_t m_capacity{0};
    T* m_buffer{nullptr};
};

}  // namespace CBL

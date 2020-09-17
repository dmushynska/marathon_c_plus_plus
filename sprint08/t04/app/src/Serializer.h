#include <fstream>
#include <iostream>
#include <string>

template <typename T>
inline void determineReference(T&& obj) {
    std::cout << "deserialized ";
    if (typeid(char).name() == typeid(obj).name())
        std::cout << "char: ";
    else if (typeid(int).name() == typeid(obj).name()) {
        std::cout << "int: ";
    } else if (typeid(float).name() == typeid(obj).name()) {
        std::cout << "float: ";
    }
}

class Serializer {
public:
    template <class T>
    void serialize(const T* object, const std::string& fileName) {
        std::ofstream out(fileName, std::ios::binary);
        if (out) {
            out.write((char*)object, sizeof(T));
            out.close();
        } else {
            throw std::invalid_argument("error");
        }
    }

    template <class T>
    T deserialize(const std::string& fileName) {
        T object;
        std::ifstream in(fileName, std::ios::binary);
        if (in) {
            in.read((char*)&object, sizeof(T));
            in.close();
        } else {
            throw std::invalid_argument("error");
        }
        return object;
    }
};

class SomeClass {
public:
    SomeClass() = default;
    SomeClass(int intVal, char charVal, float floatVal) : m_intArg(intVal), m_charArg(charVal), m_floatArg(floatVal) {}
    void output() const {
        std::cout << "SomeClass: " << m_intArg << " " << m_charArg << " " << m_floatArg;
    }

private:
    int m_intArg;
    char m_charArg;
    float m_floatArg;
};
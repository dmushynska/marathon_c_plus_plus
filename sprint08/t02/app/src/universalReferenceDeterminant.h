#include <typeinfo>
namespace UniversalReferenceDeterminant {
template <typename T>
void determineReference(T&& obj) {
    if (typeid(char).name() == typeid(obj).name())
        if (std::is_reference<T>::value == true) {
            std::cout << "char is l-value reference\n";
        } else {
            std::cout << "char is r-value reference\n";
        }
    else if (typeid(int).name() == typeid(obj).name()) {
        if (std::is_reference<T>::value == true) {
            std::cout << "int is l-value reference\n";
        } else {
            std::cout << "int is r-value reference\n";
        }
    }
}
}
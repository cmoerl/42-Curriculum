

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    this->size_ = 0;
    this->arr_ = NULL;
}

template <typename T>
Array<T>::Array(unsigned int size) {
    this->size_ = size;
    this->arr_ = new T[this->size_];
    for (unsigned int i = 0; i < this->size_; i++) {
        this->arr_[i] = T();
    }
}

template <typename T>
Array<T>::Array(const Array<T> &other) {
    this->size_ = other.size_;
    this->arr_ = new T[this->size_];
    for (unsigned int i = 0; i < this->size_; i++)
        this->arr_[i] = other.arr_[i];
}

template <typename T>
Array<T> &Array<T>::operator = (const Array<T> &other) {
    if (this != &other) {
        delete [] this->arr_;
        this->size_ = other.size_;
        this->arr_ = new T[this->size_];
        for (unsigned int i = 0; i < this->size_; i++) {
            this->arr_[i] = other.arr_[i];
    }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    delete [] this->arr_;
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return (this->size_);
}

template <typename T>
T &Array<T>::operator [] (unsigned int index) {
    if (index >= this->size_)
        throw std::out_of_range("Index out of range");
    return (this->arr_[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= this->size_) {
        throw std::out_of_range("Index out of range");
    }
    return this->arr_[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array) {
    for (unsigned int i = 0; i < array.size(); ++i) {
        out << array[i] << " ";
    }
    return out;
}

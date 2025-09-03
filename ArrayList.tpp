#include "ArrayList.hpp"

template <typename T>
ArrayList<T>::ArrayList(int i) {
     if (i <= 0) {
        throw string("Array size must be greater than 0");
    }
    maxSize = i;
    buffer = new T[maxSize];
    
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) {
        throw string("append: error, ArrayList is full");
    }
    buffer[this->length++] = elem;
}

template <typename T>
void ArrayList<T>::clear() { 
    if (buffer != nullptr) {
    delete[] buffer;
    buffer = nullptr;
}

// Then, reset the list's size and capacity
this->length = 0;
this->maxSize = 0;
}


template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    return buffer[position];
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("insert: error, position out of bounds");
    }
    if (isFull()) {
        throw string("insert: error, ArrayList is full");
    }
    for (int i = this->length; i > position; i--) {
        buffer[i] = buffer[i - 1];
    }
    buffer[position] = elem;
    this->length++;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }
    for (int i = position; i < this->length - 1; i++) {
        buffer[i] = buffer[i + 1];
    }
    this->length--;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    // TODO
    this->length;
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }
    buffer[position] = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }

    return outStream;
}

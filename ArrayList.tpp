template <typename T>
ArrayList<T>::ArrayList(int i) {
     if (i <= 0) {
        throw string("Array size must be greater than 0");
    }
    maxSize = i;
    buffer = new T[maxSize];
    length = 0;
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
        throw string("ArrayList is full");
    }
    buffer[length++] = elem;
}

template <typename T>
void ArrayList<T>::clear() { 
    if (buffer != nullptr) {
    delete[] buffer;
    buffer = nullptr;
}

// Then, reset the list's size and capacity
length = 0;
maxSize = 0;
}


template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    maxSize = copyObj.maxSize;
    length = copyObj.length;
    buffer = new T[maxSize];
    for (int i = 0; i < length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= length) {
        throw string("Invalid position");
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
    if (position < 0 || position > length) {
        throw string("Invalid position");
    }
    if (isFull()) {
        throw string("ArrayList is full");
    }
    for (int i = length; i > position; i--) {
        buffer[i] = buffer[i - 1];
    }
    buffer[position] = elem;
    length++;
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
    if (position < 0 || position >= length) {
        throw string("Invalid position");
    }
    for (int i = position; i < length - 1; i++) {
        buffer[i] = buffer[i + 1];
    }
    length--;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    // TODO
    if (position < 0 || position >= length) {
        throw string("Invalid position");
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

#include <iostream>
#include <functional>
#include "ArrayList.h"

// Constructors
template <class T>
ArrayList<T>::ArrayList() {
    this->capacity = 1;
    this->length = 0;
    this->container = new T[capacity];
}

template <class T>
ArrayList<T>::ArrayList(int length) {
    this->capacity = length;
    this->length = 0;
    this->container = new T[length];
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arraylist) {
    DeepCopy(arraylist);
}


// Destructor
template <class T>
ArrayList<T>::~ArrayList() {
    delete[] this->container;
}


// Operators
template <class T>
const T& ArrayList<T>::operator[](int index) const {
    return this->container[index];
}

template <class T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arraylist) {
    if (this == &arraylist) {
        return *this; // Return current object
    }
    delete[] this->container;
    DeepCopy(arraylist);
    return *this;
}

// Public functions
template <class T>
bool ArrayList<T>::IsEmpty() const {
    return (this->length == 0);
}

template <class T>
int ArrayList<T>::Size() const {
    return this->length;
}

template <class T>
void ArrayList<T>::Print() const {
    std::cout << *this << std::endl;
}

template <class T>
ArrayList<T>& ArrayList<T>::Add(const T& item) {
    if(this->length == this->capacity){
        this->Resize();
    }
    this->container[this->length++] = item;
    return *this;
}

template <class T>
ArrayList<T>& ArrayList<T>::Add(int index, const T& item) {
    CheckIndex(index);
    if(this->length == this->capacity){ // Check if we have to grow the storage
        this->Resize();
    }
    for (int i = this->length - 1; i > index; --i) {
        this->container[i] = this->container[i - 1]; // Shift elements to the right to fill the gap
    }

    this->container[index] = item;
    this->length++;
    return *this;
}

template <class T>
ArrayList<T>& ArrayList<T>::Remove(int index) {
    //TODO probably should also add reduce policy so that containers space doesnt take too much memory
    CheckIndex(index);
    for (int i = index; i < length - 1; ++i) {
        this->container[i] = this->container[i + 1];  // Shift elements to the left to fill the gap
    }
    length--;
    return *this;
}

template <class T>
ArrayList<T>& ArrayList<T>::Clear() {
    delete[] this->container;
    this->container = nullptr; //To prevent dangled pointer
    this->capacity = 0;
    this->length = 0;
    return *this;
}

template <class T>
int ArrayList<T>::Search(const T& element, std::function<int(const Container<T>&, const T&)> searchPolicy) const {
    return searchPolicy(*this, element); // Return -1 if the element is not found
}


template <class T>
Container<T>& ArrayList<T>::Sort(std::function<Container<T>&(Container<T>&)> sortPolicy) {
    return sortPolicy(*this);  // Return sorted container
}

template <class T>
T ArrayList<T>::RetrieveAt(int index) const {
    CheckIndex(index);
    return this->container[index];
}

template <class T>
ArrayList<T>& ArrayList<T>::ReplaceAt(int index, const T& element) {
    CheckIndex(index);
    this->container[index] = element;
    return *this;
}

// Private functions
template <class T>
void ArrayList<T>::Resize() {
    this->capacity = (this->capacity == 0) ? 1 : (this->capacity * 2);
    T *tempContainer = new T[this->capacity];
    for(int i = 0; i < this->length; i++){
        tempContainer[i] = this->container[i];
    }
    delete[] this->container;
    this->container = tempContainer;
}

template <class T>
void ArrayList<T>::CheckIndex(int index) const {
    if (index < 0 || index >= this->length) {
        throw std::out_of_range("Index out of bounds");
    }
}

template <class T>
ArrayList<T>& ArrayList<T>::DeepCopy(const ArrayList<T>& arraylist){
    this->container = new T[arraylist.capacity];
    for (int i = 0; i < arraylist.length; ++i) {
        this->container[i] = arraylist.container[i];
    }

    this->capacity = arraylist.capacity;
    this->length = arraylist.length;

    return *this;
}


// Explicit template instantiation
template class ArrayList<int>;
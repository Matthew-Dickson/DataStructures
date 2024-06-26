#include <iostream>
#include <functional>
#include "ArrayList.h"

// Constructors
template <typename T>
ArrayList<T>::ArrayList() {
    this->capacity = 1;
    this->length = 0;
    this->container = new T[this->capacity];
}

template <typename T>
ArrayList<T>::ArrayList(int length) {
    this->capacity = length;
    this->length = 0;
    this->container = new T[this->length];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& arraylist) {
    DeepCopy(arraylist);
}

template <typename T>
typename ArrayList<T>::iterator ArrayList<T>::Begin() {
    return ArrayListIterator(*this, 0);
}

template <typename T>
typename ArrayList<T>::iterator ArrayList<T>::End() {
    return ArrayListIterator(*this, this->length);
}

// Destructor
template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] this->container;
}


// Operators
template <typename T>
const T& ArrayList<T>::operator[](int index) const {
    return this->container[index];
}

template <typename T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arraylist) {
    if (this == &arraylist) {
        return *this; // Return current object
    }
    delete[] this->container;
    DeepCopy(arraylist);
    return *this;
}

// Public functions
template <typename T>
bool ArrayList<T>::IsEmpty() const {
    return (this->length == 0);
}

template <typename T>
int ArrayList<T>::Size() const {
    return this->length;
}

template <typename T>
void ArrayList<T>::Print() const {
    std::cout << *this << std::endl;
}

template <typename T>
ArrayList<T>& ArrayList<T>::Add(const T& item) {
    if(this->length == this->capacity){
        this->Resize();
    }
    this->container[this->length++] = item;
    return *this;
}

template <typename T>
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

template <typename T>
ArrayList<T>& ArrayList<T>::Remove(int index) {
    //TODO probably should also add reduce policy so that containers space doesnt take too much memory
    CheckIndex(index);
    for (int i = index; i < this->length - 1; ++i) {
        this->container[i] = this->container[i + 1];  // Shift elements to the left to fill the gap
    }
    this->length--;
    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::Clear() {
    delete[] this->container;
    this->container = nullptr; //To prevent dangled pointer
    this->capacity = 0;
    this->length = 0;
    return *this;
}

template <typename T>
int ArrayList<T>::Search(const T& element, std::function<int(const Container<T>&, const T&)> searchPolicy) const {
    return searchPolicy(*this, element); // Return -1 if the element is not found
}


template <typename T>
Container<T>& ArrayList<T>::Sort(std::function<Container<T>&(Container<T>&)> sortPolicy) {
    return sortPolicy(*this);  // Return sorted container
}

template <typename T>
T ArrayList<T>::RetrieveAt(int index) const {
    CheckIndex(index);
    return this->container[index];
}

template <typename T>
ArrayList<T>& ArrayList<T>::ReplaceAt(int index, const T& element) {
    CheckIndex(index);
    this->container[index] = element;
    return *this;
}

// Private functions
template <typename T>
void ArrayList<T>::Resize() {
    this->capacity = (this->capacity == 0) ? 1 : (this->capacity * 2);
    T *tempContainer = new T[this->capacity];
    for(int i = 0; i < this->length; i++){
        tempContainer[i] = this->container[i];
    }
    delete[] this->container;
    this->container = tempContainer;
}

template <typename T>
void ArrayList<T>::CheckIndex(int index) const {
    if (index < 0 || index >= this->length) {
        throw std::out_of_range("Index out of bounds");
    }
}

template <typename T>
ArrayList<T>& ArrayList<T>::DeepCopy(const ArrayList<T>& arraylist){
    this->container = new T[arraylist.capacity];
    for (int i = 0; i < arraylist.length; ++i) {
        this->container[i] = arraylist.container[i];
    }

    this->capacity = arraylist.capacity;
    this->length = arraylist.length;

    return *this;
}



template<typename T>
ArrayList<T>::ArrayListIterator::ArrayListIterator(const ArrayList<T>& list, int index) : container(list), index(index) {}

template<typename T>
T ArrayList<T>::ArrayListIterator::operator*() const {
    return container.RetrieveAt(index); 
}

template<typename T>
typename ArrayList<T>::ArrayListIterator& ArrayList<T>::ArrayListIterator::operator++() {
    ++index;
    return *this;
}

template<typename T>
bool ArrayList<T>::ArrayListIterator::operator==(const ArrayListIterator& other) const {
    return index == other.index;
}

template<typename T>
bool ArrayList<T>::ArrayListIterator::operator!=(const ArrayListIterator& other) const {
    return !(*this == other);
}


// Explicit template instantiation
template class ArrayList<int>;
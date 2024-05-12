#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED

#include <functional>

template<class T>
class Container {
public:
    virtual bool IsEmpty() const = 0; 
    virtual int Size() const = 0;
    virtual void Print() const = 0;
    virtual Container<T>& Add(const T& item) = 0;
    virtual Container<T>& Add(int index, const T& item) = 0;
    virtual Container<T>& Remove(int index) = 0;
    virtual Container<T>& Clear() = 0;
    virtual Container<T>& ReplaceAt(int index, const T& item) = 0;
    virtual T RetrieveAt(int index) const = 0;

    virtual Container<T>& Sort(std::function<Container<T>&(Container<T>&)> sortPolicy) = 0;
    virtual int Search(const T& element, std::function<int(const Container<T>&, const T&)> searchPolicy) const = 0;

protected:
        T *container;
        int capacity;
        int length;
};

#endif // CONTAINER_H_INCLUDED
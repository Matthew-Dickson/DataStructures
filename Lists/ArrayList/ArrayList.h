#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#include <functional>
#include <ostream>
#include "../Common/SortFunctions.h"
#include "../Common/SearchFunctions.h"
#include "../Common/Container.h"

template <class T>
class ArrayList : public Container<T> {
    public:
        //TODO Should properly add a iterator
        //TODO Pull out common features for containers
        ArrayList();
        ArrayList(int length);
        ArrayList(const ArrayList<T>& arraylist);
        ~ArrayList();

        class ArrayListIterator;
        using iterator = ArrayListIterator;
        iterator Begin(); 
        iterator End(); 

        const T& operator[](int index) const;
        const ArrayList<T>& operator=(const ArrayList<T>&);
        friend std::ostream& operator<<(std::ostream& os, const ArrayList<T>& arrayList) {
            for (int i = 0; i < arrayList.length; ++i) {
                os << "Item " << i << ": " << arrayList.RetrieveAt(i) << std::endl;
            }
            return os;
        }

        bool IsEmpty() const override;
        int Size() const override;
        void Print() const override;
        ArrayList<T>& Add(const T& item) override;
        ArrayList<T>& Add(int index, const T& item) override;
        ArrayList<T>& Remove(int index) override;
        ArrayList<T>& Clear() override;
        ArrayList<T>& ReplaceAt(int index, const T& item) override;
        T RetrieveAt(int index) const override;

        Container<T>& Sort(std::function<Container<T>&(Container<T>&)> sortPolicy = SortFunctions<T, Container<T>>::BubbleSort) override;
        int Search(const T& element, std::function<int(const Container<T>&, const T&)> searchPolicy = SearchFunctions<T, Container<T>>::LinearSearch) const override;

    private:
        void Resize();
        void CheckIndex(int index) const;
        ArrayList<T>& DeepCopy(const ArrayList<T>&);

};


template<typename T>
class ArrayList<T>::ArrayListIterator {
public:
    // Constructor
    ArrayListIterator(const ArrayList<T>& list, int index);

    // Member functions
    T operator*() const;
    ArrayListIterator& operator++();
    bool operator==(const ArrayListIterator& other) const;
    bool operator!=(const ArrayListIterator& other) const;

private:
    const ArrayList<T>& container;
    int index;
};

#endif // ARRAYLIST_H_INCLUDED
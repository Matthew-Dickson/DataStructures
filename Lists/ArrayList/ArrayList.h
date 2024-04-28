#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

#include <functional>
#include <ostream>
#include "SortFunctions.h"
#include "SearchFunctions.h"

template <class T>
class ArrayList {
    public:
        //TODO Should properly add a iterator
        //TODO Pull out common features for containers
        ArrayList();
        ArrayList(int length);
        ArrayList(const ArrayList<T>& arraylist);
        ~ArrayList();

        const T& operator[](int index) const;
        const ArrayList<T>& operator=(const ArrayList<T>&);
        friend std::ostream& operator<<(std::ostream& os, const ArrayList<T>& arrayList) {
            for (int i = 0; i < arrayList.length; ++i) {
                os << "Item " << i << ": " << arrayList.container[i] << std::endl;
            }
            return os;
        }

        bool IsEmpty() const;
        int Size() const;
        void Print() const;
        ArrayList<T>& Add(const T& item);
        ArrayList<T>& Add(int index, const T& item);
        ArrayList<T>& Remove(int index);
        ArrayList<T>& Clear();
        ArrayList<T>& ReplaceAt(int index, const T& item);
        T RetrieveAt(int index) const;

        ArrayList<T>& Sort(std::function<ArrayList<T>&(ArrayList<T>&)> sortPolicy = SortFunctions<T, ArrayList<T>>::BubbleSort);
        int Search(const T& element, std::function<int(const ArrayList<T>&, const T&)> searchPolicy = SearchFunctions<T, ArrayList<T>>::LinearSearch) const;

    protected:
        T *container;
        int capacity;
        int length;

    private:
        void Resize();
        void CheckIndex(int index) const;
        ArrayList<T>& DeepCopy(const ArrayList<T>&);

};

#endif // ARRAYLIST_H_INCLUDED
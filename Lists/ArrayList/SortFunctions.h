#ifndef SORTFUNCTIONS_H_INCLUDED
#define SORTFUNCTIONS_H_INCLUDED

template<typename T, typename N>
class SortFunctions {
    public:
        static N& BubbleSort(N& container) {
            int length = container.Size();
            for (int i = 0; i < length - 1; ++i) {  // Do a pass for every item
                for (int j = 0; j < length - i - 1; ++j) {
                    if (container.RetrieveAt(j) > container.RetrieveAt(j + 1)) {     // Swap elements if they are in the wrong order
                        T temp = container.RetrieveAt(j);
                        container.ReplaceAt(j,container.RetrieveAt(j + 1));
                        container.ReplaceAt(j + 1, temp);
                    }
                }
            }
            return container;
        }
};

#endif // SORTFUNCTIONS_H_INCLUDED

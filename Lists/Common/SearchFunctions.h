#ifndef SEARCHFUNCTIONS_H_INCLUDED
#define SEARCHFUNCTIONS_H_INCLUDED

template<typename T, typename N>
class SearchFunctions {
    public:
        static int LinearSearch(const N& container, const T& element) {
            for (int i = 0; i < container.Size(); ++i) {
                if (container.RetrieveAt(i) == element) {
                    return i;
                }
            }
            return -1;
        }

        static int BinarySearch(const N& container, const T& element) {
            int left = 0;
            int right = container.Size();

            while (left <= right) {
                int middlePoint = left + (right - left) / 2;

                // Check if the element is present at the middle
                if (container.RetrieveAt(middlePoint) == element)
                    return middlePoint;

                // If the element is greater ignore left half
                if (container.RetrieveAt(middlePoint) < element)
                    left = middlePoint + 1;
                // If the element is smaller ignore right half
                else
                    right = middlePoint - 1;
            }
            return -1;
        }
};

#endif // SEARCHFUNCTIONS_H_INCLUDED

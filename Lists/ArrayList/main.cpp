#include <iostream>
#include "SearchFunctions.h"
#include "SortFunctions.h"
#include "ArrayList.h"

using namespace std;

int main()
{
    ArrayList<int> orderedList; //look at variadic templates for easier initialization
    ArrayList<int> unorderedList;

    orderedList.Add(1);
    orderedList.Add(2);
    orderedList.Add(3);
    orderedList.Add(4);
    orderedList.Add(5);
    orderedList.Add(6);
    orderedList.Add(8);

    unorderedList.Add(2321);
    unorderedList.Add(222);
    unorderedList.Add(331);
    unorderedList.Add(3231231);
    unorderedList.Add(333);
    unorderedList.Add(22);
    unorderedList.Add(23);

    int elementToFind = 5;
    int index = orderedList.Search(elementToFind,SearchFunctions<int, ArrayList<int>>::LinearSearch);
    if (index != -1) {
        std::cout << "Element " << elementToFind << " found at index " << index << std::endl;
    } else {
        std::cout << "Element " << elementToFind << " not found" << std::endl;
    }

    orderedList.Print();

    unorderedList.Sort();
    std::cout << "Printing sorted elements:" << std::endl;
    unorderedList.Print();

    return 0;
}

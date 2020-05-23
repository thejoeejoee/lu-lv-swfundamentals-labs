#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Remover.h"
#include "List.h"

/**
 * @author Josef Kolar, jk19126
 * @brief G10, program working wih linked list to process numbers.
 * @date 23.05.2020
 *
 *
Create two C++ programs to process sequence of values in two different ways:
1) with simple one way linked list using dynamical data structures,
2) using STL::list container.
In both realizations you should create specific function and use it. Print and input all values in
 list before and after processing.
In first realization with linked list you should also create list methods like add element and other.
 After usage of list you should correctly release memory (delete all list elements).

G10. Create list from values entered from keyboard. Enter one more value n.
Create function to delete next element after n if it exists and has different value from n.
If n appears in list several times then delete all elements followed after each n.
Example: List: 1 5 2 3 6 2 2 5 1 2. n=2 List after process: 1 5 2 6 2 2 1 2

https://estudijas.lu.lv/mod/page/view.php?id=349989
*/



int main() {
    List<int> values;
    int remover_value;

    // parse first line with values
    std::string input_line;
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);
    int v;
    while (input_stream >> v) {
        values.append(v);
    }

    // parse 'remover_value'
    std::getline(std::cin, input_line);
    std::stringstream remover_line(input_line);
    if (!(remover_line >> remover_value)) {
        std::cerr << "Unable to parse the 'n' on second line." << std::endl;
        return EXIT_FAILURE;
    }

    auto item = values.head();
    while (item) {
        std::cout << values.value_of(item) << " ";
        item = values.next(item);
    }
    std::cout << std::endl;

    // new instance of remover with 'n' value and remove all item fulfilling the condition
    Remover<int> remover(remover_value);
    values.remove_if(remover);

    item = values.head();
    while (item) {
        std::cout << values.value_of(item) << " ";
        item = values.next(item);
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}



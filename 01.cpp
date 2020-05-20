/**
 * @author Josef Kolar, jk19126
 * @brief F10, program searching for symmetric words in text file.
 * @date 20.05.2020
 *
Create program in C++ to process text files. Read text file lines one by one.
It is not allowed to duplicate all contents of file in computer memory. See also other published requirements.

F10. Create program to read given text file and print into another text file all words which are simmetric.
Symmetric words are spelled from right to left and from left to right equally.
Word in input file is string separated with space or separators like  dot . or comma , or brackets ( ) or
exclamation mark ! or question mark ? or end of line. releveler repaper succus alula

https://estudijas.lu.lv/mod/page/view.php?id=349989
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]) {
    if (argc != 3) return EXIT_FAILURE;
    ifstream in;
    in.open(argv[1]);
    ofstream out;
    out.open(argv[2]);
    if (!(in.is_open() && out.is_open())) return EXIT_FAILURE;

    const vector<char> DELIMITERS({'.', ',', '(', ')', '!', '?'});

    char c;
    string word;

    while(in.get(c)) {
        if (isspace(c) || std::count(DELIMITERS.begin(), DELIMITERS.end(), c)) {
            if (word.empty()) // just another delimiter
                continue;

            // end of word
            // first half same as second => palindrome
            if (equal(word.begin(), word.begin() + word.size()/2, word.rbegin())) {
                out << word << '\n';
            }
            word.clear();
        } else {
            // end of delimiter
            word.push_back(c);
        }
    }
    // check for last word before EOF
    if (equal(word.begin(), word.begin() + word.size()/2, word.rbegin())) {
        out << word << '\n';
    }

    in.close();
    out.close();
    return EXIT_SUCCESS;
}
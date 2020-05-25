/**
 * @author Josef Kolar, jk19126
 * @brief H10, program counting words by first two chars.
 * @date 25.05.2020
 *
 *
Create program in C++ using STD map.*
H3. Read given text file and count at least 2-letter words grouped by first 2 letters of word.
Count how many words start with "aa", "ab", "ac", ... in text in given text file.
Word is string separated with dot . or comma , or brackets ( ) or exclamation mark ! or
question mark ? or space or end of line. Program must create table realized as STD map of word
count statistics and print the table in output text file.
Create output text file with pairs of letter pairs and numbers of word count.

https://estudijas.lu.lv/mod/page/view.php?id=349989
*/

#include <vector>
#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
    const std::vector<char> DELIMITERS({'.', ',', '(', ')', '!', '?'});
    short c;
    std::string word;

    // typedef std::tuple<char, char> index_tuple;
    std::unordered_map<std::string, int> stats;

    do {
        c = std::cin.get();

        if (c == EOF || isspace(c) || std::count(DELIMITERS.begin(), DELIMITERS.end(), c)) {
            if (word.empty()) // just another delimiter
                continue;

            if (word.size() >= 2)
                // end of word, add to stats
                stats[word.substr(0, 2)]++;

            word.clear();
        } else {
            // end of delimiter
            word.push_back(tolower(c));
        }
    } while (c != EOF);

    for (auto & pair : stats) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    return EXIT_SUCCESS;
}
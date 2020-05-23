/**
 * @author Josef Kolar, jk19126
 * @date 23.05.2020
 */

#include <algorithm>

/**
 * Class representing logic for this task -- remove item in list just after specified value.
 * @tparam T base type to compare
 */
template<typename T>
class Remover : public std::function<bool(const T &)> {
private:
    T remover_value;
    T prev;
    bool has_prev = false;
public:
    explicit Remover(T remover_value) :
        remover_value(remover_value),
        std::function<bool(const T &)>([this](const T & value) {
            if (!has_prev) {
                // first value_of, just store for following usage
                prev = value;
                has_prev = true;
                return false;
            }
            // remove <=> previous is remover value and current is not equal to remover value_of
            bool remove = prev == this->remover_value && value != prev;
            prev = value;
            return remove;
        }) {};
};

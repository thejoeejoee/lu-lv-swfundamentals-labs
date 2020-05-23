/**
 * @author Josef Kolar, jk19126
 * @date 23.05.2020
 */

#ifndef SWFUNDAMENTALS_02_LIST_H
#define SWFUNDAMENTALS_02_LIST_H

#include <functional>

template<typename T>
class List;

/**
 * One item of List<T> with single value of type T.
 * @tparam T
 */
template<typename T>
struct ListItem {
protected:
    T value;
    ListItem<T>* next = nullptr;
    explicit ListItem<T>(T value) : value(value) {}
public:
    friend List<T>;
};

/**
 * One way linked list with values of type T.
 * @tparam T
 */
template<typename T>
class List {
public:
    typedef ListItem<T>* item_ptr;
    /**
     * Appends new value at the end of list.
     * @param value new value
     */
    void append(T value) {
        auto new_item = new ListItem<T>(value);
        if (!m_head) {
            m_head = new_item;
            m_tail = new_item;
        } else {
            m_tail->next = new_item;
            m_tail = new_item;
        }
    }

    /**
     * Removes items form list for whose that predicate returns true.
     * @param predicate predicate for removing
     */
    void remove_if(std::function<bool(const T &)> predicate) {
        item_ptr item = m_head;
        item_ptr prev = nullptr;
        while (item) {
            if (!predicate(item->value)) {
                // just go to next
                prev = item;
                item = item->next;
                continue;
            }

            if (item == m_head) { // removing first
                m_head = item->next;
                if (m_tail == item) // removing the only one
                    m_tail = nullptr;
                delete item;
                prev = nullptr;
                item = m_head;

            } else if (item == m_tail) { // removing last
                prev->next = nullptr;
                m_tail = prev;
                delete item;
                item = prev->next;

            } else { // removing intermediate
                prev->next = item->next;
                delete item;
                // prev stays same
                item = prev->next;
            }
        }
    }
    /**
     * Get value from ListItem
     * @param item item to get value
     * @return value of item
     */
    T value_of(item_ptr item) {
        return item->value;
    }
    /**
     * Get next item in list, or nullptr if last.
     * @param item base item
     * @return next item in list
     */
    item_ptr next(item_ptr item) {
        return item->next;
    }
    /**
     * Get start from list.
     * @return
     */
    item_ptr head() { return m_head; }

    virtual ~List() {
        item_ptr item = m_head;
        item_ptr next;
        while (item) {
            next = item->next;
            delete item;
            item = next;
        }
    }
protected:
    item_ptr m_head = nullptr;
    item_ptr m_tail = nullptr;
};

#endif //SWFUNDAMENTALS_02_LIST_H

//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 6, Project 5
//  2/10/2016
//  keybag class for abstract datatype assuming it can be comparable datatype
//  uses pair to store key and data
//  Iterator implemented
#include <utility>
#include <cstdlib>  // Provides size_t

template <typename K, typename V>
class keybag{
private:
    typedef std::pair<K,V> Item;
    Item *pairs;
    int used;
    int maxsize;
    class keybag_iterator : std::iterator<std::forward_iterator_tag, Item> {
        public://private:
            Item *items;
            int current_index;
        public:
            keybag_iterator(Item* items, int initial = 0) {
                this->items = items;
                current_index = initial;
            }
            Item& operator*() const {
                return items[current_index];
            }
            keybag_iterator& operator++() {
                current_index++;
                return *this;
            }
            keybag_iterator operator++(int) {
                keybag_iterator original(items, current_index);
                current_index++;
                return original;
            }
            bool operator==(const keybag_iterator other) const{
                return current_index == other.current_index;
            }
            bool operator!=(const keybag_iterator other) const{
                return current_index != other.current_index;
            }
    };
public:
    static const int CAPACITY = 30;
    // CONSTRUCTOR
    keybag( );
    // MODIFICATION MEMBER FUNCTIONS
    void insert(const K& key, const V& entry);
    void removewithkey(const K& key);

    keybag_iterator begin();
    keybag_iterator end();

    // CONSTANT MEMBER FUNCTIONS
    bool is_item(const K& key);
    void dump();
    keybag operator*(const keybag& b);
};

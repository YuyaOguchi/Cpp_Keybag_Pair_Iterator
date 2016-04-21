//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 6, Project 5
//  2/10/2016
//  keybag class for abstract datatype assuming it can be comparable datatype
//  uses pair to store key and data
//  iterator implemented
#include <iostream>
#include "keybag_pair_iterator.h"
using namespace std;

template<typename K, typename V>
keybag<K,V>::keybag() {
    pairs = new std::pair<K,V>[CAPACITY];
    maxsize = CAPACITY;
    used = 0;
}

template<typename K, typename V>
typename keybag<K,V>::keybag_iterator keybag<K,V>::begin(){
    return keybag_iterator(pairs, 0);
}
template<typename K, typename V>
typename keybag<K,V>::keybag_iterator keybag<K,V>::end(){
    return keybag_iterator(pairs, used);
}

template<typename K, typename V>
void keybag<K,V>::insert(const K& key, const V& value){
    bool add = true;
    for (keybag_iterator it = begin(); it != end(); it++){
        if ((*it).first == key){
            add = false;
        }
    }
    if (add == true){
        Item& item = *end();
        item.first = key;
        item.second = value;
        used++;
    }
}

template<typename K, typename V>
void keybag<K,V>::removewithkey(const K& key){
    for (keybag_iterator it = begin(); it != end(); it++){
        if (key == (*it).first){
            /*for (int j = i; j < used; j++){
                pair[i].first = pair[i+1].first;
                pair[i].second = pair[i+1].second;
            }*/
            *it = *end();
            /*pair[used].first = 0;
            pair[used].second = 0;*/
            used--;
            break;
        }
    }
}

template<typename K, typename V>
bool keybag<K,V>::is_item(const K& key){
    for (keybag_iterator it = begin(); it != end(); it++){
        if (key == (*it).first){
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
void keybag<K,V>::dump(){
    for(keybag_iterator it = begin(); it != end(); it++){
        cout << "key: "<< (*it).first << " Data: " << (*it).second << endl;
    }
}


int main()
{
   keybag<int, int> s;
   s.insert(10, 1);
   s.insert(20, 3);
   s.insert(30, 5);
   cout << "s" << endl;
   s.dump();

   keybag<int, int> s1;
   s1.insert(40, 3);
   s1.insert(50,1);
   s1.insert(40,1);
   s1.removewithkey(50);
   cout << "s1" << endl;
   s1.dump();
}

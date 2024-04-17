#include <iostream>
#include <math.h>
#include <functional>
#include <list>
using std::cout;

template <typename T,typename U> class HashTable {
Private:
    class node
    {
    private:
        T* key;
        U* data;
    public:
        node(): key=nullptr, data=nullptr;{}
        node(T& newKey, U& newData)
        {
            key= newKey;
            data= newData;
        }
        U& getData const()
        {
            return data;
        }
        T& getKey const()
        {
            return key;
        }

    };
    int KeyNumber;
    int dataArraySize;
    list<vector> range[];
    
    int hashFunction()
    {
        int hNumber =  keyNumber mod dataArraySize;
        return hNumber;
    }
public:
    HashTable() : keyNumber=0, dataArraySize=10, DataArray[10];{}
    insert(const T& key, const U& data)
    {
        int hashNumber;
        keyNumber++;
        hashNumber = hashFuntion();
        //crear lista con datos
        list<node> bucket;
        //crear un nodo por medio del constructor
        node* newInput= new node(key,data);
        list.pushBack(node);

        vector<T> key;

 
     }
};
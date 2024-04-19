#include <iostream>
#include <math.h>
#include <functional>
#include <list>
template <typename T,typename U> class HashTable {
    private:
        class Node
            {
            private:
                T* key;
                U* data;
            public:
                Node(): key(nullptr), data(nullptr) {}
                Node(T& newKey, U& newData)
                {
                    key= newKey;
                    data= newData;
                }
                U& getData() const
                {
                    return data;
                }
                T& getKey() const
                {
                    return key;
                }

            };
    unsigned int const loadFactor=0.75;
    unsigned int dataArraySize;
    std::list<Node>* DataArray;
    
    
    
    int hashFunction(const T& key)
    {
        int hNumber;
        //hay que implementar una hash function que regrese un 
        //entero dependiendo siempre de la llave que se entregue
        return hNumber;
    }
public:
    HashTable()
    {
        dataArraySize=2;
        DataArray= new std::list<Node>[dataArraySize];
    }
    void insert(const T& key, const U& data)
    {
        int hashNumber;
        hashNumber = hashFunction(key);

        //crear lista con datos
        std::list<Node> bucket;
        Node newInput(key,data);    
        bucket.pushBack(newInput);

 
    }
};

int main()
{
    HashTable<int, int> table;
    return 0;
}
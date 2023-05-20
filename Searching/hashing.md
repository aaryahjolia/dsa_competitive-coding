#include <iostream>
using namespace std;

const int HASH_TABLE_SIZE = 100; // Size of the hash table array

class HashTable {
private:
    int hashFunction(int key) {
        return key % HASH_TABLE_SIZE; // Simple modulus hash function
    }

    int table[HASH_TABLE_SIZE]; // Hash table array

public:
    HashTable() {
        // Initialize all elements of the hash table to -1 (indicating empty)
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    void insert(int key) {
        int hashValue = hashFunction(key);
        // Linear probing to handle collisions
        while (table[hashValue] != -1) {
            hashValue = (hashValue + 1) % HASH_TABLE_SIZE;
        }
        table[hashValue] = key;
    }

    bool search(int key) {
        int hashValue = hashFunction(key);
        // Linear probing to handle collisions
        while (table[hashValue] != -1) {
            if (table[hashValue] == key) {
                cout << "Found " << key << " at index " << hashValue << endl;
                return true;
            }
            hashValue = (hashValue + 1) % HASH_TABLE_SIZE;
        }
        cout << "Key " << key << " not found in the hash table" << endl;
        return false;
    }
};

int main() {
    HashTable hashTable;
    int i=0;
    int n;
    int val;
    int val2;
    cout<<"Enter the number of values to be entered"<<endl;
    cin>>n;
    if(n>HASH_TABLE_SIZE) //To check if the hash table has sufficient space
    {
        cout<<"Insufficient space"<<endl;
        return 0;
    }
    for(i=0;i<n;i++) //Inserting elements in hash table
    {
        cout<<"Enter value"<<endl;
        cin>>val;
        hashTable.insert(val);
    }
    cout<<"Enter the value to be searched"<<endl; //Searching
    cin>>val2;
    hashTable.search(val2);
    return 0;
}

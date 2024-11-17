#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
private:
    vector<int> table;
    int size;

    int hashFunction(int key)
    {
        return key % size;
    }

public:
    HashTable(int s) : size(s)
    {
        table.resize(size, -1); // Initialize the table with -1 indicating empty slots
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        if (table[index] == -1)
        {
            table[index] = key;
        }
        else
        {
            cout << "Collision occurred for key: " << key << endl;
            int i = 1;
            while (table[(index + i) % size] != -1)
            {
                i++;
            }
            table[(index + i) % size] = key;
        }
    }

    int search(int key)
    {
        int index = hashFunction(key);
        if (table[index] == key)
        {
            return index;
        }
        else
        {
            int i = 1;
            while (table[(index + i) % size] != -1)
            {
                if (table[(index + i) % size] == key)
                {
                    return (index + i) % size;
                }
                i++;
            }
        }
        return -1;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i] != -1)
                cout << "Index " << i << ": " << table[i] << endl;
            else
                cout << "Index " << i << ": Empty" << endl;
        }
    }
};

int main()
{
    int size, choice, key;

    cout << "Enter the size of the hash table: ";
    cin >> size;

    HashTable ht(size);

    while (true)
    {
        cout << "\nChoose operation:\n";
        cout << "1 for Insert\n2 for Search\n3 for Display\n4 for Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            int pos;
            pos = ht.search(key);
            if (pos != -1)
            {
                cout << "Key found at index: " << pos << endl;
            }
            else
            {
                cout << "Key not found." << endl;
            }
            break;
        case 3:
            ht.display();
            break;
        case 4:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
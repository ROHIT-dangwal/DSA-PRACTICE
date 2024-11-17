#include <iostream>
#include <algorithm>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, key, choice;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    cout << "Choose search method: 1 for Linear Search, 2 for Binary Search: ";
    cin >> choice;

    if (choice == 1)
    {
        int position = linearSearch(arr, n, key);
        if (position != -1)
        {
            cout << "Element found at position: " << position << endl;
        }
        else
        {
            cout << "Element not found." << endl;
        }
    }
    else if (choice == 2)
    {
        sort(arr, arr + n); // Sorting is necessary for binary search
        int position = binarySearch(arr, n, key);
        if (position != -1)
        {
            cout << "Element found at position: " << position << endl;
        }
        else
        {
            cout << "Element not found." << endl;
        }
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
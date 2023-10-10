// C++ program for implementation of Heap Sort

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define MAX 10000 // Max size of Heap


struct Heap {
    int arr[MAX];   // Array that stores heap elements
    int n = 0;      // n is tge size of the heap 


    // Function to maintain heap after insertion
    void heapify(int i) {
        int parent = (i - 1) / 2;
        if (parent >= 0 && arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapify(parent);  // Recursively heapify the parent node
        }
    }

    // Function to insert element
    void insertNode(int Key) {
        n = n + 1;
        arr[n - 1] = Key;
        heapify(n - 1);
    }


    // Function to delete the maximum element
    void deleteRoot() {
        if (n == 0) return; // Heap is empty so return
        int lastElement = arr[n - 1];
        arr[0] = lastElement;   // Replace root with last element
        n = n - 1;  // Decrease Heap Size

        // This heapify is different from the insertion heapify
        int i = 0;
        while (true) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && arr[l] > arr[largest])
                largest = l;

            if (r < n && arr[r] > arr[largest])
                largest = r;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

    // Function to get the maximum element from heap
    int getMax() {
        if (n == 0) return -1;  // heap is empty
        return arr[0];  // Maximum element found
    }
};

int main() {
    int number_of_queries;
    cin >> number_of_queries;   // Get # of User Commands
    cin.ignore();

    Heap heap;  // Creates a Max Heap

    for (int i = 0; i < number_of_queries; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        string command;
        iss >> command;

        // Insertion Command
        if (command == "INSERT") {
            int value;
            iss >> value;
            heap.insertNode(value);

        // Delete Command
        } else if (command == "DELETE") {
            heap.deleteRoot();


            // Print Command 
        } else if (command == "PRINT") {
            int maxVal = heap.getMax();
            if (maxVal == -1) {     // Print Empty line if heap is empty
                cout << endl;
            } else {
                cout << maxVal << endl; // Otherwise print max element
            }
        }
    }

    return 0;
}

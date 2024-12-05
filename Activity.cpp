#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain max-heap property
void maxheapify(vector<int> &hT, int i, int size) {
    int largest = i;
    int l = 2 * i + 1; // Left child
    int r = 2 * i + 2; // Right child

    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;

    if (largest != i) {
        swap(&hT[i], &hT[largest]);
        maxheapify(hT, largest, size);
    }
}

// Maintain min-heap property
void minheapify(vector<int> &hT, int i, int size) {
    int smallest = i;
    int l = 2 * i + 1; // Left child
    int r = 2 * i + 2; // Right child

    if (l < size && hT[l] < hT[smallest])
        smallest = l;
    if (r < size && hT[r] < hT[smallest])
        smallest = r;


    if (smallest != i) {
        swap(&hT[i], &hT[smallest]);
        minheapify(hT, smallest, size);
    }
}

// Build a min-heap
void buildMinHeap(vector<int> &hT) {
    int lastParent = (hT.size() / 2) - 1;
    for (int i = lastParent; i >= 0; i--) {
        minheapify(hT, i, hT.size());
    }
}

// Build a max-heap
void buildMaxHeap(vector<int> &hT) {
    int lastParent = (hT.size() / 2) - 1;
    for (int i = lastParent; i >= 0; i--) {
        maxheapify(hT, i, hT.size());
    }
}

// Insert into heap (works for both min and max heaps)
void insert(vector<int> &hT, int newNum, bool isMinHeap) {
    hT.push_back(newNum);
    int current = hT.size() - 1;

    // Bubble up based on the heap type
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (isMinHeap && hT[current] < hT[parent]) { // if its a minheap bubbles up with this operation
            swap(&hT[current], &hT[parent]);
            current = parent;
        } else if (!isMinHeap && hT[current] > hT[parent]) { // if its not a maxheap bubbles up with this operation
            swap(&hT[current], &hT[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

// Heapsort for ascending order (from Min-Heap)
void heapsortMin(vector<int> &hT) {
    vector<int> sortedArray;
    int size = hT.size();

    // Repeatedly extract the root (minimum element)
    for (int i = size - 1; i >= 0; i--) {
        sortedArray.push_back(hT[0]); // pushes the root out
        swap(&hT[0], &hT[i]); // swaps the root with the end node
        hT.pop_back(); // removes the last element of the vector
        minheapify(hT, 0, hT.size()); // minheapifys the vector
    }

    // Prints the sorted array
    cout << "Sorted Array (Ascending): ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << "\n";
}

// Heapsort for descending order (from Max-Heap)
void heapsortMax(vector<int> &hT) {
    vector<int> sortedArray;
    int size = hT.size();

    // Repeatedly extract the root (maximum element)
    for (int i = size - 1; i >= 0; i--) {
        sortedArray.push_back(hT[0]); // pushes the root out
        swap(&hT[0], &hT[i]); // swaps the root with the end node
        hT.pop_back(); // removes the last element of the vector
        maxheapify(hT, 0, hT.size()); // minheapifys the vector
    }

    // Prints the sorted array
    cout << "Sorted Array (Descending): ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << "\n";
}

void printArray(const vector<int> &hT) {
    for (int num : hT) // Prints out each number from the vector
        cout << num << " ";
    cout << "\n";
}

int main() {
    vector<int> heapTree;

    cout << "Original array: 10, 20, 5, 30, 15\n";

    // min-Heap
    heapTree = {10, 20, 5, 30, 15};
    buildMinHeap(heapTree);
    cout << "Min-Heap: ";
    printArray(heapTree);
    heapsortMin(heapTree);

    // max-Heap
    heapTree = {10, 20, 5, 30, 15};
    buildMaxHeap(heapTree);
    cout << "Max-Heap: ";
    printArray(heapTree);
    heapsortMax(heapTree);

    return 0;
}

/*
    * FIFO Page Replacement Algorithm Implementation in C++
    * Find hit and miss ratio
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter number of frames: ";
    int n;
    cin >> n;  // Number of frames

    queue<int> frames;  // To keep track of pages in frames (FIFO)
    unordered_set<int> lookup;  // To quickly check if a page is in frames

    cout << "Enter page reference string (end with -1): ";
    vector<int> pages;
    int page;

    // Input the page reference string
    while (cin >> page && page != -1) {
        pages.push_back(page);
    }

    int hits = 0, misses = 0;
    
    // Traverse through the page reference string
    for (auto p : pages) {
        // Check if the page is already in frames
        if (lookup.find(p) != lookup.end()) {
            hits++;  // If the page is found, it's a hit
            continue;  // No need to replace the page
        }

        // Page miss - need to replace a page in the frames
        misses++;

        // If there's space in the frames, just add the new page
        if (frames.size() < n) {
            frames.push(p);
            lookup.insert(p);  // Mark the page as present in frames
        } else {
            // If frames are full, remove the oldest page (FIFO)
            int old_page = frames.front();
            frames.pop();  // Remove the oldest page from the front
            lookup.erase(old_page);  // Remove it from the set as well

            // Insert the new page into frames
            frames.push(p);
            lookup.insert(p);  // Mark the new page as present in frames
        }
    }

    // Output the final content of frames
    cout << "Final frame contents: ";
    queue<int> temp = frames;  // Copy the frame contents for output
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Calculate hit and miss ratios
    double hit_ratio = (double)hits / (hits + misses);
    double miss_ratio = (double)misses / (hits + misses);

    // Output the hit and miss ratios
    cout << "Hit ratio: " << hit_ratio << endl;
    cout << "Miss ratio: " << miss_ratio << endl;

    return 0;
}

/*
input : 
Enter number of frames: 3
Enter page reference string (end with -1): 1 2 3 4 1 2 3 4 -1



output:
1 2 3 
Hit ratio: 0.375
Miss ratio: 0.625


*/
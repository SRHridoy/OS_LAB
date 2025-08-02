/*
    * FIFO Page Replacement Algorithm Implementation in C++
    * Find hit and miss ratio
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter number of frames: ";
    int n; cin >> n;
    queue<int> frames;
    unordered_set<int> lookup;
    cout<<"Enter page reference string (end with -1): ";
    vector<int> pages;
    int page;
    while(cin >> page && page != -1){
        pages.push_back(page);
    }
    int hits = 0, misses = 0;
    for(auto p : pages) {
        // Check if page is already in frames
        if(lookup.find(p) != lookup.end()) {
            hits++;
            continue; // Page hit, no need to replace
        }
        // Page miss, need to replace
        misses++;
        if(frames.size() < n) {
            frames.push(p);
            lookup.insert(p);
        } else {
            int old_page = frames.front();
            frames.pop();
            lookup.erase(old_page);
            frames.push(p);
            lookup.insert(p);
        }
    }
   while(frames.size() > 0) {
        cout << frames.front() << " ";
        frames.pop();
    }
    cout << endl;
    // Calculate hit and miss ratios
    double hit_ratio = (double)hits / (hits + misses);
    double miss_ratio = (double)misses / (hits + misses);
    cout<<"Hit ratio: "<<hit_ratio<<endl;
    cout<<"Miss ratio: "<<miss_ratio<<endl;
}

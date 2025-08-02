/*
    * MRU Page Replacement Algorithm Implementation in C++
    * Find hit and miss ratio
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter number of frames: ";
    int n; cin >> n;
    list<int> frames;
    unordered_map<int, list<int>::iterator> frame_map;
    cout<<"Enter page reference string (end with -1): ";
    vector<int> pages;
    int page;
    while(cin >> page && page != -1){
        pages.push_back(page);
    }
    int hits = 0, misses = 0;
    for(auto p : pages) {
        // Check if page is already in frames
        if(frame_map.find(p) != frame_map.end()) {
            hits++;
            // Move the accessed page to the front (most recently used)
            frames.erase(frame_map[p]);
            frames.push_front(p);
            frame_map[p] = frames.begin();
            continue; // Page hit, no need to replace
        }
        // Page miss, need to replace
        misses++;
        if(frames.size() < n) {
            frames.push_front(p);
            frame_map[p] = frames.begin();
        } else {
            int old_page = frames.front();
            frames.pop_front();
            frame_map.erase(old_page);
            frames.push_front(p);
            frame_map[p] = frames.begin();
        }
    }
    for(auto u : frames) {
        cout << u << " ";
    }
    cout << endl;
    // Calculate hit and miss ratios
    double hit_ratio = (double)hits / (hits + misses);
    double miss_ratio = (double)misses / (hits + misses);
    cout<<"Hit ratio: "<<hit_ratio<<endl;
    cout<<"Miss ratio: "<<miss_ratio<<endl;
}

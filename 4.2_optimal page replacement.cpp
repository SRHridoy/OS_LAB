#include <iostream>
#include <vector>
using namespace std;

// ভবিষ্যতে সবচেয়ে দেরিতে ব্যবহৃত পেজটি বের করার ফাংশন
int findOptimal(vector<int> &frame, int ref[], int pages, int idx){
    int farthest = idx, pos = -1;
    for(int i=0; i<frame.size(); i++){
        int j;
        for(j=idx; j<pages; j++){
            if(frame[i] == ref[j]){
                if(j > farthest){
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if(j==pages) return i; // ভবিষ্যতে আর ব্যবহার হবে না এমন পেজ পেলে সেটিই রিটার্ন করো
    }
    return (pos == -1) ? 0 : pos; // অন্যথায় সবচেয়ে দূরে ব্যবহার হবে সেটি
}

int main(){
    int pages, frames, hits=0;

    cout<<"Enter number of pages: ";
    cin>>pages;
    int ref[pages];

    cout<<"Enter reference string:\n";
    for(int i=0; i<pages; i++)
        cin>>ref[i];

    cout<<"Enter frame size: ";
    cin>>frames;

    vector<int> frame;

    for(int i=0; i<pages; i++){
        bool found = false;
        for(int j : frame){
            if(j==ref[i]){
                hits++; found=true; break;
            }
        }
        if(found) continue;

        if(frame.size() < frames)
            frame.push_back(ref[i]);  // ফ্রেমে জায়গা থাকলে ঢুকাও
        else{
            int j = findOptimal(frame, ref, pages, i+1);
            frame[j] = ref[i]; // Optimal অনুযায়ী বদলানো
        }
    }

    cout<<"\nHits: "<<hits<<"\nFaults: "<<pages-hits<<endl;
}

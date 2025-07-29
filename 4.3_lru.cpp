#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

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

    list<int> frame; // LRU এর জন্য list ব্যবহার
    unordered_map<int, list<int>::iterator> pos;

    for(int i=0;i<pages;i++){
        if(pos.find(ref[i])!=pos.end()){
            hits++;
            frame.erase(pos[ref[i]]); // আগের পজিশন থেকে সরিয়ে সামনের দিকে আনা
        }
        else if(frame.size()==frames){
            pos.erase(frame.back()); // সবচেয়ে পুরানো পেজ সরানো
            frame.pop_back();
        }
        frame.push_front(ref[i]);   // নতুন পেজকে সামনে ঢোকানো
        pos[ref[i]]=frame.begin();  // পেজের নতুন পজিশন আপডেট করা
    }

    cout<<"\nHits: "<<hits<<"\nFaults: "<<pages-hits<<endl;
}

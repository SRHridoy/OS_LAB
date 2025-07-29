#include <iostream>
#include <queue>
using namespace std;

int main(){
    int pages, frames, hits = 0;

    // মোট পেজের সংখ্যা ইনপুট নেওয়া
    cout << "Enter number of pages: ";
    cin >> pages;

    int ref[pages];

    // পেজ রেফারেন্স স্ট্রিং ইনপুট নেওয়া
    cout << "Enter page reference string:\n";
    for(int i=0; i<pages; i++){
        cin >> ref[i];
    }

    // ফ্রেম সংখ্যা ইনপুট নেওয়া
    cout << "Enter frame size: ";
    cin >> frames;

    queue<int> q; // FIFO জন্য queue ব্যবহার করা হয়েছে
    bool inFrame[1000] = {0}; // পেজগুলো ফ্রেমে আছে কিনা চেক করার জন্য

    // প্রতিটি পেজ রেফারেন্স এর জন্য চেক করা
    for(int i=0; i<pages; i++){

        // পেজ যদি আগেই ফ্রেমে থাকে তাহলে Hit হবে
        if(inFrame[ref[i]]){
            hits++;
        }
        else{
            // যদি ফ্রেম ফুল হয়ে থাকে তাহলে প্রথম পেজ বের করে দেওয়া (FIFO)
            if(q.size() == frames){
                int old_page = q.front(); // প্রথম পেজ
                q.pop();                  // প্রথম পেজ বের করা
                inFrame[old_page] = false; // সেই পেজকে "ফ্রেমে নেই" বলে মার্ক করা
            }

            // নতুন পেজটি ফ্রেমে ঢোকানো
            q.push(ref[i]);
            inFrame[ref[i]] = true; // নতুন পেজকে "ফ্রেমে আছে" বলে মার্ক করা
        }
    }

    // মোট Hit ও Fault সংখ্যা প্রিন্ট করা
    cout << "\nHits: " << hits << endl;
    cout << "Faults: " << pages - hits << endl;

    return 0;
}

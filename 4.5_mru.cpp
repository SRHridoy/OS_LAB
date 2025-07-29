#include <iostream>
#include <vector>
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

    vector<int> frame;

    for(int i=0; i<pages; i++){
        bool found = false;
        for(int j : frame){
            if(j==ref[i]){
                hits++; found=true; break;
            }
        }
        if(found){
            // MRU জন্য সাম্প্রতিক পেজ শেষে রাখা
            for(int k=0; k<frame.size(); k++){
                if(frame[k]==ref[i]){
                    frame.erase(frame.begin()+k);
                    frame.push_back(ref[i]);
                    break;
                }
            }
            continue;
        }

        if(frame.size() < frames)
            frame.push_back(ref[i]);  // ফ্রেমে জায়গা থাকলে ঢুকাও
        else{
            frame.pop_back();    // MRU পেজ (শেষ পেজ) সরাও
            frame.push_back(ref[i]);
        }
    }

    cout<<"\nHits: "<<hits<<"\nFaults: "<<pages-hits<<endl;
}

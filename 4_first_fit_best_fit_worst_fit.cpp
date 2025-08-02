#include<bits/stdc++.h>
using namespace std;
void firstFit(int holes[],int n,int processSize){
    for(int i=0; i < n; i++){
        if(holes[i]>=processSize){
            cout << "First Fit: " << holes[i] << "k" << endl;
            return;
        }
            
    }
    cout << "Wait Please Don't have sufficient Space" << endl;
}
void bestFit(int holes[],int n,int processSize){
    sort(holes,holes+n);
    for(int i=0; i < n; i++){
        if(holes[i]>=processSize){
            cout << "Best Fit: " << holes[i] << "k"<< endl;
            return;
        }
    }
    cout << "Wait Please Don't have sufficient Space" << endl;
}
void worstFit(int holes[],int n,int processSize){
    sort(holes,holes+n,greater<int>());
    if(processSize<=holes[0]){
        cout << "Worst Fit: " << holes[0] << "k" << endl;
        return;
    }
    cout << "Wait Please Don't have sufficient Space" << endl;
}



int main(){
    int n;
    cout << "Enter the number of Holes availabe:";
    cin >> n;

    cout << "Enter the Hole Sizes : ";
    int holes[n];
    for(int i = 0; i < n; i++){
        cin >> holes[i];
    }

    int processSize;
    cout << "Enter process size: ";
    cin >> processSize;

    firstFit(holes, n, processSize);
    bestFit(holes, n, processSize);
    worstFit(holes, n, processSize);


}

/*
Input:
Enter the number of Holes available: 3
Enter the Hole Sizes: 500 1000 1500
Enter process size: 400


Output: 
First Fit: 500k
Best Fit: 500k
Worst Fit: 1500k



*/
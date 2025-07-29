#include <iostream>
using namespace std;

int main() {
    int n, m;
    
    // প্রসেস এবং রিসোর্সের সংখ্যা ইনপুট নেওয়া
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;
    
    int allocation[n][m], max[n][m], need[n][m];
    int available[m];
    
    // Allocation Matrix ইনপুট নেওয়া
    cout << "\nEnter Allocation Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> allocation[i][j];
        }
    }
    
    // Max Need Matrix ইনপুট নেওয়া
    cout << "\nEnter Max Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> max[i][j];
        }
    }
    
    // Available Resources ইনপুট নেওয়া
    cout << "\nEnter Available Resources:\n";
    for(int i=0; i<m; i++){
        cin >> available[i];
    }
    
    // Need Matrix গণনা করা (Need = Max - Allocation)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    
    bool finish[n] = {0}; // কোন প্রসেস শেষ হয়েছে কিনা ট্র্যাক করার জন্য
    int safeSeq[n];       // Safe Sequence সংরক্ষণের জন্য
    int cnt = 0;          // কয়টা প্রসেস শেষ হয়েছে তা গণনার জন্য
    
    while(cnt < n){
        bool found = false;
        for(int i=0; i<n; i++){
            if(finish[i]==0){
                int j;
                for(j=0; j<m; j++){
                    // যদি কোনো প্রসেসের প্রয়োজনের থেকে কম রিসোর্স থাকে
                    if(need[i][j] > available[j])
                        break;
                }
                
                // প্রসেসটি যদি Available Resources দিয়ে চালানো যায়
                if(j == m){
                    for(int k=0; k<m; k++)
                        available[k] += allocation[i][k]; // রিসোর্স ফেরত নেওয়া
                    safeSeq[cnt++] = i; // প্রসেসকে সেফ সিকোয়েন্সে রাখা
                    finish[i] = true;   // প্রসেস সম্পন্ন হিসেবে মার্ক করা
                    found = true;       // অন্তত একটি প্রসেস পাওয়া গেছে
                }
            }
        }
        if(!found) break; // আর কোনো প্রসেস চালানো না গেলে ডেডলক হবে
    }
    
    // ডেডলক আছে কিনা চেক করা
    if(cnt != n)
        cout << "\nDeadlock detected! (ডেডলক হয়েছে!)\n";
    else{
        cout << "\nSafe Sequence (সেফ সিকোয়েন্স): ";
        for(int i=0; i<n; i++)
            cout << "P" << safeSeq[i] << " ";
        cout << endl;
    }
    
    return 0;
}

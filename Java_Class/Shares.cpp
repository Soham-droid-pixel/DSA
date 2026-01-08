#include<bits/stdc++.h>
using namespace std;

int main() {
    int Shareprice[5] = {600, 2000, 300, 1200, 1900};
    double money = 100000;
    
    int best_cp = 0;
    int best_sp = 0;
    int max_diff = 0;
    
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            int diff = Shareprice[j] - Shareprice[i];
            
            if(diff > max_diff) {
                max_diff = diff;
                best_cp = Shareprice[i];
                best_sp = Shareprice[j];
            }
        }
    }

    int shares = (int)(money / best_cp);
    double total_profit = shares * max_diff;
    
    cout << "Best Strategy Found:" << endl;
    cout << "Cost Price (Buy): " << best_cp << endl;
    cout << "Selling Price: " << best_sp << endl;
    cout << "Profit per Share: " << max_diff << endl;
    cout << "Total Shares Bought: " << shares << endl;
    cout << "Total Profit on 1 Lakh: " << total_profit << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// Function to solve the knapsack problem
void knapsack(int n, int M, int weights[], int values[]) {
    int dp[n + 1][M + 1];

    // Initialize the table
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    //  The items selected
    int selectedItems[n], itemCount = 0;
    int i = n, j = M;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems[itemCount++] = i - 1;
            j -= weights[i - 1];
        }
        i--;
    }
    int total_profit=0;
    // Print the selected packages
    cout << "Packages selected by the thief:\n";
    for (int i = itemCount - 1; i >= 0; --i) {
        cout << " Weight = " << weights[selectedItems[i]]
             << "      Profit value  = " << values[selectedItems[i]] << endl;
             total_profit+= values[selectedItems[i]];
    }
    cout<<"The Selected Packages is: "<<endl;
    for (int i = itemCount - 1; i >= 0; --i) {
        cout << selectedItems[i] + 1<<" " ;
    }
    cout<<endl;
    cout<<"The total profit value is: "<<total_profit;
}

int main() {
    srand(time(0)); 
    int n;
    cout << "Enter the number of packages: ";
    cin >> n;
    cout<<endl;
    int weights[n];
    int values[n];

    // Generate random weights and values
    for (int i = 0; i < n; ++i) {
        weights[i] = rand() % 101; 
        // Generate a random value between 0 and 100
        values[i] = rand() % 101;  
    }

    int M;
    cout << "Enter the maximum weight the thief can carry: ";
    cin >> M;
    cout<<endl;
    knapsack(n, M, weights, values);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cout<<"Enter number"<<endl;
    cin>>num;
    double guess=num;
    double epsilon=1e-6;
    while((guess*guess-num)>epsilon)
       {
        guess=0.5*(guess+num/guess);
       }
    int IntGuess=(int)(guess+0.5);
       if(1LL*IntGuess*IntGuess==(long long)num)
       {
        cout<<"It is a valid perfect square"<<endl;
       }
       else{
    cout<<"It is not a valid perfect square"<<endl;
       }
    return 0;

}
/*/*
-------------------------------------------------------------
🧮 Newton-Raphson Method for Perfect Square
-------------------------------------------------------------

🔹 Formula used:
   y_next = 0.5 * (y + x / y)

🔹 Idea:
   - Approximate square root of x using repeated iteration
   - Stop when difference between guess² and num is less than epsilon (tolerance)

🔹 Precision Handling:
   - We use epsilon = 1e-6 to decide when to stop iterations
   - Rounding with (int)(guess + 0.5) ensures we test integer square

🔹 Overflow Handling:
   - Use 1LL * IntGuess * IntGuess to avoid overflow in large inputs

🔹 Time Complexity: O(log num) on average
🔹 Space Complexity: O(1)

🔹 Drawback:
   - Uses floating-point numbers → needs careful precision management
-------------------------------------------------------------
*/
/*#include <bits/stdc++.h>
using namespace std;

// Function to check if num is a perfect square using binary search
bool isPerfectSquareBinary(int num) {
    if (num < 0) return false;
    if (num == 0 || num == 1) return true;

    int low = 1, high = num / 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long square = 1LL * mid * mid;

        if (square == num)
            return true;
        else if (square < num)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (isPerfectSquareBinary(num))
        cout << "It is a valid perfect square (Binary Search)" << endl;
    else
        cout << "It is not a valid perfect square (Binary Search)" << endl;

    return 0;
}
*/
/*/*
-------------------------------------------------------------
🔢 Binary Search to Check Perfect Square
-------------------------------------------------------------

🔹 Idea:
   - Square root must lie between 1 and num / 2
   - Use binary search to find mid such that mid² == num

🔹 Logic:
   - Calculate mid = (low + high) / 2
   - If mid² == num → return true
   - If mid² < num → search right half
   - If mid² > num → search left half

🔹 Edge Cases:
   - num < 0 → false
   - num == 0 or 1 → true

🔹 Overflow Handling:
   - Use 1LL * mid * mid to avoid overflow during multiplication

🔹 Time Complexity: O(log num)
🔹 Space Complexity: O(1)

🔹 Advantage:
   - Purely integer-based → no floating point precision issues
-------------------------------------------------------------
*/

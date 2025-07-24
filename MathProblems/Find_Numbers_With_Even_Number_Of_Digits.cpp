#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int digits = 0;
            int temp = nums[i];  // Use temp so original array is not modified
            while (temp > 0) {
                temp = temp / 10;
                digits++;
            }
            if (digits % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    // Example input
    vector<int> nums = {12, 345, 2, 6, 7896};

    Solution solution;
    int result = solution.findNumbers(nums);

    cout << "Count of numbers with even number of digits: " << result << endl;

    return 0;
}
/*/*
🛑 COMMON MISTAKES TO AVOID in digit-count problems:

1️⃣ Don't forget to reset your digit counter (e.g., flag/digits) for every number.
    🔁 Declare/reset inside the for-loop.

2️⃣ Never modify the original input array (nums[i]) directly.
    ✅ Use a temporary variable like: int temp = nums[i];

3️⃣ Don't assume all numbers are > 0.
    🔎 Handle edge cases like 0 (has 1 digit).

4️⃣ Avoid overcomplicating digit count.
    ✅ Use while(temp > 0) { temp /= 10; digits++; }

5️⃣ Be careful with loop bounds.
    ✅ Use: for (int i = 0; i < nums.size(); i++)

6️⃣ Don’t forget required headers.
    ✅ Include: #include <iostream>, #include <vector>

7️⃣ If you're not using `using namespace std;`, prefix std:: to cout, vector, etc.

8️⃣ Don’t confuse even/odd logic.
    ✅ Even digits: if (digits % 2 == 0)

9️⃣ Avoid unnecessary string conversions unless allowed.
    ❗ Use string methods only if problem permits.

🔁 ALWAYS TEST with:
    - Single-digit numbers
    - Even and odd-digit numbers
    - Zero and edge cases like 1000, 99999
*/
/*Best:
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(const vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            int digits = 0;
            int temp = num;

            // Handle 0 as a special case (though not in LeetCode input)
            if (temp == 0) digits = 1;

            while (temp > 0) {
                temp /= 10;
                digits++;
            }

            if (digits % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {12, 345, 2, 6, 7896};
    Solution sol;
    cout << "Count of even-digit numbers: " << sol.findNumbers(nums) << endl;
    return 0;
}
*/
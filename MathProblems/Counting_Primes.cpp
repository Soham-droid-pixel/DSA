#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int p = 2; p * p < n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        int primeCount = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primeCount++;
            }
        }

        return primeCount;
    }
};

int main() {
    Solution sol;

    int n1 = 10;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << sol.countPrimes(n1) << endl; 
    cout << "-----------------------------------" << endl;

    int n2 = 20;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << sol.countPrimes(n2) << endl; 
    cout << "-----------------------------------" << endl;

    int n3 = 1;
    cout << "Input: n = " << n3 << endl;
    cout << "Output: " << sol.countPrimes(n3) << endl; 
    cout << "-----------------------------------" << endl;

    return 0;
}

/*
====================================================================
## Algorithm Notes: Sieve of Eratosthenes
====================================================================

**What is it?**
The Sieve of Eratosthenes is a highly efficient algorithm for finding all prime numbers up to a given limit. Instead of checking each number individually, it works by eliminating multiples.

**Concept:**
The core idea is to create a "checklist" (a boolean array) for all numbers from 0 to n. We first assume every number is prime (mark them 'true'). Then, we find the first prime number (2) and cross off all its multiples (4, 6, 8,...) by marking them 'false'. We then find the next number that *wasn't* crossed off (3) and cross off all its multiples (6, 9, 12,...). We repeat this process, and any number left marked 'true' at the end is a prime number.

**Small Example (n = 10):**
1.  **Create List:** `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`
    **Checklist:** `[T, T, T, T, T, T, T, T, T, T]`

2.  **Mark 0, 1 as False:**
    **Checklist:** `[F, F, T, T, T, T, T, T, T, T]`

3.  **Start at p = 2:** '2' is True. Mark all multiples of 2 as False (4, 6, 8).
    **Checklist:** `[F, F, T, T, F, T, F, T, F, T]`

4.  **Next p = 3:** '3' is True. Mark all multiples of 3 as False (6, 9).
    **Checklist:** `[F, F, T, T, F, T, F, T, F, F]`

5.  **Next p = 5:** '5' is True. Mark multiples of 5 (none left < 10). The loop stops because the next prime (7) has `p*p = 49`, which is `> 10`.

6.  **Final Count:** Count the 'True' values from index 2 onwards: 2, 3, 5, 7.
    **Answer:** 4
*/
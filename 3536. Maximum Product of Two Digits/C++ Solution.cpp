// https://leetcode.com/problems/maximum-product-of-two-digits/submissions/2197645790/

class Solution {
public:
    int maxProduct(int n) {
        // We track the two largest digits seen so far.
        int maxDigit = 0, secondMaxDigit = 0;
        // While n still has nonzero digits:
        while (n) {
            // Extract last digit of n
            int digit = n % 10;
            // If it a new maximum, update both secondMaxDigit and maxDigit
            if (digit > maxDigit) {
                secondMaxDigit = maxDigit;
                maxDigit = digit;
            // Otherwise if it's a new second-maximum, update just secondMaxDigit
            } else if (digit > secondMaxDigit) {
                secondMaxDigit = digit;
            }
            // Otherwise nothing need be done

            // Divide 10 out of n to "move" it to the next digit
            n /= 10;
        }
        // Return the product.
        return maxDigit * secondMaxDigit;
    }
};

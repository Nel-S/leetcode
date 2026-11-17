// Added by LeetCode in the background
#include <cstdint>

class Solution {
public:
    int reverse(int x) {
        /* Represents the maximum number of digits a signed 32-bit integer
           can have. More accurately, this is ceil(log_10(2^31)).
        */
        constexpr int32_t MAX_SIGNED_32_BIT_DIGITS = 10;
        /* Constants later used in determining whether the reversed value
           is representable in 32 signed bits.
        */
        constexpr int32_t MAX_REVERSED_X = INT32_MAX/10; // Integer division
        constexpr int32_t MAX_INT_REMAINDER_MOD_10 = INT32_MAX % 10;

        /* We convert (a copy of) x to its absolute value.
           We also handle -2^31 as a special case, as it is the only 
           negative 32-bit integer whose inverse would still be negative.
        */
        if (x == INT32_MIN) return 0;
        int32_t absoluteX = x < 0 ? -x : x;
        /* Then, we repeat the algorithm for each digit in the 
           absolute-value integer, lowest to highest. Each time we divide
           the value by 10 to get the next lowest integer in absoluteX.
        */
        int32_t reversedX = 0;
        for (int32_t i = 0; i < MAX_SIGNED_32_BIT_DIGITS && absoluteX; ++i, absoluteX /= 10) { // Integer division
            /* If the next iteration of reversedX would overflow, we return 
               0.
               This occurs when
               reversedX*10 + (absoluteX % 10) > INT32_MAX
               -> reversedX > (INT32_MAX - (absoluteX % 10))/10.
               In practice this equates to > INT32_MAX/10 unless
               (absoluteX % 10) > (INT32_MAX % 10), in which case it will
               be > INT32_MAX/10 - 1.
            */
            if (reversedX > MAX_REVERSED_X - ((absoluteX % 10) > MAX_INT_REMAINDER_MOD_10)) return 0;
            /* Otherwise we add the next digit to reversedX. */
            reversedX = reversedX*10 + (absoluteX % 10);
        }
        /* Restore reversedX's sign if applicable, and return it. */
        if (x < 0) reversedX = -reversedX;
        return reversedX;
    }
};

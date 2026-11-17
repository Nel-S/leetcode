// https://leetcode.com/problems/destroying-asteroids/submissions/2183382288

// Added by LeetCode in the background
#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
    bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
        /* The optimal order to destroy the asteroids will always be from smallest asteroid to largest asteroid.
        That way, by the time the kth-largest asteroid is encountered, the planet has the combined mass of all n - k asteroids that came before it. Any other ordering would cause the planet to have either the same amount of mass (making no difference), or less mass (potentially making the effort impossible).
        To that end, we begin by sorting the array of asteroids.*/
        std::sort(asteroids.begin(), asteroids.end());
        /* Then, we emulate the algorithm, adding the last asteroid's mass to the planet after each iteration. If the combined mass is still not enough, it is not possible to destroy the current asteroid.
        However, we must convert the mass counter to a 64-bit integer first, because the maximum possible combined mass (10^5 + 10^5(10^5) = 10000100000) is greater than the largest possible signed integer (2^15 or 2^31 depending on the platform).
        */
        uint64_t combinedMass = mass;
        for (const int asteroid : asteroids) {
            if (combinedMass < static_cast<uint64_t>(asteroid)) return false;
            combinedMass  += asteroid;
        }
        // Otherwise if all asteroids are iterated through, it is indeed possible after all.
        return true;
    }
};
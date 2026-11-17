// https://leetcode.com/problems/asteroid-collision/submissions/2184249613

// Added by LeetCode in the background
#include <vector>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        // Create the output vector.
        std::vector<int> output;
        
        // For each asteroid in the list:
        for (const int asteroid : asteroids) {
            /* We first resolve any collisions that involve the current asteroid.
            Since a (possibly chain of) collisions only occurs when a right-moving asteroid is directly followed by a left-moving asteroid, we only have to worry about resolving collisions with left-moving asteroids. (For right-moving asteroids, either we will encounter a left-moving asteroid sometime in the future, in which case the collision can be resolved then; or we will never encounter any more left-moving asteroids, in which case the right-moving asteroid will never be involved in a collision in the first place.)
            */
            if (asteroid < 0) {
                /* Collisions will only occur if A. there was an asteroid directly before the current one, and B. said previous asteroid was right-moving. */
                while (!output.empty() && output.back() > 0) {
                    int lastAsteroid = output.back();
                    /* Since the current asteroid is negative, and the last asteroid was positive, we negate the sign of the last asteroid so we can compare them. (All positive ints can also be converted to negative ints without overflowing, while the reverse is not always true.)
                    If the current asteroid has an equal/larger magnitude (negative is farther from 0), the last asteroid is removed.*/
                    if (-lastAsteroid >= asteroid) output.pop_back();
                    /* If the last asteroid has an equal/larger magnitude (negative is farther from 0), the current asteroid is removed.*/
                    if (-lastAsteroid <= asteroid) goto currentAsteroidSkipped;
                }
            }
            /* If the current asteroid wasn't removed, we add it to the output.*/
            output.push_back(asteroid);
            /* Otherwise continue to next asteroid in list. */
            currentAsteroidSkipped: continue;
        }
        return output;
    }
};
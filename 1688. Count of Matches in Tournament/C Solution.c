// https://leetcode.com/problems/count-of-matches-in-tournament/submissions/1351594556/

int numberOfMatches(int n) {
    /* Teams are only eliminated by losing a match, and only one team is eliminated per match. Therefore for n - 1 teams to be eliminated, exactly n - 1 matches need to be played.
       The only edge case would be if 0 (or fewer) teams exist, in which case the number of matches needed is simply 0, but we are assured 1 <= n.*/
    return n - 1;
}
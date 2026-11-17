# https://leetcode.com/problems/determine-if-two-events-have-conflict/submissions/2021532933

# Added by LeetCode in the background
from typing import List

class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        # Since we are guaranteed all events happened (and thus all times
        # exist) on the same day; and since they are already in 24-hour
        # HH:MM format, they are already in a format such that
        # str(time2) >= str(time1) if time2 occurred after time1. Therefore
        # we can directly compare the raw time values.
        # If a conflict exists, either Event 2 must start while Event 1 is
        # ongoing (in which case event1[0] <= event2[0] <= event1[1]) or
        # Event 1 must start while Event 2 is ongoing (in which case
        # event2[0] <= event1[0] <= event2[1]).
        return event1[0] <= event2[0] <= event1[1] or event2[0] <= event1[0] <= event2[1]
        
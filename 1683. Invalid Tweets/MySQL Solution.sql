-- https://leetcode.com/problems/invalid-tweets/submissions/2193486745

# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15
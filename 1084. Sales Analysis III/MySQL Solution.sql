-- https://leetcode.com/problems/sales-analysis-iii/submissions/2193485968

# First, determine valid product IDs
WITH ValidProductIDs AS (
    SELECT product_id
    FROM Sales
    # Group entries based on product ID
    GROUP BY product_id
    # Then determine earliest/latest sale dates for that product, and filter based on whether they occurred within the first quarter only
    HAVING MIN(sale_date) >= "2019-01-01" AND MAX(sale_date) <= "2019-03-31"
)
# Then return the product IDs and names...
SELECT ValidProductIDs.product_id, product_name
# ...after the Product and Valid Product ID tables are joined together
FROM Product INNER JOIN ValidProductIDs ON Product.product_id = ValidProductIDs.product_id
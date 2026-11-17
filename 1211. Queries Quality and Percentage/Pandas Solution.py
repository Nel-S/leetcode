# https://leetcode.com/problems/queries-quality-and-percentage/submissions/2193473940

import pandas as pd

def queries_stats(queries: pd.DataFrame) -> pd.DataFrame:
    # Calculate Quality for each individual entry.
    queries["quality"] = queries["rating"]/queries["position"]
    # Calculate percentage for each individual entry. (Each is either 0% or 100%; averaging
    # these will give the overall mean percentage.)
    queries["poor_query_percentage"] = 100*queries["rating"].lt(3)
    # Group all identical query_name entries together, and average their qualities and percentages.
    result = queries[["query_name", "quality", "poor_query_percentage"]].groupby("query_name").mean()
    # Since Pandas' built-in .round() rounds-to-even instead of rounding away from 0, we
    # perform the rounding manually. In reality this breaks ties by rounding up, but
    # that works here since quality and poor_query_percentage will both always be non-negative.
    result = np.floor(100.*result + 0.5)/100.
    # Move query_name from index to be a standalone column alonside the others, and return.
    result.reset_index(inplace=True)
    return result
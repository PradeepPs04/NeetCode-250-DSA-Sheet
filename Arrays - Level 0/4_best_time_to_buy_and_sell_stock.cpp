/*
    Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

    Note: Stock must be bought before being sold.
*/

int maximumProfit(vector<int> &prices)
{
    int lastBuy = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > lastBuy)
            maxProfit = max(maxProfit, prices[i] - lastBuy);
        else
            lastBuy = prices[i];
    }

    return maxProfit;
}
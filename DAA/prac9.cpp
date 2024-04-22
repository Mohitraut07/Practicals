#include <iostream>
#include <vector>
using namespace std;

int lcs(string X, string Y, int m, int n, vector<vector<int> > &dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
    else
        return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                              lcs(X, Y, m - 1, n, dp));
}

string findLCS(string X, string Y, int m, int n, vector<vector<int> > &dp)
{
    int i = m, j = n;
    string lcsSequence = "";
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcsSequence = X[i - 1] + lcsSequence;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return lcsSequence;
}

int main()
{
    string S1 = "EXPONENTIAL";
    string S2 = "POLYNOMIAL";
    int m = S1.size();
    int n = S2.size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
    cout << "Length of LCS is " << lcs(S1, S2, m, n, dp) << endl;
    string lcsSequence = findLCS(S1, S2, m, n, dp);
    cout << "LCS is: " << lcsSequence;
    return 0;
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllDpPrograms
    {
        static bool IsPossible(int N, int[] coins)
        {
            // code here
            //return Recursion(coins,0,0,N);
            int[,] dp = new int[N + 1, 2025];
            for (int i = 0; i < N + 1; i++)
            {
                for (int j = 0; j < 2025; j++)
                {
                    dp[i, j] = -1;
                }
            }
            int possible = Memoization(coins, 0, 0, N, dp);

            if (possible == 1)
                return true;
            else
                return false;
        }

        static bool Recursion(int[] coins, int currInd, int sum, int N)
        {
            if (sum != 0 && (sum == 2024 || sum % 20 == 0 || sum % 24 == 0))
            {
                return true;
            }
            if (currInd == N)
            {
                return false;
            }
            bool take = Recursion(coins, currInd + 1, sum + coins[currInd], N);
            if (take)
                return take;
            bool noTake = Recursion(coins, currInd, sum, N);
            if (noTake)
                return noTake;
            return false;
        }

        static int Memoization(int[] coins, int currInd, int sum, int N, int[,] dp)
        {
            if (sum > 0 && (sum == 2024 || sum % 20 == 0 || sum % 24 == 0))
            {
                return dp[currInd, sum] = 1;
            }
            if (currInd >= N)
            {
                return dp[currInd, sum] = 0;
            }
            if (dp[currInd, sum] != -1)
                return dp[currInd, sum];
            int noTake = Memoization(coins, currInd + 1, sum, N, dp);
            if (noTake == 1)
                return dp[currInd, sum] = 1;
            int take = Memoization(coins, currInd + 1, sum + coins[currInd], N, dp);
            if (take == 1)
                return dp[currInd, sum] = 1;
            return dp[currInd, sum] = 0;
        }
    }
}

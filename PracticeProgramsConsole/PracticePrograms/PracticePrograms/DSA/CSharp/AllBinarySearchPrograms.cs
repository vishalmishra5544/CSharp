using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllBinarySearchPrograms
    {
        static int SearchInSorted(int[] arr, int N, int K)
        {
            //Your code here
            int low = 0, high = arr.Length - 1, mid;
            while (low <= high)
            {
                mid = low + (high - low) / 2;
                if (arr[mid] == K)
                    return 1;
                else if (arr[mid] < K)
                {
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            return 0;
        }
    }
}

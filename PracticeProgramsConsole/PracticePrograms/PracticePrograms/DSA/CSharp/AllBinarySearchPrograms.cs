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


        public int count(int[] arr, int n, int x)
        {
            //Your code here
            int firstOccurrence = FirstOccurrence(arr, n, x);
            int lastOccurrence = LastOccurrence(arr, n, x);
            if (firstOccurrence == -1 || lastOccurrence == -1)
                return 0;
            return lastOccurrence - firstOccurrence + 1;
        }

        private int FirstOccurrence(int[] arr, int n, int x)
        {
            int s = 0, e = n - 1;
            int ans = -1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (arr[mid] == x)
                {
                    ans = mid;
                    e = mid - 1;
                }
                else if (arr[mid] > x)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            return ans;
        }
        private int LastOccurrence(int[] arr, int n, int x)
        {
            int s = 0, e = n - 1;
            int ans = -1;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (arr[mid] == x)
                {
                    ans = mid;
                    s = mid + 1;
                }
                else if (arr[mid] > x)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            return ans;
        }

        public int peakElement(int[] arr, int n)
        {
            int low = 0, high = n - 1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                // Check if mid is a peak
                if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
                    (mid == n - 1 || arr[mid + 1] <= arr[mid]))
                {
                    return mid;
                }

                // If the element to the left of mid is greater,
                // then peak must be in the left subarray
                if (mid > 0 && arr[mid - 1] > arr[mid])
                {
                    high = mid - 1;
                }
                // If the element to the right of mid is greater,
                // then peak must be in the right subarray
                else
                {
                    low = mid + 1;
                }
            }

            return -1;
        }

        public long floorSqrt(long x)
        {
            //Your code here
            long s = 0, e = x;
            double ans = -1;
            while (s <= e)
            {
                long mid = s + (e - s) / 2;
                if (mid * mid <= x)
                {
                    ans = mid;
                    s = mid + 1;
                }
                else if (mid * mid > x)
                {
                    e = mid - 1;
                }
            }
            return (long)Math.Floor(ans);
        }
    }
}

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

            // find decimal part also:
            //double step = 0.1;
            //double finalAns = ans;
            //int precisionCount =3;
            //for (int i = 1; i <= precisionCount; i++)
            //{
            //    finalAns += step;
            //    double j = finalAns;
            //    while (j * j <=x)
            //    {
            //        finalAns = j;
            //        j = j + step;
            //    }
            //    step /= 10;
            //}
        }

        //Function to search a given number in row-column sorted matrix.
        public static bool searchInRowColumnWiseSortedMatrix(List<List<int>> matrix, int n, int m, int x)
        {
            int i = 0, j = m - 1;
            while (i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1)
            {
                if (matrix[i][j] == x)
                    return true;
                else if (matrix[i][j] > x)
                {
                    j--;
                }
                else if (matrix[i][j] < x)
                    i++;
            }
            return false;
        }

        public static int SearchInSortedRotatedArray(int[] A, int l, int h, int key)
        {
            //Your code here
            int pivotElementIndex = FindPivotElement(A, l, h);
            int indexOfFound = 0;
            if (key >= A[l] && key <= A[pivotElementIndex])
                indexOfFound = BinarySearch(A, l, pivotElementIndex, key);
            else if (pivotElementIndex+1<=h && key >= A[pivotElementIndex + 1] && key <= A[h])
                indexOfFound = BinarySearch(A, pivotElementIndex + 1, h, key);
            return indexOfFound;
        }

        private static int FindPivotElement(int[] arr, int l, int h)
        {
            int mid = 0;
            while (l <= h)
            {
                if (l == h)
                    return l;
                mid = l + (h - l) / 2;
                if (mid - 1 >= l && arr[mid] < arr[mid - 1])
                    return mid - 1;
                if (mid + 1 <= h && arr[mid] > arr[mid + 1])
                    return mid;
                if (arr[l] > arr[mid])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return mid;
        }

        private static int BinarySearch(int[] arr, int s, int e, int key)
        {
            int mid = 0;
            while (s <= e)
            {
                mid = s + (e - s) / 2;
                if (arr[mid] == key)
                    return mid;
                if (arr[mid] > key)
                    e = mid - 1;
                else if (arr[mid] < key)
                    s = mid + 1;
            }
            return -1;
        }

        // Function to find the quotient using binary search
        public static int divide_binary_search(int dividend,
                                               int divisor)
        {

            if (divisor == 1)
                return dividend;

            if (divisor == -1)
                return -dividend;

            // Declaring and Initialising
            // the variables.
            long low = 0, high = Math.Abs(dividend);
            long mid;

            // To store the Quotient.
            int quotient = 0;

            while (low <= high)
            {

                // Calculating mid.
                mid = low + ((high - low) / 2);

                // To search in lower bound.
                if (Math.Abs(mid * divisor)
                    > Math.Abs(dividend))
                    high = mid - 1;

                // To search in upper bound.
                else
                {
                    quotient = (int)mid;
                    low = mid + 1;
                }
            }

            // Checking the parity and
            // returning the Quotient.
            if ((dividend < 0 && divisor < 0
                 || dividend > 0 && divisor > 0))
                return quotient;
            else
                return -quotient;
        }

        public static int BinarySearchInNearlySortedArray(int[] arr, int l, int r, int x)
        {
            if (r >= l)
            {
                int mid = l + (r - l) / 2;

                // If the element is present at
                // one of the middle 3 positions
                if (arr[mid] == x)
                    return mid;
                if (mid > l && arr[mid - 1] == x)
                    return (mid - 1);
                if (mid < r && arr[mid + 1] == x)
                    return (mid + 1);

                // If element is smaller than mid, then
                // it can only be present in left subarray
                if (arr[mid] > x)
                    r = mid - 2;

                // Else the element can only be present
                // in right subarray
                else
                    l = mid + 2;
            }

            // We reach here when element is
            // not present in array
            return -1;
        }

        public int FindTheOddAppearingElement(int[] arr) // Type 3 problems on Binary Search ( uses index for search space approach)
        {
            //##ans will always be on even index for this type of qn.
            int s = 0, e = arr.Length - 1;
            while(s<=e)
            {
                if(s==e)//only one element
                    return arr[s];
                int mid = s+(e-s)/2;                
                if(mid%2==0)//even mid
                {
                    if (arr[mid] == arr[mid + 1])//(x,x) with x on even,x on odd => on left so do right search  
                    {
                        s = mid + 2;// here mid+1 is already checked so +2
                    }
                    else//on right so do left search
                        e = mid; //can be on ans or something like x,y with x on odd,y on even
                }
                else//odd mid
                {
                    if (arr[mid] == arr[mid - 1])//(x,x) with x on even,x on odd =>on left so do right search
                    {
                        s = mid + 1;
                    }
                    else//on right so do left search
                        e = mid - 1; // can't be on ans as ans is always on even index, so on something like (x,y) with x on even,y on odd and mid on y.
                }
                if (arr[mid] == arr[mid+1] && mid%2==0)
                {
                    e = mid - 2;
                }
                else
                {
                    s = mid + 2;
                }
            }
            return -1;
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllArraysPrograms
    {
        static void ReverseInGroups(List<long> arr, int n, int k)
        {
            for (int i = 0; i < n; i += k)
            {
                Reverse(arr, i, k);
            }
        }
        static void Reverse(List<long> arr, int start, int k)
        {
            int end = (start + k - 1) > arr.Count - 1 ? arr.Count - 1 : start + k - 1;
            while (start < end)
            {
                arr[start] = arr[start] ^ arr[end];
                arr[end] = arr[start] ^ arr[end];
                arr[start] = arr[start] ^ arr[end];
                start++;
                end--;
            }
        }
        static void Rotate(int[] arr, int k)
        {
            ReverseArr(arr, 0, k - 1);
            ReverseArr(arr, k, arr.Length - 1);
            ReverseArr(arr, 0, arr.Length - 1);
        }
        static void ReverseArr(int[] arr, int start, int end)
        {
            while (start < end)
            {
                arr[start] = arr[start] ^ arr[end];
                arr[end] = arr[start] ^ arr[end];
                arr[start] = arr[start] ^ arr[end];
                start++;
                end--;
            }
        }
        public static void sort012(int[] arr, int n)
        {
            int one = 0, two = n - 1, curr = 0;
            while (curr <= two)
            {
                if (arr[curr] == 0)
                {
                    swap(arr, one, curr);
                    one++;
                    curr++;
                }
                else if (arr[curr] == 1)
                {
                    curr++;
                }
                else
                {
                    swap(arr, two, curr);
                    two--;
                }

            }
        }
        private static void swap(int[] arr, int a, int b)
        {
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;

        }

        public static void sort0and1(int[] arr, int n)
        {
            // code here

            int one = n - 1, curr = 0;
            while (curr <= one)
            {
                if (arr[curr] == 0)
                {
                    curr++;
                }
                else
                {
                    swap(arr, curr, one);
                    one--;
                }
            }

        }

        public static void moveNegativeElementsInEnd(int[] arr, int n)
        {
            // code here

            int end = n - 1, curr = 0;
            while (curr <= end)
            {
                if (arr[curr] >= 0)
                {
                    curr++;
                }
                else
                {
                    swap(arr, curr, end);
                    end--;
                }
            }

        }

        public static void moveNegativeElementsInRight(int[] arr, int n)// time:o(n)
        {
            // code here

            int end = n - 1, curr = 0;
            while (curr <= end)
            {
                if (arr[curr] < 0)
                {
                    curr++;
                }
                else
                {
                    swap(arr, curr, end);
                    end--;
                }
            }

        }

        //Function to find duplicates in an array.
        public static List<int> duplicates(long[] arr, int n)
        {
            //Your code here
            List<int> ans = new List<int>();
            for (long i = 0; i < arr.Length; i++)
            {
                long index = arr[i] % n;
                arr[index] += n;
            }
            for (long i = 0; i < arr.Length; i++)
            {
                long noOfTimesN = arr[i] / n;   
                if (noOfTimesN >= 2)
                    ans.Add((int)i);
            }
            if (ans.Count == 0)
                ans.Add(-1);
            else
                ans.Sort();
            return ans;
        }

        public static List<int> leaders(int[] a, int n)
        {
            //Your code here
            List<int> ans = new List<int>();
            int maxOnLeftTillNow = a[n - 1];
            ans.Add(a[n - 1]);
            // int[] maxOnLeft = new int[n];
            // maxOnLeft[n-1]=-1;
            // for(int i=n-2;i>=0;i--)
            // {
            //     maxOnLeft[i] = maxOnLeftTillNow;
            //     if(maxOnLeftTillNow<a[i])
            //       maxOnLeftTillNow=a[i];
            // }
            for (int i = n - 2; i >= 0; i--)
            {
                if (a[i] >= maxOnLeftTillNow)
                {
                    ans.Add(a[i]);
                    maxOnLeftTillNow = a[i];
                }
            }
            int l = 0, r = ans.Count-1;
            while (l < r)
            {
                ans[l] = ans[l] ^ ans[r];
                ans[r] = ans[l] ^ ans[r];
                ans[l] = ans[l] ^ ans[r];
                l++;
                r--;
            }
            return ans;
        }
    }
 }

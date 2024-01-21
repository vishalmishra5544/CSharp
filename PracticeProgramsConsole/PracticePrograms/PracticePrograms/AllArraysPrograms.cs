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
    }
 }

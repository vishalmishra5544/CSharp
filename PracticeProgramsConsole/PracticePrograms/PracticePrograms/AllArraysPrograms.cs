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
    }
}

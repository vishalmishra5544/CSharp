using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllSortingPrograms
    {
        public static Node insertionSort(Node head)
        {
            // Create a dummy node to represent the sorted part of the list
            Node dummy = new Node(-1);
            Node temp = null;
            Node prev = null;

            // Iterate through the original linked list
            while (head != null)
            {
                // Reset temp and prev pointers for each iteration
                temp = dummy;
                prev = null;

                // Find the correct position in the sorted part of the list
                while (temp != null && head.data > temp.data)
                {
                    prev = temp;
                    temp = temp.next;
                }

                // Insert the current node into the sorted part of the list
                prev.next = head;
                head = head.next;
                prev.next.next = temp;
            }

            // Return the sorted linked list starting from the next of the dummy node
            return dummy.next;
        }
        int[] sortArr(int[] arr, int n)
        {
            // code here
            MergeSort(arr, 0, n - 1);
            return arr;
        }
        private void MergeSort(int[] arr, int p, int q)
        {
            if (p >= q)
                return;

            int mid = p + (q - p) / 2;
            MergeSort(arr, p, mid);
            MergeSort(arr, mid + 1, q);
            Merge(arr, p, mid, q);
        }
        private void Merge(int[] arr, int p, int mid, int q)
        {
            int n1 = mid - p + 1;
            int n2 = q - (mid + 1) + 1;
            int[] arr1 = new int[n1];
            int[] arr2 = new int[n2];
            for (int a1 = 0; a1 < n1; a1++)
                arr1[a1] = arr[a1 + p];
            for (int a2 = 0; a2 < n2; a2++)
                arr2[a2] = arr[a2 + mid + 1];
            int i = 0, j = 0, k = p;
            while (i < n1 && j < n2)
            {
                if (arr1[i] <= arr2[j])
                    arr[k++] = arr1[i++];
                else
                    arr[k++] = arr2[j++];
            }
            while (i < n1)
            {
                arr[k++] = arr1[i++];
            }
            while (j < n2)
            {
                arr[k++] = arr2[j++];
            }
        }
    }
}

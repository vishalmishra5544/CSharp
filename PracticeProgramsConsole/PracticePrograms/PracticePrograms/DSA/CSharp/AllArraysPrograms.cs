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

        public static List<int> commonElements(int[] A, int[] B, int[] C, int n1, int n2, int n3)
        {
            //Your code here
            /*List<int> ans = new List<int>();
            int i=0,j=0,k=0,maxi;
            HashSet<int> uniqueNumbers = new HashSet<int>();
            while(i<n1 && j<n2 && k<n3)
            {
                maxi = Max(A[i],Max(B[j],C[k]));
                while(i<n1 &&A[i]<maxi)
                {
                    i++;
                }
                while(j<n2 && B[j]<maxi)
                {
                    j++;
                }
                while(k<n3 && C[k]<maxi)
                {
                    k++;
                }
                if(i<n1 && j<n2 && k<n3 && A[i]==B[j] && B[j]==C[k])
                {
                    uniqueNumbers.Add(A[i]);
                    i++;
                    j++;
                    k++;
                }
            }
            foreach(var ele in uniqueNumbers)
            {
                ans.Add(ele);
            }
            return ans;*/

            List<int> ans = new List<int>();
            int i = 0, j = 0, k = 0, maxi;
            int lastAdded = int.MinValue;
            while (i < n1 && j < n2 && k < n3)
            {
                maxi = Max(A[i], Max(B[j], C[k]));
                while (i < n1 && A[i] < maxi)
                {
                    i++;
                }
                while (j < n2 && B[j] < maxi)
                {
                    j++;
                }
                while (k < n3 && C[k] < maxi)
                {
                    k++;
                }
                if (i < n1 && j < n2 && k < n3 && A[i] == B[j] && B[j] == C[k])
                {
                    if (lastAdded != A[i])
                    {
                        ans.Add(A[i]);
                        lastAdded = A[i];
                    }
                    i++;
                    j++;
                    k++;
                }
            }
            return ans;
        }
        private static int Max(int a, int b)
        {
            return a > b ? a : b;
        }

        public static void convertToWave(int n, List<int> arr)
        {
            List<int> oddIndex = new List<int>();
            List<int> evenIndex = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    evenIndex.Add(arr[i]);
                }
                else
                    oddIndex.Add(arr[i]);
            }
            int o = 0, e = 0;
            arr.Clear();
            while (o < oddIndex.Count && e < evenIndex.Count)
            {
                arr.Add(oddIndex[o++]);
                arr.Add(evenIndex[e++]);
            }

            while (e < evenIndex.Count)
            {
                arr.Add(evenIndex[e++]);
            }
        }

        //Function to return a list of integers denoting spiral traversal of matrix.
        public static List<int> spirallyTraverse(List<List<int>> matrix, int r, int c)
        {
            List<int> ans = new List<int>();
            int top = 0, right = c - 1, down = r - 1, left = 0, i = 0, j = 0;
            while (top <= down && left <= right)
            {
                j = left;
                while (j <= right)
                {
                    ans.Add(matrix[top][j++]);
                }
                top++;
                i = top;
                while (i <= down)
                {
                    ans.Add(matrix[i++][right]);
                }
                right--;
                j = right;
                while (j >= left && top <= down)
                {
                    ans.Add(matrix[down][j--]);
                }
                //left++;
                down--;
                i = down;
                while (i >= top && left <= right)
                {
                    ans.Add(matrix[i--][left]);
                }
                left++;
            }
            return ans;
        }

        public static List<int> factorial(int N)
        {
            List<int> ans = new List<int>();
            ans.Add(1);
            int mul, carry = 0;
            for (int i = 2; i <= N; i++)
            {
                for (int j = 0; j < ans.Count; j++)
                {
                    mul = ans[j] * i + carry;
                    ans[j]=(mul % 10);
                    carry = mul / 10;
                }
                while (carry > 0)
                {
                    ans.Add(carry % 10);
                    carry /= 10;
                }
            }
            ans.Reverse();
            return ans;
        }

        public static int equilibriumPoint(long[] a, int n)
        {
            //Your code here
            if (n == 1)
                return (int)a[0];
            long[] prefixSum = new long[n];
            int ans = -1;
            prefixSum[0] = a[0];
            for (int i = 1; i < n; i++)
            {
                prefixSum[i] = prefixSum[i - 1] + a[i];
            }

            for (int i = 1; i < n - 1; i++)
            {
                if ((prefixSum[n - 1] - prefixSum[i]) == prefixSum[i - 1])
                {
                    ans = i + 1;
                    break;
                }
            }
            return ans;
        }
    }
 }

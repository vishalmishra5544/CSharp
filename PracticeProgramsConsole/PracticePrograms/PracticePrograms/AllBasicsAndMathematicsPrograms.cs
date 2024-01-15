using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllBasicsAndMathematicsPrograms
    {
        static List<long> GetMinMax(List<long> a, int n)
        {
            //return new List<long>(){a.Min(),a.Max()};
            long min = long.MaxValue, max = long.MinValue;
            foreach (var ele in a)
            {
                if (ele < min)
                    min = ele;
                if (ele > max)
                    max = ele;
            }
            return new List<long>() { min, max };
        }
        static int largest(List<int> arr, int n)
        {
            int maxi = int.MinValue;
            for (int i = 0; i < arr.Count; i++)
            {
                maxi = max(maxi, arr[i]);
            }
            return maxi;
        }
        static int max(int a, int b)
        {
            if (a >= b)
                return a;
            return b;
        }

        static int isPrime(int N)
        {
            //Your code here
            if (N == 1)
                return 0;
            if (N == 2 || N == 3)
                return 1;
            if (N % 2 == 0 || N % 3 == 0)
                return 0;
            for (int i = 5; i <= Math.Sqrt(N); i += 6)
            {
                if (N % i == 0 || N % (i + 2) == 0)
                    return 0;
            }
            return 1;
        }

        static long factorial(int N)
        {
            //code here
            if (N <= 1)
                return 1;
            return N * factorial(N - 1);
        }

        public int thirdLargest(int[] a, int n)
        {
            //Your code here
            int f = int.MinValue, s = int.MinValue, t = int.MinValue;
            for (int i = 0; i < n; i++)
            {
                if (a[i] > f)
                {
                    t = s;
                    s = f;
                    f = a[i];
                }
                else if (a[i] > s)
                {
                    t = s;
                    s = a[i];
                }
                else if (a[i] > t)
                {
                    t = a[i];
                }
            }
            return t;
        }
    }
}

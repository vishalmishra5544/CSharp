﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllDictionaryPrograms
    {
        static int BirthdayCakeCandles(List<int> candles)
        {
            SortedDictionary<int, int> dict = new SortedDictionary<int, int>();
            foreach (int ele in candles)
            {
                if (dict.ContainsKey(ele))
                {
                    dict[ele] += 1;
                }
                else
                {
                    dict.Add(ele, 1);
                }
            }
            return dict.Last().Value;
        }

        static bool Check(List<long> A, List<long> B, int N)
        {
            //Your code here    
            Dictionary<long, long> h = new Dictionary<long, long>();
            foreach (long ele in A)
            {
                if (h.ContainsKey(ele))
                {
                    h[ele] += 1;
                }
                else
                    h.Add(ele, 1);
            }
            foreach (long ele in B)
            {
                if (!h.ContainsKey(ele))
                    return false;
                h[ele] -= 1;
                if (h[ele] == 0)
                    h.Remove(ele);
            }
            return true;
        }
        static int firstElementKTime(int[] a, int n, int k)
        {
            Dictionary<int, int> d = new Dictionary<int, int>(k);
            foreach (var ele in a)
            {
                if (d.ContainsKey(ele))
                {
                    d[ele] += 1;
                }
                else
                {
                    d.Add(ele, 1);
                }
                if (d[ele] == k)
                {
                    return ele;
                }
            }
            return -1;
        }
    }
}

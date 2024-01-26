using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms.DSA.CSharp
{
    public class Item
    {
        public int value;
        public int weight;
        public Item(int v,int w)
        {
            value = v;
            weight = w;
        }
    }
    public class Comparator : IComparer<Item>
    {
        public int Compare(Item? x, Item? y)
        {
            if ((x.value / (x.weight * 1.0)) < (y.value / (y.weight * 1.0)))
                return 1;
            else
                return 0;
        }
                
    }
    internal class AllGreedyPrograms
    {
        public static double fractionalKnapsack(int W, Item[] arr, int n)
        {
            //Your code here
            Array.Sort(arr, new Comparator());
            double maxValue = 0;
            int i = 0;
            while (W>0 && i < arr.Length)
            {
                if (W - arr[i].weight>=0)
                {
                    maxValue += arr[i].value;
                    W-= arr[i].weight;
                }
                else
                {
                    maxValue += W*(arr[i].value / (arr[i].weight*1.0));
                    break;
                }
                i++;
            }
            return maxValue;
        }
    }
}

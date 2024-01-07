using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllHashSetPrograms
    {
        static int DoUnion(int[] a, int n, int[] b, int m)
        {
            HashSet<int> h = new HashSet<int>(n + m);
            foreach (int ele in a)
                h.Add(ele);
            foreach (int ele in b)
                h.Add(ele);
            return h.Count;

        }
        static string IsSubset(int[] a1, int[] a2, int n, int m)
        {
            //Your code here
            if (m > n)
            {
                return "No";
            }
            Dictionary<int, int> d = new Dictionary<int, int>(n);
            foreach (var ele in a1)
            {
                if (d.ContainsKey(ele))
                    d[ele] += 1;
                else
                    d.Add(ele, 1);
            }

            foreach (var ele in a2)
            {
                if (!d.ContainsKey(ele))
                    return "No";
                d[ele]--;
                if (d[ele] == 0)
                    d.Remove(ele);
            }
            return "Yes";
        }

    }
}

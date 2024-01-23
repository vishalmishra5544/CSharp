using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllBinarySearchTreePrograms
    {
        public int minValue(Node root)
        {
            // code here
            int ans = -1;
            MinValueHelper(root, ref ans);
            return ans;
        }
        private void MinValueHelper(Node root, ref int ans)
        {
            if (root == null)
                return;
            MinValueHelper(root.left, ref ans);
            if (ans == -1)
                ans = root.data;
        }
    }
}

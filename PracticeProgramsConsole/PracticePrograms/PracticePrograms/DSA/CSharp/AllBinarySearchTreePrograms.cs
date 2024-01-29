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
        public static bool search(Node root, int x)
        {
            // Your code here
            if (root == null)
                return false;
            if (root.data == x)
                return true;
            if (root.data > x)
                return search(root.left, x);
            else
                return search(root.right, x);

        }

        public static bool isBST(Node root)
        {
            //Your code here
            List<int> inOrderTraversal = new List<int>();
            InOrder(root, inOrderTraversal);
            for (int i = 0; i < inOrderTraversal.Count - 1; i++)
            {
                if (inOrderTraversal[i + 1] <= inOrderTraversal[i])
                    return false;
            }
            return true;
        }
        private static void InOrder(Node root, List<int> inOrderTraversal)
        {
            if (root == null)
                return;
            InOrder(root.left, inOrderTraversal);
            inOrderTraversal.Add(root.data);
            InOrder(root.right, inOrderTraversal);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllTreesPrograms
    {
        //Function to return a list containing the postOrder traversal of the tree.
        public List<int> postOrder(Node root)
        {
            //code here
            List<int> ans = new List<int>();
            HelperPostOrder(root, ans);
            return ans;
        }

        private void HelperPostOrder(Node root, List<int> ans)
        {
            if (root == null)
                return;
            HelperPostOrder(root.left, ans);
            HelperPostOrder(root.right, ans);
            ans.Add(root.data);
        }

        //Complete this function
        public int countLeaves(Node root)
        {
            //Your code here
            int ans = 0;
            HelperPreOrder(root, ref ans);
            return ans;
        }

        private void HelperPreOrder(Node root, ref int ans)
        {
            if (root == null)
                return;
            if (root.left == null && root.right == null)
                ans++;
            HelperPreOrder(root.left, ref ans);
            HelperPreOrder(root.right, ref ans);
        }

        //Function to return a list containing elements of left view of the binary tree.
        public List<int> LeftView(Node root)
        {
            //Your code here
            if (root == null)
                return new List<int>();
            List<int> leftView = new List<int>();
            Queue<Node> q = new Queue<Node>();
            q.Enqueue(root);
            while (q.Count > 0)
            {
                int size = q.Count;
                int i = 0;
                while (i < size)
                {
                    Node front = q.Dequeue();
                    if (i == 0)
                        leftView.Add(front.data);
                    if (front.left != null)
                        q.Enqueue(front.left);
                    if (front.right != null)
                        q.Enqueue(front.right);
                    i++;
                }

            }
            return leftView;
        }
    }
}

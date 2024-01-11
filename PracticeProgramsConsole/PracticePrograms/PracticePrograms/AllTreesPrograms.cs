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
    }
}

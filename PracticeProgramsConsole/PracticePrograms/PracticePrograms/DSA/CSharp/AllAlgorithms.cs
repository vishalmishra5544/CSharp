using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    class Node
    {
        public int data;
        public Node left;
        public Node right;
        public Node next;
        public Node(int x)
        {
            data = x;
            this.next = null;
            left = null;
            right = null; 
        }
    }
    internal class AllAlgorithms
    {

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    class StackUsingLinkedList
    {
        Node top;
        public void push(int x)
        {
            Node n = new Node(x);            
            n.next = top;
            top = n;
        }

        public int pop()
        {
            if (top == null)
                return -1;
            Node t = top;
            top = top.next;
            t.next = null;
            return t.data;
        }

    }
    internal class AllStackPrograms
    {
    }
}

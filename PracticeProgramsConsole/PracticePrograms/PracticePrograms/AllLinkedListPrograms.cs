using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllLinkedListPrograms
    {
        public int getCount(Node head)
        {
            //Your code here
            int count = 0;
            Node temp = head;
            while (temp != null)
            {
                count++;
                temp = temp.next;
            }
            return count;
        }
        public bool isCircular(Node head)
        {
            //Your code here
            if (head == null)
                return true;
            Node t = head;
            while (t != null && t.next != head)
            {
                if (t.next == null)
                    return false;
                t = t.next;
            }
            return true;
        }
    }
}

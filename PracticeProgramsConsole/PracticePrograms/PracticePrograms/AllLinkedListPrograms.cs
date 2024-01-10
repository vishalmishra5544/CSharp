using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllLinkedListPrograms
    {
        static Node insertAtBeginning(Node head, int x)
        {
            //Your code here
            Node newNode = new Node(x);
            newNode.next = head;
            head = newNode;
            return head;
        }

        static Node insertAtEnd(Node head, int x)
        {
            //Your code here
            Node newNode = new Node(x);
            if (head == null)
            {
                head = newNode;
                return head;
            }
            Node t = head;
            while (t != null && t.next != null)
            {
                t = t.next;
            }
            t.next = newNode;
            return head;
        }

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
        public bool IsIdentical(Node head1, Node head2)
        {
            //write your code here 
            if ((head1 == null && head2 != null) || (head2 == null && head1 != null))
                return false;
            Node h1 = head1, h2 = head2;
            while (h1 != null && h2 != null)
            {
                if (h1.data != h2.data)
                    return false;
                h1 = h1.next;
                h2 = h2.next;
            }
            if ((h1 == null && h2 != null) || (h1 != null && h2 == null))
                return false;
            return true;
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllBitManipulationPrograms
    {
        static bool IsPowerofTwo(long n)
        {
            // Your code here
            /* int noOfSetBits = 0;
             long temp = n;
             int length =(int)Math.Floor(Math.Log2(n) + 1);
             while (noOfSetBits < 2 && length > 0)
             {
                 if ((temp & 1) == 1)
                 {
                     noOfSetBits++;
                 }
                 temp = temp >> 1;
                 length--;
             }
             return noOfSetBits == 1;*/
            return (n > 0) && ((n & (n - 1)) == 0);
        }
    }
}

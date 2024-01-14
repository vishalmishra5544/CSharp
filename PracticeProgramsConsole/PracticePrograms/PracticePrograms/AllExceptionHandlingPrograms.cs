using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllExceptionHandlingPrograms
    {
        public static int Ex1()
        {
            int res = 0;
            try
            {
                int y = 0;
                res = 5/ y;
            }catch (Exception ex)
            {
                return res;
            }
            finally 
            {
             // return res; //not allowed in c#
            }
            return res;
        }
    }
}

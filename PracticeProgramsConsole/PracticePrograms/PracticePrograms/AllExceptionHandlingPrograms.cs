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

        public static void Ex2()
        {
            try
            {
                switch (1)
                {
                    default:
                        break;
                    case 0:
                        break;
                    case 1:
                        for(int i=0; i < 5;i++)
                        {
                            if (i == 3)
                                continue;
                        }
                        //continue; //not allowed as no loop present
                        break;
                    case '2':
                        break;
                   /* case "3":   //Not Allowed as can't directly convert from string to int.
                        break;*/
                }
            }
            catch(Exception ex)
            {

            }
            
        }
        public static void Ex3()
        {
            try
            {   //All Same precedence left to right associative.
                int a = 2;
                int b = (a++) * (a++);
                Console.WriteLine("a: "+a+" b:"+b);
                 b = (a++) * (a--);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (a--) * (a++);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (a--) * (a--);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (++a) * (++a);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (++a) * (--a);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (--a) * (++a);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (--a) * (--a);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (--a) * (a++);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (++a) * (a--);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (--a) * (a--);
                Console.WriteLine("a: " + a + " b:" + b);
                b = (++a) * (a++);
                Console.WriteLine("a: " + a + " b:" + b);
                b = ++a * a--;
                Console.WriteLine("a: " + a + " b:" + b);


                b = ~(a);
                Console.WriteLine("b : " + b);
                b = (~a);
                Console.WriteLine("b : " + b);
                b = ~a;
                Console.WriteLine("b : " + b);
            }
            catch (Exception ex)
            {

            }
        }
    }
}

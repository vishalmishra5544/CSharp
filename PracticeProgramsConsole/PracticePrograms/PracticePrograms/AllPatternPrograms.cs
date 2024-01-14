using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllPatternPrograms
    {
        public static void SolidSquare(int rowCount, int columnCount)
        {
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < columnCount; j++)
                {
                    Console.Write("* ");
                }
                Console.WriteLine();
            }
        }
        public static void HollowSquare(int rowCount, int columnCount)
        {
            for(int i=0;i<rowCount; i++)
            {
                for(int j=0;j<columnCount; j++)
                {
                    if (i == 0 || i == rowCount - 1 || j == 0 || j == columnCount - 1)
                        Console.Write("* ");
                    else
                        Console.Write("  ");
                }
                Console.WriteLine();
            }
        }
        public static void LeftUpperTriangle(int rowCount, int columnCount)
        {
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < i+1; j++)
                {
                    Console.Write("* ");                     
                }
                Console.WriteLine("  ");
            }
        }
        public static void LeftLowerTriangle(int rowCount, int columnCount)
        {
            for (int i = rowCount-1; i>=0; i--)
            {
                for (int j = i; j>=0; j--)
                {
                    Console.Write("* ");
                }
                Console.WriteLine("  ");
            }
        }

        public static void LeftPyramid(int rowCount, int columnCount)
        {
            LeftUpperTriangle(rowCount, columnCount);
            LeftLowerTriangle(rowCount, columnCount);
        }

        public static void RightUpperTriangle(int rowCount, int columnCount)
        {
            for(int i=1; i <= rowCount; i++)
            {
                for(int j=1;j<=columnCount-i;j++)
                {
                    Console.Write("  ");
                }
                for(int j=1;j<=i;j++)
                {
                    Console.Write("* ");
                }
                Console.WriteLine();
            }
        }

        public static void RightLowerTriangle(int rowCount, int columnCount)
        {
            for (int i = 1; i <= rowCount; i++)
            {
                for (int j = 1; j < i; j++)
                {
                    Console.Write("  ");
                }
                for (int j = 1; j <= columnCount - i+1; j++)
                {
                    Console.Write("* ");
                }
                
                Console.WriteLine();
            }
        }

        
    }
}

﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    internal class AllStringPrograms
    {
        static string ReverseWord(string str)
        {
            /*var charList = str.ToCharArray();
            int l = 0, r = str.Length - 1;
            while(l<r)
            {
                charList[l] = (char)((int) charList[l] ^ (int) charList[r]);
                charList[r] = (char)((int) charList[l] ^ (int) charList[r]);
                charList[l] = (char)((int) charList[l] ^ (int) charList[r]);
                l++;r--;
            }
            return new string(charList);*/
            StringBuilder rev = new StringBuilder();
            for (int i = str.Length - 1; i >= 0; i--)
                rev.Append(str[i]);
            return rev.ToString();
        }
        public int lastIndex(string s)
        {
            // Your code here
            //return s.LastIndexOf('1');
            int lastIndex = -1;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '1')
                    lastIndex = i;
            }
            return lastIndex;
        }
    }
}

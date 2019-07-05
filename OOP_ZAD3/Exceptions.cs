using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_ZAD3
{
    public class MethodException : Exception
    {
        public MethodException() : base()
        {
        }

        public MethodException(string msg) : base(msg)
        {
        }


    }
}

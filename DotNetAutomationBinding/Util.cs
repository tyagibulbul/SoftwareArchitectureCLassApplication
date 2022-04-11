using System;
using System.Runtime.InteropServices;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DotNetAutomationBinding
{
    internal class Util
    {


        public static IntPtr StringArrayToIntPtr<Char>(string[] InputStrArray) where Char : struct
        {
            int size = InputStrArray.Length;

            // build an array of pointers to string
            IntPtr[] ptrs = new IntPtr[size];

            int dim = IntPtr.Size * size;
            IntPtr rRoot = Marshal.AllocCoTaskMem(dim);

            for (int i = 0; i < size; ++i)
            {
                if (typeof(Char) == typeof(char))
                    ptrs[i] = Marshal.StringToCoTaskMemUni(InputStrArray[i]);
                else if (typeof(Char) == typeof(byte))
                    ptrs[i] = Marshal.StringToCoTaskMemAnsi(InputStrArray[i]);
                else if (typeof(Char) == typeof(IntPtr))         // assume BSTR for IntPtr param
                    ptrs[i] = Marshal.StringToBSTR(InputStrArray[i]);
            }

            // copy the array of pointers
            Marshal.Copy(ptrs, 0, rRoot, size);

            return rRoot;
        }


    }
}

using System;
using System.Runtime.InteropServices;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using DotNetAutomationBinding;

namespace DotNetLib
{
    public static class Lib
    {

        [DllImport("clrAutomationLibrary", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        static extern int PrintOutStuff(ref IntPtr inParams, ref int inParamsSize);


        private static int s_CallCount = 1;

        [StructLayout(LayoutKind.Sequential)]
        public struct LibArgs
        {
            public IntPtr Message;
            public int Number;
        }

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

        public static int Main(IntPtr arg, int argLength)
        {

            Console.WriteLine("Hello From DotNet Automation Program");

            DotNetAutomationBinding.Session theSession = DotNetAutomationBinding.Session.GetSession();

            Part part1 = theSession.MakePart("SomePart.prt");

            part1.Save();


            return 0;
        }
        public static int MainOld(IntPtr arg, int argLength)
        {
            if (argLength < System.Runtime.InteropServices.Marshal.SizeOf(typeof(LibArgs)))
            {
                return 1;
            }

            LibArgs libArgs = Marshal.PtrToStructure<LibArgs>(arg);
            Console.WriteLine($"Hello, world! from {nameof(Lib)} [count: {s_CallCount++}]");
            PrintLibArgs(libArgs);

            String[] myList = { "Software", "Arch" };

            IntPtr inputParamsRoot = StringArrayToIntPtr<byte>(myList);
            int inputParamsSize = myList.Length;

            int rc = PrintOutStuff(ref inputParamsRoot, ref inputParamsSize);

            Console.WriteLine($"Back from PrintOutStuff" + rc);

            return 0;
        }



        public delegate void CustomEntryPointDelegate(LibArgs libArgs);
        public static void CustomEntryPoint(LibArgs libArgs)
        {
            Console.WriteLine($"Hello, world! from {nameof(CustomEntryPoint)} in {nameof(Lib)}");
            PrintLibArgs(libArgs);
        }

#if NET5_0
        [UnmanagedCallersOnly]
        public static void CustomEntryPointUnmanaged(LibArgs libArgs)
        {
            CustomEntryPoint(libArgs);
        }
#endif

        private static void PrintLibArgs(LibArgs libArgs)
        {
            string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
                ? Marshal.PtrToStringUni(libArgs.Message)
                : Marshal.PtrToStringUTF8(libArgs.Message);

            Console.WriteLine($"-- message: {message}");
            Console.WriteLine($"-- number: {libArgs.Number}");
        }
    }
}
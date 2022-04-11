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


    public class Session
    {
        [DllImport("clrAutomationLibrary", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        static extern void Session_initSession();

        [DllImport("clrAutomationLibrary", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        static extern int Session_MakePart(ref IntPtr path);

        private static Session instance;


        private Session()
        {
            initSession();
        }

        public static Session GetSession()
        {
            if (instance == null)
            {
                instance = new Session();
            }
            return instance;
        }


        private void initSession()
        {
            Session_initSession();
        }

        public Part MakePart(String partFilePath)
        {
            String[] parms = { partFilePath };

            IntPtr inputParamsIntPtr = Util.StringArrayToIntPtr<byte>(parms);


            int guid = Session_MakePart(ref inputParamsIntPtr);

            return new Part(guid);
        }

}
}

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
    public class Part
    {
        [DllImport("clrAutomationLibrary", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        static extern void Part_Save(int guid);

        /// <exclude>Not to be used directly</exclude>
        public Part(int guid)
        {
            m_guid = guid;
        }

        public void Save()
        {
            Part_Save(m_guid);
        }

        private int m_guid;

    }
}

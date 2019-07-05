using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_ZAD3
{
    // Logger
    // staticki getter, staticka backup variabla za cuvanje instance loggera, privatni kostruktor
    //
    //
    public class Logger
    {
        private static Logger m_Logger = null;

        public static Logger Instance
        {
            get
            {
                if (m_Logger == null)
                {
                    m_Logger = new Logger();
                    return m_Logger;
                }
                return m_Logger;
            }
        }
        private Logger()
        {
        }

        private static string m_logFileName = "p.txt";
        public void Write(string text)
        {
            string _textfilename = string.Concat(Utils.AssemblyDirectory, m_logFileName);
            string line = text + Environment.NewLine;
            string txtLine = string.Format("{0},{1}", DateTime.Now, line);

            try
            {
                if (!File.Exists(_textfilename))
                {
                    File.Create(_textfilename).Dispose();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("ERROR: Log path not found on local disk: {0}", e.Message);
                Console.ReadKey();
            }

            using (StreamWriter writer = new StreamWriter(_textfilename, true))
            {
                writer.Write(txtLine);
                writer.Flush();
            }


            Debug.WriteLine(txtLine);
        }
    }
}

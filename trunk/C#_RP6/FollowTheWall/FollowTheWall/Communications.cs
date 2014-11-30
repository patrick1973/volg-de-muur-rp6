using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace FollowTheWall
{
    class Communications
    {
        string[] ports;
        public Communications()
        {
            this.ports = SerialPort.GetPortNames();
        }

        public String[] getComPorts()
        {
            string[] ports = SerialPort.GetPortNames();
            return ports;
        }

        public string readSerialData(SerialPort port, string begin, string end)
        {
            string message = "";
            if (port.IsOpen)
            {
                //message = port.ReadExisting();
                message = port.ReadLine();
                return getStringBetween(message, begin, end);
            }
            else
                return null;
        }
        public string getStringBetween(string strSource, string strStart, string strEnd)
        {
            int Start, End;
            if (strSource.Contains(strStart) && strSource.Contains(strEnd))
            {
                Start = strSource.IndexOf(strStart, 0) + strStart.Length;
                End = strSource.IndexOf(strEnd, Start);
                return strSource.Substring(Start, End - Start);
            }
            else
            {
                return "No valid Data";
            }
        }
        public List<string> collect(string receivedData)
        {
            string test = "";
            if (!receivedData.Equals(null))
            {
                List<String> receivedElements = new List<string>();
                for (int i = 0; i < receivedData.Length; i++)
                {
                    test = test + receivedData[i];
                    if (receivedData[i] == ',')
                    {
                        test = test.Remove(test.Length - 1);
                        receivedElements.Add(test);
                        test = null;
                    }
                }
                return receivedElements;
            }
            return null;
        }
    }
}

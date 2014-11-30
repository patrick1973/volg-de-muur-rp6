using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;

namespace FollowTheWall
{
    public partial class Form1 : Form
    {
        Communications comms = new Communications();
        List<String> Eventvalues = new List<string>();
        String temp = "";

        public Form1()
        {
            InitializeComponent();
            this.toolStripCBbaudrate.SelectedItem = "38400";
            this.toolStripCbPorts.SelectedItem = "com8";
            this.toolStripStatusConnection.BackColor = Color.Red;
            this.toolStripStatusConnection.Text = "Dis-connected";
            tmUpdateLB.Enabled = true;

            getComPorts(comms.getComPorts());
            serialPortRP6.ReadBufferSize = 100;


            serialPortRP6.DataReceived += serialPortRP6_DataReceived;
        }

        void serialPortRP6_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int charTeller = 0;

            SerialPort sp = (SerialPort)sender;

            temp = comms.readSerialData(sp, "$", "#");


            Eventvalues.Add(temp);

            foreach (char item in temp)
            {
                if (item.Equals(','))
                {
                    charTeller++;
                }
            }
            if (charTeller == 8)
            {
                Eventvalues = comms.collect(temp);
            }
            sp.DiscardInBuffer();
        }

        private void getComPorts(string[] availPorts)
        {
            string[] ports = SerialPort.GetPortNames();
            foreach (string port in availPorts)
            {
                this.toolStripCbPorts.Items.Add(port);
            }
        }
        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
            serialPortRP6.Close();
        }

        private void connectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (!serialPortRP6.IsOpen)
                {
                    serialPortRP6.Open();
                    if (serialPortRP6.IsOpen)
                    {
                        this.toolStripStatusConnection.Text = "Connected";
                        this.toolStripStatusConnection.BackColor = Color.Green;
                    }
                }
            }
            catch (System.IO.IOException ex)
            {
                MessageBox.Show("Problems with openning the com port : " + ex.ToString(), "Error");
            }
            catch (InvalidOperationException ex)
            {

                MessageBox.Show("Problems with openning the com port " + ex.ToString(), "Error");
            }
            catch (UnauthorizedAccessException ex)
            {
                MessageBox.Show("Comport already in use " + ex.ToString(), "Error");
            }
        }

        private void disconnectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (serialPortRP6.IsOpen)
            {
                try
                {
                    serialPortRP6.Close();
                    this.toolStripStatusConnection.BackColor = Color.Red;
                    this.toolStripStatusConnection.Text = "Dis-connected";
                }
                catch (System.IO.IOException)
                {

                    MessageBox.Show("Problems with closing the com port ", "Error");
                }
                catch (InvalidOperationException ex)
                {

                    MessageBox.Show("Problems with closing the com port " + ex.ToString(), "Error");
                }
            }
        }

        private void toolStripCBbaudrate_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (!serialPortRP6.IsOpen)
            {
                try
                {
                    serialPortRP6.BaudRate = Convert.ToInt32(this.toolStripCBbaudrate.SelectedItem);
                    this.toolStripStatusBaudRate.Text = this.toolStripCBbaudrate.SelectedItem.ToString();
                }
                catch (InvalidOperationException ex)
                {
                    MessageBox.Show("select a comm port " + ex.ToString(), "Error");
                }
            }
        }

        private void toolStripCbPorts_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (!serialPortRP6.IsOpen)
            {
                try
                {
                    serialPortRP6.PortName = this.toolStripCbPorts.SelectedItem.ToString();
                    this.toolStripStatusCommport.Text = this.toolStripCbPorts.SelectedItem.ToString();
                }
                catch (Exception)
                {

                    throw;
                }
            }
        }

        private void tmUpdateLB_Tick(object sender, EventArgs e)
        {

            this.chart1.Series["IrValueLeftFront"].Enabled =    this.cbLeftFront.Checked    ? true : false;
            this.chart1.Series["IrValueRightFront"].Enabled =   this.cbRightFront.Checked   ? true : false;
            this.chart1.Series["IrValueLeftRear"].Enabled =     this.cbLeftRear.Checked     ? true : false;
            this.chart1.Series["IrValueRightRear"].Enabled =    this.cbRightRear.Checked    ? true : false;
            this.chart1.Series["DifferenceLeft"].Enabled =      this.cbDiffRight.Checked    ? true : false;
            this.chart1.Series["DifferenceRight"].Enabled =     this.cbDiffLeft.Checked     ? true : false;
            this.chart1.Series["BatteryLevel"].Enabled =        this.cbBatteryLevel.Checked ? true : false;

            if (Eventvalues.Count >= 5)
            {
                this.chart1.Series["IrValueLeftFront"].Points.AddY(Convert.ToDouble(Eventvalues[0]));
                this.chart1.Series["IrValueRightFront"].Points.AddY(Convert.ToDouble(Eventvalues[1]));
                this.chart1.Series["IrValueLeftRear"].Points.AddY(Convert.ToDouble(Eventvalues[2]));
                this.chart1.Series["IrValueRightRear"].Points.AddY(Convert.ToDouble(Eventvalues[3]));
                this.chart1.Series["DifferenceLeft"].Points.AddY(Convert.ToDouble(Eventvalues[4]));
                this.chart1.Series["DifferenceRight"].Points.AddY(Convert.ToDouble(Eventvalues[5]));
                this.chart1.Series["BatteryLevel"].Points.AddY(Convert.ToDouble(Eventvalues[6])/100.0);

                this.tbLeftFront.Text =         Eventvalues[0];
                this.tbRightFront.Text =        Eventvalues[1];
                this.tbLeftRear.Text =          Eventvalues[2];
                this.tbRightRear.Text =         Eventvalues[3];
                this.tbDifferenceRight.Text =   Eventvalues[4];
                this.tbDifferenceLeft.Text =    Eventvalues[5];
                
                
                double BatterryLevel = Convert.ToDouble(Eventvalues[6]);
                int tijdelijk = 3600 - Convert.ToInt16(Eventvalues[7]);
                //this.trackBar1.Value = Convert.ToInt16(Eventvalues[7]);




                this.tbBatteryValue.Text = (BatterryLevel / 100.0).ToString();
                batteryLevelAlarm((BatterryLevel/100.0),Convert.ToDouble (this.nudBatteryAlarmLevel.Value));
                Eventvalues.Clear();
                
            }
        }

        void batteryLevelAlarm(double batteryLevel, double alarmLevel)
        {
            if (batteryLevel < alarmLevel)
            {
                this.toolStripStatusAlarm.Text = "Warning battery Level is low " + batteryLevel.ToString();
                this.toolStripStatusAlarm.BackColor = Color.Red;
            }
            else
            {
                this.toolStripStatusAlarm.Text = "no alarm";
                this.toolStripStatusAlarm.BackColor = Color.Green;
            }
        }

    }
}

namespace FollowTheWall
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series8 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series9 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series10 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series11 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series12 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series13 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series14 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.serialPortRP6 = new System.IO.Ports.SerialPort(this.components);
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.connectionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.baudRateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripCBbaudrate = new System.Windows.Forms.ToolStripComboBox();
            this.commToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripCbPorts = new System.Windows.Forms.ToolStripComboBox();
            this.connectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.disconnectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusConnection = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusCommport = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusBaudRate = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusAlarm = new System.Windows.Forms.ToolStripStatusLabel();
            this.tmUpdateLB = new System.Windows.Forms.Timer(this.components);
            this.panel1 = new System.Windows.Forms.Panel();
            this.tbDifferenceRight = new System.Windows.Forms.TextBox();
            this.tbRightRear = new System.Windows.Forms.TextBox();
            this.tbLeftRear = new System.Windows.Forms.TextBox();
            this.tbRightFront = new System.Windows.Forms.TextBox();
            this.tbDifferenceLeft = new System.Windows.Forms.TextBox();
            this.tbLeftFront = new System.Windows.Forms.TextBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.cbDiffRight = new System.Windows.Forms.CheckBox();
            this.cbDiffLeft = new System.Windows.Forms.CheckBox();
            this.cbLeftFront = new System.Windows.Forms.CheckBox();
            this.cbLeftRear = new System.Windows.Forms.CheckBox();
            this.cbRightFront = new System.Windows.Forms.CheckBox();
            this.cbRightRear = new System.Windows.Forms.CheckBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.nudBatteryAlarmLevel = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cbBatteryLevel = new System.Windows.Forms.CheckBox();
            this.tbBatteryValue = new System.Windows.Forms.TextBox();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.menuStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.panel2.SuspendLayout();
            this.panel3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudBatteryAlarmLevel)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.panel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.connectionToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1507, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // connectionToolStripMenuItem
            // 
            this.connectionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.baudRateToolStripMenuItem,
            this.commToolStripMenuItem,
            this.connectToolStripMenuItem,
            this.disconnectToolStripMenuItem});
            this.connectionToolStripMenuItem.Name = "connectionToolStripMenuItem";
            this.connectionToolStripMenuItem.Size = new System.Drawing.Size(81, 20);
            this.connectionToolStripMenuItem.Text = "Connection";
            // 
            // baudRateToolStripMenuItem
            // 
            this.baudRateToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripCBbaudrate});
            this.baudRateToolStripMenuItem.Name = "baudRateToolStripMenuItem";
            this.baudRateToolStripMenuItem.Size = new System.Drawing.Size(186, 22);
            this.baudRateToolStripMenuItem.Text = "Baud Rate";
            // 
            // toolStripCBbaudrate
            // 
            this.toolStripCBbaudrate.Items.AddRange(new object[] {
            "300",
            "1200",
            "2400",
            "4800",
            "9600",
            "14400",
            "19200",
            "28800",
            "38400",
            "57600",
            "115200"});
            this.toolStripCBbaudrate.Name = "toolStripCBbaudrate";
            this.toolStripCBbaudrate.Size = new System.Drawing.Size(121, 23);
            this.toolStripCBbaudrate.Text = "Choose a baudrate";
            this.toolStripCBbaudrate.SelectedIndexChanged += new System.EventHandler(this.toolStripCBbaudrate_SelectedIndexChanged);
            // 
            // commToolStripMenuItem
            // 
            this.commToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripCbPorts});
            this.commToolStripMenuItem.Name = "commToolStripMenuItem";
            this.commToolStripMenuItem.Size = new System.Drawing.Size(186, 22);
            this.commToolStripMenuItem.Text = "Communication port";
            // 
            // toolStripCbPorts
            // 
            this.toolStripCbPorts.Name = "toolStripCbPorts";
            this.toolStripCbPorts.Size = new System.Drawing.Size(121, 23);
            this.toolStripCbPorts.SelectedIndexChanged += new System.EventHandler(this.toolStripCbPorts_SelectedIndexChanged);
            // 
            // connectToolStripMenuItem
            // 
            this.connectToolStripMenuItem.Name = "connectToolStripMenuItem";
            this.connectToolStripMenuItem.Size = new System.Drawing.Size(186, 22);
            this.connectToolStripMenuItem.Text = "Connect";
            this.connectToolStripMenuItem.Click += new System.EventHandler(this.connectToolStripMenuItem_Click);
            // 
            // disconnectToolStripMenuItem
            // 
            this.disconnectToolStripMenuItem.Name = "disconnectToolStripMenuItem";
            this.disconnectToolStripMenuItem.Size = new System.Drawing.Size(186, 22);
            this.disconnectToolStripMenuItem.Text = "Disconnect";
            this.disconnectToolStripMenuItem.Click += new System.EventHandler(this.disconnectToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusConnection,
            this.toolStripStatusCommport,
            this.toolStripStatusBaudRate,
            this.toolStripStatusAlarm});
            this.statusStrip1.Location = new System.Drawing.Point(0, 1040);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1507, 22);
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusConnection
            // 
            this.toolStripStatusConnection.Name = "toolStripStatusConnection";
            this.toolStripStatusConnection.Size = new System.Drawing.Size(0, 17);
            // 
            // toolStripStatusCommport
            // 
            this.toolStripStatusCommport.Name = "toolStripStatusCommport";
            this.toolStripStatusCommport.Size = new System.Drawing.Size(0, 17);
            // 
            // toolStripStatusBaudRate
            // 
            this.toolStripStatusBaudRate.Name = "toolStripStatusBaudRate";
            this.toolStripStatusBaudRate.Size = new System.Drawing.Size(0, 17);
            // 
            // toolStripStatusAlarm
            // 
            this.toolStripStatusAlarm.Name = "toolStripStatusAlarm";
            this.toolStripStatusAlarm.Size = new System.Drawing.Size(0, 17);
            // 
            // tmUpdateLB
            // 
            this.tmUpdateLB.Interval = 500;
            this.tmUpdateLB.Tick += new System.EventHandler(this.tmUpdateLB_Tick);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Teal;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.tbDifferenceRight);
            this.panel1.Controls.Add(this.tbRightRear);
            this.panel1.Controls.Add(this.tbLeftRear);
            this.panel1.Controls.Add(this.tbRightFront);
            this.panel1.Controls.Add(this.tbDifferenceLeft);
            this.panel1.Controls.Add(this.tbLeftFront);
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Location = new System.Drawing.Point(12, 39);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(522, 723);
            this.panel1.TabIndex = 11;
            // 
            // tbDifferenceRight
            // 
            this.tbDifferenceRight.Location = new System.Drawing.Point(458, 348);
            this.tbDifferenceRight.Name = "tbDifferenceRight";
            this.tbDifferenceRight.ReadOnly = true;
            this.tbDifferenceRight.Size = new System.Drawing.Size(57, 20);
            this.tbDifferenceRight.TabIndex = 25;
            this.tbDifferenceRight.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbRightRear
            // 
            this.tbRightRear.Location = new System.Drawing.Point(458, 598);
            this.tbRightRear.Name = "tbRightRear";
            this.tbRightRear.ReadOnly = true;
            this.tbRightRear.Size = new System.Drawing.Size(57, 20);
            this.tbRightRear.TabIndex = 24;
            this.tbRightRear.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbLeftRear
            // 
            this.tbLeftRear.Location = new System.Drawing.Point(3, 598);
            this.tbLeftRear.Name = "tbLeftRear";
            this.tbLeftRear.ReadOnly = true;
            this.tbLeftRear.Size = new System.Drawing.Size(57, 20);
            this.tbLeftRear.TabIndex = 23;
            this.tbLeftRear.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbRightFront
            // 
            this.tbRightFront.Location = new System.Drawing.Point(458, 110);
            this.tbRightFront.Name = "tbRightFront";
            this.tbRightFront.ReadOnly = true;
            this.tbRightFront.Size = new System.Drawing.Size(57, 20);
            this.tbRightFront.TabIndex = 22;
            this.tbRightFront.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbDifferenceLeft
            // 
            this.tbDifferenceLeft.Location = new System.Drawing.Point(-2, 348);
            this.tbDifferenceLeft.Name = "tbDifferenceLeft";
            this.tbDifferenceLeft.ReadOnly = true;
            this.tbDifferenceLeft.Size = new System.Drawing.Size(57, 20);
            this.tbDifferenceLeft.TabIndex = 21;
            this.tbDifferenceLeft.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbLeftFront
            // 
            this.tbLeftFront.Location = new System.Drawing.Point(-2, 110);
            this.tbLeftFront.Name = "tbLeftFront";
            this.tbLeftFront.ReadOnly = true;
            this.tbLeftFront.Size = new System.Drawing.Size(57, 20);
            this.tbLeftFront.TabIndex = 20;
            this.tbLeftFront.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::FollowTheWall.Properties.Resources.Rp6_TopView1;
            this.pictureBox1.Location = new System.Drawing.Point(61, 4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(397, 641);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 12;
            this.pictureBox1.TabStop = false;
            // 
            // chart1
            // 
            chartArea2.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.chart1.Legends.Add(legend2);
            this.chart1.Location = new System.Drawing.Point(550, 41);
            this.chart1.Name = "chart1";
            series8.ChartArea = "ChartArea1";
            series8.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series8.Color = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(64)))), ((int)(((byte)(0)))));
            series8.Legend = "Legend1";
            series8.Name = "DifferenceRight";
            series8.YAxisType = System.Windows.Forms.DataVisualization.Charting.AxisType.Secondary;
            series9.ChartArea = "ChartArea1";
            series9.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series9.Legend = "Legend1";
            series9.Name = "DifferenceLeft";
            series9.YAxisType = System.Windows.Forms.DataVisualization.Charting.AxisType.Secondary;
            series10.ChartArea = "ChartArea1";
            series10.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series10.Legend = "Legend1";
            series10.Name = "IrValueLeftFront";
            series11.ChartArea = "ChartArea1";
            series11.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series11.Legend = "Legend1";
            series11.Name = "IrValueLeftRear";
            series12.ChartArea = "ChartArea1";
            series12.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series12.Legend = "Legend1";
            series12.Name = "IrValueRightFront";
            series13.ChartArea = "ChartArea1";
            series13.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series13.Legend = "Legend1";
            series13.Name = "IrValueRightRear";
            series14.ChartArea = "ChartArea1";
            series14.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series14.Legend = "Legend1";
            series14.Name = "BatteryLevel";
            this.chart1.Series.Add(series8);
            this.chart1.Series.Add(series9);
            this.chart1.Series.Add(series10);
            this.chart1.Series.Add(series11);
            this.chart1.Series.Add(series12);
            this.chart1.Series.Add(series13);
            this.chart1.Series.Add(series14);
            this.chart1.Size = new System.Drawing.Size(954, 597);
            this.chart1.TabIndex = 12;
            this.chart1.Text = "chart1";
            // 
            // cbDiffRight
            // 
            this.cbDiffRight.AutoSize = true;
            this.cbDiffRight.Location = new System.Drawing.Point(20, 31);
            this.cbDiffRight.Name = "cbDiffRight";
            this.cbDiffRight.Size = new System.Drawing.Size(100, 17);
            this.cbDiffRight.TabIndex = 13;
            this.cbDiffRight.Text = "DifferenceRight";
            this.cbDiffRight.UseVisualStyleBackColor = true;
            // 
            // cbDiffLeft
            // 
            this.cbDiffLeft.AutoSize = true;
            this.cbDiffLeft.Location = new System.Drawing.Point(21, 55);
            this.cbDiffLeft.Name = "cbDiffLeft";
            this.cbDiffLeft.Size = new System.Drawing.Size(93, 17);
            this.cbDiffLeft.TabIndex = 14;
            this.cbDiffLeft.Text = "DifferenceLeft";
            this.cbDiffLeft.UseVisualStyleBackColor = true;
            // 
            // cbLeftFront
            // 
            this.cbLeftFront.AutoSize = true;
            this.cbLeftFront.Location = new System.Drawing.Point(160, 55);
            this.cbLeftFront.Name = "cbLeftFront";
            this.cbLeftFront.Size = new System.Drawing.Size(105, 17);
            this.cbLeftFront.TabIndex = 15;
            this.cbLeftFront.Text = "ir value Left front";
            this.cbLeftFront.UseVisualStyleBackColor = true;
            // 
            // cbLeftRear
            // 
            this.cbLeftRear.AutoSize = true;
            this.cbLeftRear.Location = new System.Drawing.Point(160, 31);
            this.cbLeftRear.Name = "cbLeftRear";
            this.cbLeftRear.Size = new System.Drawing.Size(102, 17);
            this.cbLeftRear.TabIndex = 16;
            this.cbLeftRear.Text = "ir value Left rear";
            this.cbLeftRear.UseVisualStyleBackColor = true;
            // 
            // cbRightFront
            // 
            this.cbRightFront.AutoSize = true;
            this.cbRightFront.Location = new System.Drawing.Point(306, 31);
            this.cbRightFront.Name = "cbRightFront";
            this.cbRightFront.Size = new System.Drawing.Size(112, 17);
            this.cbRightFront.TabIndex = 17;
            this.cbRightFront.Text = "ir value Right front";
            this.cbRightFront.UseVisualStyleBackColor = true;
            // 
            // cbRightRear
            // 
            this.cbRightRear.AutoSize = true;
            this.cbRightRear.Location = new System.Drawing.Point(306, 54);
            this.cbRightRear.Name = "cbRightRear";
            this.cbRightRear.Size = new System.Drawing.Size(109, 17);
            this.cbRightRear.TabIndex = 18;
            this.cbRightRear.Text = "ir value Right rear";
            this.cbRightRear.UseVisualStyleBackColor = true;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel2.Controls.Add(this.cbDiffLeft);
            this.panel2.Controls.Add(this.cbRightRear);
            this.panel2.Controls.Add(this.cbDiffRight);
            this.panel2.Controls.Add(this.cbRightFront);
            this.panel2.Controls.Add(this.cbLeftFront);
            this.panel2.Controls.Add(this.cbLeftRear);
            this.panel2.Location = new System.Drawing.Point(550, 644);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(447, 96);
            this.panel2.TabIndex = 19;
            // 
            // panel3
            // 
            this.panel3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel3.Controls.Add(this.nudBatteryAlarmLevel);
            this.panel3.Controls.Add(this.label3);
            this.panel3.Controls.Add(this.label2);
            this.panel3.Controls.Add(this.cbBatteryLevel);
            this.panel3.Controls.Add(this.tbBatteryValue);
            this.panel3.Location = new System.Drawing.Point(1029, 644);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(459, 100);
            this.panel3.TabIndex = 20;
            // 
            // nudBatteryAlarmLevel
            // 
            this.nudBatteryAlarmLevel.DecimalPlaces = 2;
            this.nudBatteryAlarmLevel.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.nudBatteryAlarmLevel.Location = new System.Drawing.Point(288, 29);
            this.nudBatteryAlarmLevel.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.nudBatteryAlarmLevel.Name = "nudBatteryAlarmLevel";
            this.nudBatteryAlarmLevel.Size = new System.Drawing.Size(97, 20);
            this.nudBatteryAlarmLevel.TabIndex = 25;
            this.nudBatteryAlarmLevel.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(285, 13);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(58, 13);
            this.label3.TabIndex = 24;
            this.label3.Text = "Alarm level";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(207, 32);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(25, 13);
            this.label2.TabIndex = 22;
            this.label2.Text = "Volt";
            // 
            // cbBatteryLevel
            // 
            this.cbBatteryLevel.AutoSize = true;
            this.cbBatteryLevel.Location = new System.Drawing.Point(3, 31);
            this.cbBatteryLevel.Name = "cbBatteryLevel";
            this.cbBatteryLevel.Size = new System.Drawing.Size(92, 17);
            this.cbBatteryLevel.TabIndex = 2;
            this.cbBatteryLevel.Text = "Battery output";
            this.cbBatteryLevel.UseVisualStyleBackColor = true;
            // 
            // tbBatteryValue
            // 
            this.tbBatteryValue.Location = new System.Drawing.Point(101, 29);
            this.tbBatteryValue.Name = "tbBatteryValue";
            this.tbBatteryValue.ReadOnly = true;
            this.tbBatteryValue.Size = new System.Drawing.Size(100, 20);
            this.tbBatteryValue.TabIndex = 1;
            this.tbBatteryValue.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(14, 12);
            this.trackBar1.Maximum = 360;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(903, 45);
            this.trackBar1.TabIndex = 22;
            this.trackBar1.TickFrequency = 10;
            this.trackBar1.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
            this.trackBar1.Value = 90;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(452, 60);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 13);
            this.label1.TabIndex = 23;
            this.label1.Text = "zuid";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(881, 60);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(36, 13);
            this.label4.TabIndex = 24;
            this.label4.Text = "Noord";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(11, 60);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(36, 13);
            this.label5.TabIndex = 25;
            this.label5.Text = "Noord";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(233, 60);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(29, 13);
            this.label6.TabIndex = 26;
            this.label6.Text = "Oost";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(667, 60);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(32, 13);
            this.label7.TabIndex = 27;
            this.label7.Text = "West";
            // 
            // panel4
            // 
            this.panel4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel4.Controls.Add(this.trackBar1);
            this.panel4.Controls.Add(this.label7);
            this.panel4.Controls.Add(this.label1);
            this.panel4.Controls.Add(this.label6);
            this.panel4.Controls.Add(this.label4);
            this.panel4.Controls.Add(this.label5);
            this.panel4.Location = new System.Drawing.Point(550, 765);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(938, 77);
            this.panel4.TabIndex = 28;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1507, 1062);
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.panel3);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.chart1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "RP6 following the wall";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudBatteryAlarmLevel)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPortRP6;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem connectionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem connectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem disconnectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusConnection;
        private System.Windows.Forms.ToolStripMenuItem baudRateToolStripMenuItem;
        private System.Windows.Forms.ToolStripComboBox toolStripCBbaudrate;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusCommport;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusBaudRate;
        private System.Windows.Forms.ToolStripMenuItem commToolStripMenuItem;
        private System.Windows.Forms.ToolStripComboBox toolStripCbPorts;
        private System.Windows.Forms.Timer tmUpdateLB;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.CheckBox cbDiffRight;
        private System.Windows.Forms.CheckBox cbDiffLeft;
        private System.Windows.Forms.CheckBox cbLeftFront;
        private System.Windows.Forms.CheckBox cbLeftRear;
        private System.Windows.Forms.CheckBox cbRightFront;
        private System.Windows.Forms.CheckBox cbRightRear;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.TextBox tbDifferenceRight;
        private System.Windows.Forms.TextBox tbRightRear;
        private System.Windows.Forms.TextBox tbLeftRear;
        private System.Windows.Forms.TextBox tbRightFront;
        private System.Windows.Forms.TextBox tbDifferenceLeft;
        private System.Windows.Forms.TextBox tbLeftFront;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.TextBox tbBatteryValue;
        private System.Windows.Forms.CheckBox cbBatteryLevel;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown nudBatteryAlarmLevel;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusAlarm;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Panel panel4;
    }
}


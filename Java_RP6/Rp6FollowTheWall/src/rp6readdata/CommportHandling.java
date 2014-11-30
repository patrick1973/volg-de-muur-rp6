/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package rp6readdata;

import gnu.io.*;
import java.io.*;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author patrick.vanieperen
 */
public class CommportHandling extends Thread implements SerialPortEventListener  {
    
  
/*--------------------Data velden---------------------------------------------*/ 
     Enumeration port_list = CommPortIdentifier.getPortIdentifiers();
     SerialPort serialPort;
     CommPortIdentifier port_id;
     private final ArrayList<String> listOfPorts;
     private static final int TIME_OUT = 2000;
     private int baudRate = 9600;
     private String selectedCommport;
     private BufferedReader input;
     private OutputStream output;
     private String receivedData;
     
     private boolean fetchingData = false;
     Thread readCycle;
     int teller=0;
     
     
     
/*--------------------Constructor---------------------------------------------*/
    public CommportHandling()
    {
        listOfPorts = new ArrayList<>();
        
        checkAvailiblePorts();
        
      
    }
/*--------------------Properties----------------------------------------------*/
    /**
     * 
     * @return arrayList with availible comm ports
     */
    public ArrayList<String> getListOfPorts()
    {
        return listOfPorts;
    } 
    
    public int getBaudRate()
    {
       return baudRate;
    }

    public void setBaudRate(int baudRate)
    {
        this.baudRate = baudRate;
    }
    
    public String getSelectedCommport()
    {
        return selectedCommport;
    }

    public void setSelectedCommport(String selectedCommport)
    {
        this.selectedCommport = selectedCommport;
    }
    
    public String getReceivedData()
    {
        return receivedData;
    }
    
/*--------------------Methodes------------------------------------------------*/     
 private void checkAvailiblePorts()
{
    while (port_list.hasMoreElements())
    {
        port_id = ( CommPortIdentifier) port_list.nextElement(); 
        if (port_id.getPortType() == CommPortIdentifier.PORT_SERIAL)
        {
            listOfPorts.add(port_id.getName());
        }
       }  
    } 
 
 public boolean openCommPort() throws Exception
 {
     // laat het object naar de juiste (geselecteerde poort) kijken.
     port_id = CommPortIdentifier.getPortIdentifier(selectedCommport); 
     try
     {
       // open serial port, and use class name for the appName.
       serialPort = (SerialPort)  port_id.open("Arduino Reader",TIME_OUT);
       // set port parameters
       serialPort.setSerialPortParams(baudRate, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);         
     }
     catch ( PortInUseException | UnsupportedCommOperationException ex)
     {
         return false;
     } 
     return true;
 }
 
 public void initStreams()
 {
     try
     {
        input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
        output = serialPort.getOutputStream();
        serialPort.addEventListener(this);
        serialPort.notifyOnDataAvailable(true);
     }   
     catch (IOException | TooManyListenersException ex)
     {
         Logger.getLogger(CommPort.class.getName()).log(Level.SEVERE, null, ex);
     }
             
 }
 /**
 * This should be called when you stop using the port.
 * This will prevent port locking on platforms like Linux.
 * @return 
 */ 
public synchronized boolean closeCommPort()
 {
     if (serialPort !=null)
     {
         serialPort.removeEventListener();
         serialPort.close();
         return true;
     }
     else
     {
         return false;
     }
 }
public void readData()
{
    initStreams();
    try
    {
    if (!fetchingData)
    {
        readCycle = new Thread(this);
        readCycle.start();
    }
    fetchingData = true; 
    }
    catch ( IllegalThreadStateException ex)
        {
           JOptionPane.showMessageDialog(null,"Er is iets mis gegaan met het starten van de Thread","ERROR",JOptionPane.ERROR_MESSAGE);
        }
}

    @Override
    public void serialEvent(SerialPortEvent spe)
    {
        if (spe.getEventType() == SerialPortEvent.DATA_AVAILABLE) 
        {
            
                
            try
            {
                
                receivedData = input.readLine();
            } 
            catch (IOException ex)
            {
               System.err.println(ex);
                
            }
                System.out.println(receivedData);
                
            
        }
        
    }
    
    @Override
    public void run() {
        try
            {
                while (!Thread.currentThread().isInterrupted() && fetchingData)
               { 
                   teller++;
                   CommportHandling.sleep(1000); 
                }
            }
            catch(InterruptedException ex)
            {
                JOptionPane.showMessageDialog(null,"Er is iets mis gegaan met Threads : " + ex.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
            }
            
    }

    

    

   
}
 

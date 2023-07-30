// Write a Java Program for TrafficLight using Applet and Multithreading. Create three circle to
// display Red, Green and Yellow light which should simulate traffic light. The switching
// between Red, Green and Yellow should take place after every 10 seconds

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class p2 extends Applet implements Runnable
{
    Thread t;
    int i=0;
    public void init()
    {
        t=new Thread(this);
        t.start();
    }
    public void paint(Graphics g)
    {
        g.setColor(Color.red);
        g.fillOval(100,100,100,100);
        g.setColor(Color.green);
        g.fillOval(100,250,100,100);
        g.setColor(Color.yellow);
        g.fillOval(100,400,100,100);
        if(i==0)
        {
            g.setColor(Color.red);
            g.fillOval(100,100,100,100);
        }
        else if(i==1)
        {
            g.setColor(Color.green);
            g.fillOval(100,250,100,100);
        }
        else if(i==2)
        {
            g.setColor(Color.yellow);
            g.fillOval(100,400,100,100);
        }
    }
    public void run()
    {
        while(true)
        {
            try
            {
                Thread.sleep(10000);
                i++;
                if(i==3)
                    i=0;
                repaint();
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
        }
    }
}
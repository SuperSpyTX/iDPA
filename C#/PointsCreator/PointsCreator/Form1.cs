using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace PointsCreator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // define variables
            int globalCount = 0;
            string format = "x[A] = B;\ny[A] = C;\n";
            int defRow = 4, startCol = -1;
            string message = textBox1.Text.Replace('\r', ' ');
            string[] lines = message.Split('\n');
            string final = "";
            if (lines[0].Length > 20)
            {
                MessageBox.Show("This is too big!");
                return;
            }
            char defChar = lines[0][(lines[0].Length / 2)];
            startCol = lines[0].Length / 2;
            final += "int startY = LOL;\n".Replace("LOL", startCol.ToString());

            for (int l = 0; l < lines.Length; l++)
            {
                string lmsg = lines[l];
                for (int i = 0; i < lmsg.Length; i++)
                {
                    char g = lmsg[i];
                    if (g == defChar && (l == 0 ? (i != startCol) : true))
                    {
                        int b = (l), c = (i - startCol); // OUR DIFF!
                        
                        final += format.Replace("A", globalCount.ToString()).Replace("B", b.ToString()).Replace("C", c.ToString());
                        globalCount++;
                    }
                }
            }
            textBox2.Text = final;
        }
    }
}

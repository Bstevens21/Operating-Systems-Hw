using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace AutoBelay
{
    class Program
    {
        static readonly object _carabiner = new object();

        public static void ClimbRoute()
        {
            string numClimber = Thread.CurrentThread.Name;
            Random rnd = new Random();
            int curRnd = rnd.Next(1, 5);

            Monitor.Enter(_carabiner);
            Console.WriteLine("Climber " + numClimber + " locked the caribiner to their belay loop");
            try
            {
                  
                    Console.Write("Climber " + numClimber + " is using the autobelay\n");
                    Thread.Sleep(curRnd);
            }
            finally
            {
                Console.WriteLine("Climber " + numClimber + " is finsihed with the autobelay after " + curRnd + " minutes\n");
                Monitor.Exit(_carabiner);
                Console.WriteLine("Climber " + numClimber + " ");
            }
        }

        static void Main(string[] args)
        {
            Thread[] Climbers = new Thread[5];
            for (int i = 1; i < 5; i++)
            {
                Climbers[i] = new Thread(new ThreadStart(ClimbRoute));
                Climbers[i].Name = i.ToString();
                Climbers[i].Start();
            }
            //foreach (Thread c in Climbers)
            //    c.Start();

            Console.ReadLine();
        }
    }
}
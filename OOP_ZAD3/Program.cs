using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_ZAD3
{
    class Program
    {
        static void Main(string[] args)
        {
            IStore store = new Store();

            store.UnosOtkupnogMesta("Zvecan");
            

            Console.WriteLine("Bilo koji taster za izlaz...");
            Console.ReadLine();


         

        }
    }
}

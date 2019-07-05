using System;
using System.Collections;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Orquesta orquesta1 = new Orquesta("Orquesta uno","varela","Sinfonica");
            //orquesta1.ImprimirOrquesta();
            Orquesta orquesta2 = new Orquesta("Orquesta dos","Avellaneda","Camara");
            orquesta2.ImprimirOrquesta();
            Instrumento instrumento1 = new Instrumento("piano", " madera");
           // instrumento1.ImprimirInstrumento();
            Musico musico1 = new Musico("Matias", "Moll", 22, orquesta2, instrumento1);
            musico1.ImprimirMusico();
            Console.ReadKey();

            ArrayList listaOrquesta = new ArrayList();
            listaOrquesta.Add(orquesta1);
            listaOrquesta.Add(orquesta2);

            foreach(Orquesta elemento in listaOrquesta)
            {
                elemento.ImprimirOrquesta();
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Orquesta
    {
        public string nombre;
        public string lugar;
        public string tipoOrquesta;

      
        public void ImprimirOrquesta()
        {
            Console.WriteLine("Nombre {0}, lugar {1}, Tipo {2}",this.nombre,this.lugar,this.tipoOrquesta);
            Console.ReadLine();
        }
        public Orquesta(string nombre, string lugar, string tipo)
        {
            this.nombre = nombre;
            this.lugar = lugar;
            this.tipoOrquesta = tipo;
        }
        
    }
}

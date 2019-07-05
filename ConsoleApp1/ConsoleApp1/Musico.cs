using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Musico
    {
        public string nombre;
        public string apellido;
        public int edad;
        public Orquesta orquesta;
        public Instrumento instrumento;

        public Musico(string nombre, string apellido, int edad, Orquesta orquesta, Instrumento instrumento)
        {
            this.nombre = nombre;
            this.apellido = apellido;
            this.edad = edad;
            this.orquesta = orquesta;
            this.instrumento = instrumento;
        }
        public void ImprimirMusico()
        {
            Console.WriteLine("Nombre del musico {0}, Apellido Musico {1}, Edad {2}, Nombre Orquesta {3}, Nombre instrumento {4}", this.nombre, this.apellido, this.edad, this.orquesta.nombre, this.instrumento.nombre);
            Console.ReadLine();
        }
        

    }
}

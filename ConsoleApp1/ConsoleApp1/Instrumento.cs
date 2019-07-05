using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Instrumento
    {
        public string nombre;
        public string tipoInstrumento;

    
    public Instrumento(string nombre, string tipoInstrumento)
    {
        this.nombre = nombre;
        this.tipoInstrumento = tipoInstrumento;

    }
    public void ImprimirInstrumento()
    {
        Console.WriteLine("nombre {0}, tipoInstrumento {1}", this.nombre, this.tipoInstrumento);
        Console.ReadLine();
    }

}
}

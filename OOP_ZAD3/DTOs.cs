using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_ZAD3
{
    public class BaseDTO
    {
        public int ID;

        //public virtual string ToString()
        //{
        //    throw new MethodException("Must implement this in subclassed DTO");
        //}
    }

    public class HladnjacaDTO : BaseDTO
    {

    }

    // Okupljivac ili proizvodjac
    public class OtkupljivacDTO : BaseDTO
    {
        public string Ime;
        public string Prezime;
        public string MatBr;
        public OtkupnoMestoDTO OtkupnoMesto; // Mesto kome pripada
        public List<int> ZaduzenjeAmbalaze;
    }

    public class OtkupnoMestoDTO : BaseDTO
    {
        public string Ime;
        public OtkupljivacDTO Otkupljivac;

        public override string ToString()
        {
            string strRes = String.Concat(ID, this.GetType());

            return strRes;
        }
    }

    public class VoceDTO : BaseDTO
    {
    }

    public enum Klasa
    {
    }

    public class Document
    {
        public int KolicinaPredatogVoca;
        public Klasa KlasaVoca;
        public int KolicinaZaduzeneAmblaze;
        public int KolicinaVraceneAmbalaze;
    }
}

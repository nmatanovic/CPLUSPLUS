using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_ZAD3
{
 

    public interface IStoreDocuments
    {


    }



    public class DocumentStore : IStoreDocuments
    {
        Dictionary<int, BaseDTO> m_InernalData = new Dictionary<int, BaseDTO>();

        int m_LastID = 0;
        // Return ID of last added object
        public int LastID()
        {
            return m_LastID;
        }

        
        public int IncrementLastID()
        {
            int prevValue = m_LastID;
            m_LastID++;
            return prevValue;
        }

    }


    // Zahtev 9.
    public interface IStore
    {
        int UnosOtkupnogMesta(string Naziv);
        void UnosProizvodjaca();
        void UnosVoca();
        void UnosZaduzenjaAmbalaze();
        void UnosOtkupaVoca();
        void PregledOtkupaVoca();
        void PregledSaldaZaOtkupnoMesto();
    }


    public class Store : IStore
    {
        Dictionary<int, BaseDTO> m_InernalData = new Dictionary<int, BaseDTO>();

        int m_LastID = 0;
        // Return ID of last added object
        public int LastID()
        {
            return m_LastID;
        }

        public int IncrementLastID()
        {
            int prevValue = m_LastID;
            m_LastID++;
            return prevValue;
        }


        public int UnosOtkupnogMesta(string Naziv)
        {
            var log = Logger.Instance;

            OtkupnoMestoDTO om = new OtkupnoMestoDTO();
            om.ID = IncrementLastID();
            om.Ime = Naziv;
            m_InernalData.Add(om.ID, om);


            log.Write("Unos otkupnog mesta");

            return om.ID;
        }

        public void UnosProizvodjaca()
        {
            var log = Logger.Instance;

            OtkupljivacDTO op = new OtkupljivacDTO();

            op.ID = m_InernalData.Count;
            m_InernalData.Add(op.ID, op);


            log.Write("Unos proizovdjaca");
        }

        public void UnosVoca()
        {

        }


        public void PregledOtkupaVoca()
        {
            throw new NotImplementedException();
        }

        public void PregledSaldaZaOtkupnoMesto()
        {
            throw new NotImplementedException();
        }

        public void UnosOtkupaVoca()
        {
            throw new NotImplementedException();
        }


        public void UnosZaduzenjaAmbalaze()
        {
            throw new NotImplementedException();
        }
    }



}

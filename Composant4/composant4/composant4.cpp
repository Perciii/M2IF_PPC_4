#include "../interfaces/composant4.h"
#include <list>

std::string hashBloc(Bloc bloc)
{
	
}
bool verifHash(Bloc bloc, std::string hashCode)
{
	
}
Bloc buildBloc(TX transaction)
{
	for (UTXO tran : transaction.UTXOs)
	{
		int i = 0;
		for (char element : hash(tran.toString()).c_str())
		{
			tran.hash[i] = element;
			i++;
		}
		if (i < 63)
			for (int j = i; j < 63; j++)
				tran.hash[j] = '0';
	}
	Bloc b = Bloc(transaction);
	
	//call composant1 pour la liste des blocs;
	//et intégrer le previous hash dedans
	std::list<Bloc> blocs = composant1Blocs();
	for (Bloc bloc : blocs)
	{
		if (bloc.num == b.num - 1)
			strcpy_s(b.previous_hash,bloc.hash);
	}
	return b;
		
}
Bloc buildBlocFull(unsigned int _nonce = 0, int _num = 0, char* _prevHash, TX _transaction, TXM _transactionMineur)
{
	Bloc b = Bloc();
	b.num = _num;
	b.nonce = _nonce;
	strcpy_s(b.previous_hash,_prevHash);
	b.tx1 = _transaction;
	b.tx0 = _transactionMineur;
	return b;
}
std::string version()
{
	return "v1.0.0";
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hash)
{
	using namespace boost::python;
	def("hash", hashBloc);
	def("vertifHash", verifHash);
	def("buildBloc", buildBloc);
	def("buildBlocFull", buildBlocFull);
	def("version", version);
}
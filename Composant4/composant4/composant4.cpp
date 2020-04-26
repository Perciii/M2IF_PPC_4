#include "../interfaces/composant4.h"

std::string hashBloc(Bloc bloc)
{
	
}
bool verifHash(Bloc bloc, std::string hashCode)
{
	
}
Bloc buildBloc(TX transaction)
{
	
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
	def("version", version);
}
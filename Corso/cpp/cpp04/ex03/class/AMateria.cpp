#include "./AMateria.hpp"

AMateria::AMateria(string const & type) : _type(type) {

}

AMateria::AMateria() {

}

AMateria::~AMateria() {

}

AMateria::AMateria(const AMateria &rhs) {
	*this = rhs;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

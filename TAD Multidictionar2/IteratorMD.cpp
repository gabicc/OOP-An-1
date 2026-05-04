#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md):
	md(_md),
	empty(),
	itChei(md.multidict.iterator()),
	itValori(empty.iterator())
{
	itChei.prim();
	if (itChei.valid()) {
		itValori = itChei.element().second->iterator();
	}
}

TElem IteratorMD::element() const{
	if (this->valid()) {
		return pair<TCheie, TValoare>(itChei.element().first, itValori.element());
	}
	else {
		throw IteratorException("Invalid element");
	}
}

bool IteratorMD::valid() const {
	return itChei.valid() && itValori.valid();
}

void IteratorMD::urmator() {
	if (!this->valid()) {
		throw IteratorException("Invalid position for the next element");
	}

	// advance the current value iterator
	itValori.urmator();

	// if values exhausted, advance keys until we find a key that has values (or until keys exhausted)
	while (!itValori.valid() && itChei.valid()) {
		itChei.urmator();
		if (itChei.valid()) {
			itValori = itChei.element().second->iterator();
		}
	}
}

void IteratorMD::prim() {
	itChei = md.multidict.iterator();
	itChei.prim();

	if (itChei.valid()) {
		itValori = itChei.element().second->iterator();
	} else {
		itValori = empty.iterator();
	}
}

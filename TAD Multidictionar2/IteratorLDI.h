#pragma once
#include <string>
#include <exception>

using namespace std;
template <typename T> class LDI;

class IteratorException: public exception {
private:
	string message;
public:
	IteratorException(string msg): message(msg) {}
	const char* what() const noexcept override { return message.c_str(); }
};

template <typename T> class IteratorLDI {
	template <typename> friend class LDI;
private:

	IteratorLDI(const LDI<T>& m): multime(&m), curent(m.head) {}

	const LDI<T>* multime;
	int curent;

public:
	void prim() {
		this->curent = this->multime->head;
	}

	void urmator() {
		if (this->valid()) {
			this->curent = this->multime->nodes[this->curent].next;
		} else {
			throw IteratorException("Invalid position for the next element");
		}
	}

	bool valid() const {
		return this->curent != -1;
	}

	T element() const {
		if (this->valid()) return this->multime->nodes[this->curent].val;
		throw IteratorException("Invalid position to return");
	}


	IteratorLDI<T>& operator=(const IteratorLDI<T>& ot) {
		if (this != &ot) {
			this->multime = ot.multime;
			this->curent = ot.curent;
		}
		return *this;
	}
};

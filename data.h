#ifndef FORMAT_H
#define FORMAT_H

class Format
{
public:
	// __ITERATORI__________
	// =====================
	typedef float * iterator;				// meglio una classe
	typedef const float * const_iterator;	// (idem)
	// =====================

	Format(unsigned int s = 0);
	Format(const Format& n);
	virtual ~Format() = 0;
	Format& operator=(const Format& n);

	virtual void fill(std::string Formatfile);	// input da file
//		(?)
//	{
//		for (int i = 0; i < y; ++i)
//			for (int j = 0; j < x; ++j)
//				file >> tmp;
//	}
	unsigned int size() const;
	unsigned int capacity() const;
	bool empty() const;
	iterator begin() const;
	iterator end() const;
	void push_back(const float& d);
	void pop_back();
	void clear();

	void reserve(unsigned int new_capacity);
	void resize(unsigned int s);

private:
	unsigned int sz;
	unsigned int cpty;
	float * buffer;
};

#endif

/*
	- Format: input da file
	- Matrix: input da file
	-ASCII: input da file
	- ASCIIart: input da file
	- Function: input da parametro del costruttore, come ad esempio SIN, COS, AND, OR, XOR, ADD, SBTRKT, ...; Formatfile autogenerato
	- VariableLength: input da file; numero arbitrario di input nella rete neurale; si potrebbe implementare con getline(, forse, e poi fare padding con un valore speciale non presente
	- Boolean: input da file; per unificare le varie rappresentazioni, come 0/1, -1/1... I due valori potrebbero essere parametri del costruttore!
*/
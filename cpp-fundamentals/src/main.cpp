// pre-processor directives
// runs before any code by a pre-processor
#include "Cat.h"
#include "Machine.h"
#include "NS.h"
#include "Pointers.h"
#include "functions.h"
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <ios>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include "sdlAPI/sdlapi.h"
#include <SDL2/SDL_filesystem.h>
#include "particle/particle_main.h"
#include <array>
#include <tuple>
#include <functional>
#include <utility>
#include <algorithm>
#include <thread>
#include <chrono>
#include "miostream.h"

using namespace std;

int non_static_global_number = 7;

// build process:
// preprocessing -> the compiler runs the preprocessor
// compilation(translation) proccess(.o) -> Compiler: converts .cpp files
// (translation unity) into .o files (machine code)
//  -> tokenizing
//  -> abstract syntax tree
//  -> after makes the tree, than it generates machine code
// linking(links all .o, including .o from libraries) and produces executable
//
//
// it is not always possible to associate a translation unity to a single cpp
// file translation unity is any cpp file that is compiled and translated to a
// object file. But a cpp file can include another cpp file in this case, there
// is only one translation unity for two cpp files, because only object file
// will be generated
//
//
// DYNAMIC LIBRARIES: code that the program finds during runtime, not during
// linking
//      -> unix: libcode.so
//      -> windows: code.dll
// STATIC LIBRAIES: code compiled into a binary file, and linked during build
//      -> unix: libcode.a
//      -> windows: code.lib
//      -> can instruct to load code from dynamic library
//
//  header files + static library file to link with + dinamic library files to
//  execute at runtime called by the static library
//
// header files are not compiled. Only when they are include via preprocessor
//  every cpp file is compiled individually into a object file ( transforms cpp
//  code into machine code) linker: links all .o files and creates a executable
//
//
//  function declaration == function prototype
//  function definition == function prototype + function body
//
//  any function can be used anywhere, even if its DEFINITION is typed in
//  another file the compiler only needs to see the DECLARATION of the function
//  in the file that is going to be used and it is going to trust that the
//  DEFINITON is declared elsewhere
//
//  now, the LINKER finds all the definitions of the functions, and matches them
//  against its declarations via the .o files
//
//  FILES have no MEANING for the c++ compiler. It is just a data source that
//  feeds the compiler to produce .o files
//
//
//  #pragma once -> header guard: prevents from multiple includes of the same
//  header file a single translation unity
//
//
//
//
//
//  Libraries:
//
//  ways to setup:
//   -> binary linking
//   -> include the source code of the library directly on the repo
//
//
//  library structure:
//   -> include directory (bunch of header files) -> symbol declarations of the pre-built binaries
//   -> lib directory: has the pre-built binaries. Has all the declations of the header files. Effectivelly, all the compiled .cpp files
//      -> dynamic library: gets linked at runtime. At the application launch, after the executable starts
//      -> static library: the library is put into your executable. It is inside the executable. This is how it is linked
//          -> static linking results in a faster application

#define CALL(y) std::cout << y << std::endl;

// external linkage
// the linker will look for the definition of this variables inside others translation units
extern int variable_from_translation_unit1;
extern int global_number;

void function() {}
int GoingToBeInherited::n_members = 0;

using namespace std;
// it is necessary to include the .h where the namespace is defined
using namespace gmcc;

using namespace sdlAPI;

void Log(const char *);

struct Anything
{
};

// recomendation: use structs for POD (plain old data). No behavior. Only
// methods that manipulates interval variables from the struct used for data
// structures that atre not too much complex. No inheritance
struct Player
{
	int x;
	int y;
	int speed;

	void Move(int x, int y)
	{
		this->x += x * speed;
		this->y += y * speed;
	}
};

class Player_Class
{
public:
	int x, y, speed;
	void Move(int x, int y)
	{
		this->x += x * speed;
		this->y += y * speed;
	}
};

struct Entity
{
	int x, y;

	// static members are shared across all the instances of a class/struct
	// it points to the same memory address regardless the instance
	static int s_member;
	void print() { std::cout << x << ", " << y << std::endl; }

	// returns always the same reference
	static Entity *s_get_entity()
	{
		static Entity *ent = new Entity();
		return ent;
	}
};

int Entity::s_member = 10;

int main()
{
	/* Log("hello world"); */
	// sdlAPI::run();
	//gmcc::run();
	/* preprocessor_statements(); */
	/* CALL(5); */
	// a not valid pointer. It is fine. It has the memory address of 0. It is either
	// not possible to read from or write to points to nowhere, and has no value
	//
	//
	// types for pointers are kind of meaningless, if you do not need to write to
	// the memory via the pointer
	/* int var = 8; */
	/* void* ptr = &var; */

	// pointer to the beggining of the block of memory
#ifndef CHURROS
	/* std::cout << "Churros not defined" << std::endl; */
#endif
	char *buffer = new char[9];
	int i = 0;
	memset(buffer, 'B', 9);
	//*ptr = 10;  error here

	// pointer to a pointer (double pointer)
	/* char** ptr_to_char_ptr = &buffer; */

	/* std::cout << &buffer << std::endl; */
	/* std::cout << *ptr_to_char_ptr << std::endl; */
	/* delete[] buffer; */

	// a reference to a value has the same memory address as the value
	// it is an alias
	/* int a = 10; */
	/* int* ptr_a = &a; */
	/* int& b = a; */
	/* b = 20; */
	/* std::cout << &b << " " << &a << std::endl; */

	// deferrencing a pointer returns a reference to the memory address that it
	// refers to
	/* receive_reference(*ptr_a); */
	/* std::cout << a << std::endl; */
	/**/
	/**/
	/* Player player = {0, 2, 4}; */
	/* Player_Class player_class = {5, 5, 2}; */
	/* Entity e1= {5, 8}; */
	/* Entity e2= {10, 12}; */
	/**/
	/* std::cout << variable_from_translation_unit1 << std::endl; */
	/* e1.print(); */
	/* e2.print(); */
	/* std::cout << &e1.s_member << std::endl; */
	/* std::cout << &e2.s_member << std::endl; */
	/* std::cout << &Entity::s_member << std::endl; */
	/* std::cout << e1.s_get_entity() << std::endl; */
	/* std::cout << e2.s_get_entity() << std::endl; */
	/* virtual_funcs(); */
	/* interfaces(); */
	/* Pointers::constness(); */
	/* heap_stack(); */
	/* operator_overloading(); */
	/* smart_pointers(); */
	/* smart_pointers(); */
	/* copy(); */
	/* vectors(); */
	// local_static();
	// multiple_returns();
	//  cherno_arrays();
	// cherno_strings();
	// templates();
	// stack_vs_heap();
	// macros();
	//std::cout << non_static_global_number << std::endl;
	//auto_keyword();
	//std_array();
	//function_pointers();
	//lambdas();
	//namespace_std();
	//reverse_string();
	//Namespaces::namespaces();
	//threads();
	//timing();
	//multidimensional_arrays();
	//sorting();
	//type_punning();
	//unions();
	//virtual_destructors();
	//casting();
	//precompiled_headers();
	//dynamic_casting();
	structured_bindings();
	cin.get();
	return 0;
}

void variables()
{
	/*
	endl: new line(\n) in the output stream buffer + flushes the output stream
	buffer
	*/
	int numberX = 3;
	int numberY = 5;
	string dogFirstname = "churros ";
	string dogLastname = "augusto";
	int *pNumberX = &numberX;
	numberX += 2;

	cout << "Hello world!" << endl;
	cout << numberX + numberY << endl;
	cout << *pNumberX << endl;
	cout << dogFirstname + dogLastname << endl;
}

void inputText()
{
	cout << "Tell me your name: " << flush;
	string input1;
	string input2;
	cin >> input1;
	cin >> input2;
	cout << "Input 1: " << input1 << endl;
	cout << "Input 2: " << input2 << endl;
}

void integers()
{
	int value = 2147483647;
	long longValue = 29464836438;
	short int shortValue = 256;
	cout << sizeof(value) << endl;
	cout << sizeof(shortValue) << endl;
	cout << INT_MAX << endl;
}

void floats()
{
	float value = 76.53856385355;
	double dValue = 76.53856385355;
	cout << setprecision(20) << fixed << value << endl;
	cout << setprecision(20) << fixed << dValue << endl;
}

void booleans()
{
	bool condition1 = true;
	bool condition2 = false;
	char oneByte1 = '7';
	cout << condition1 << endl;
	cout << condition2 << endl;
	cout << "------" << endl;
	cout << (int)oneByte1 << endl;
	cout << (char)55 << endl;
}

void conditions()
{
	float vFloat = 5.5;
	float v2Float = 5.6;

	if (vFloat == v2Float)
	{
		cout << "equals" << endl;
	}
	else
	{
		cout << "not equals" << endl;
	}
	cout << setw(20) << "test" << endl;

	int value1 = 7;
	int value2 = 8;

	if ((value2 != 8 && value1 == 10) || value1 < 10)
	{
		cout << "Condition: true" << endl;
	}
	else
	{
		cout << "Condition: false" << endl;
	}
}

void whileLoops()
{
	int i = 0;
	while (i < 10)
	{
		// cout << i << " " << flush;
		i++;
	}

	int y = 0;
	int j = 0;
	do
	{
		j = ++y;
		cout << "y: " << y << " | j: " << j << endl;
	} while (y < 10);

	const string password = "hello";
	string input;

	do
	{
		cout << "Type the password > " << flush;
		cin >> input;

		if (input != password)
			cout << "Invalid password. Try again." << endl;
	} while (input != password);

	cout << "Logged in!" << endl;
}

void forLoops()
{
	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
		{
			continue;
		}
		cout << i << endl;
	}
}

void arithmetic()
{
	int nValue1 = 6 / 3;
	int nValue2 = 7.0;		// implicit cast
	int nValue3 = (int)7.0; // explicit cast
	double nValue4 = 7 / (double)2;
	int nValue5 = 7 / 3.5; // implicit cast

	cout << nValue4 << endl;
	cout << sizeof(int) << endl;

	for (int i = 1; i <= 10000; i++)
	{
		cout << "." << flush;
		if (i % 100 == 0 && i > 0)
		{
			cout << endl;
		}
	}
}

void arrays()
{
	int values[5];
	values[0] = 1;
	values[1] = 2;
	cout << values[0] << endl;
	cout << values[1] << endl;
	cout << values[2] << endl;

	// an array is a reference to the memory address of the first element
	int iValues[3] = {1, 2, 3};
	/* for (int i = 0; i < sizeof(iValues) / sizeof(typeof(iValues[0])); i++) {
	  cout << iValues[i] << endl;
	} */

	cout << &iValues << endl;
	cout << &iValues[0] << endl;
	cout << *iValues << " | " << iValues[0] << endl;
	cout << "-------" << endl;
	// each element is initialize as 0
	int valuesX[6] = {};
	cout << valuesX[3] << valuesX[5] << endl;

	string names1[] = {"churros", "shoyou"};
	string names2[3];
	string names3[2] = {};
	string names4[1] = {"churros"};
}

void multidimensionalArrays()
{
	int values[2][3] = {{1, 2, 3}, {4, 5, 6}};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << values[i][j] << endl;
		}
		cout << "-------" << endl;
	}

	int multiplicationFactor;
	cout << "Type a number to see multiplication table > " << flush;
	cin >> multiplicationFactor;

	for (int i = 0; i < 10; i++)
	{
		cout << multiplicationFactor << " x " << i + 1 << " = "
			 << multiplicationFactor * (i + 1) << endl;
	}

	// totalSize = type size * 2 * 2
	// 32 * 2 * 2
	cout << "-------" << endl;
	string names[][2] = {{"churros", "shoyou"}, {"gui", "isa"}};
	for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
	{
		for (int j = 0; j < sizeof(names[0]) / sizeof(string); j++)
		{
			cout << names[i][j] << " " << flush;
		}
		cout << endl;
	}
}

void switchCase()
{
	int value = 1;
	switch (value)
	{
	case 1:
	{
		cout << "it is 1" << endl;
		break;
	}
	case 4:
	case 5:
		cout << "it is correct" << endl;
		break;
	default:
		cout << "none of them" << endl;
	}
}

int factorial(int value)
{
	if (value == 1 || value == 0)
		return 1;

	return value * factorial(value - 1);
}

void passingValues(int valueAsValue, int &valueAsReference)
{
	cout << &valueAsValue << endl;
	cout << &valueAsReference << endl;
}

void stringStreams()
{
	int age = 32;
	string dog = "Churros";
	stringstream info;
	info << "name: " << dog << "; age: " << age << endl;
	cout << info.str() << endl;
}

void charArrays()
{
	// null string terminator
	// it is a virtual character that indicates where the strings terminates
	char words[] = "churros";
	char *pWords = words;
	for (int i = 0; i < sizeof(words); i++)
	{
		cout << i << ": " << words[i] << endl;
	}
}

void copyConstructors()
{
	Machine machine1("ryzen7700x");

	// copy constructor called implicitly
	Machine machine2 = machine1;
	cout << "--------" << endl;
	cout << "machine 1 address out of method: " << &machine1 << endl;
	cout << &machine2 << endl;
	Machine::withCopy(machine1);
	cout << "machine2 cpu: " << machine2.getCpu() << endl;
}

void newOperator()
{
	// new: allocates memory mannualy on the heap
	Machine *machine = new Machine();
	// memory allocated with new, MUST BE deallocated mannually as well
	machine->setCpu("Intel Corei9 9900");
	std::string cpu = machine->getCpu();
	cout << "cpu: " << cpu << endl;
	// dot operator has higher precedence then the star operator
	// this is why "pointerVariable.method" does not work
	// so, (*pointerVariable).method == pointerVariable->method
	cout << "cpu: " << (*machine).getCpu() << endl;
	delete machine; // in this case, call the destructor

	// pointing to nowhere
	Machine *machine2 = NULL;
	// dont call delete on null pointer. CRASH WARNING
	cout << machine2 << endl;
}

void returningObjects()
{
	Machine *machine = Machine::createWithPointer();
	machine->setCpu("ryzen7700x");
	cout << machine->getCpu() << endl;
	delete machine;
}

void allocatingMemory()
{
	int *pInt = new int;
	delete pInt;

	Machine *pMachine = new Machine[7];
	pMachine[4].setCpu("Ryzen4400x");
	cout << pMachine[4].getCpu() << endl;
	delete[] pMachine;

	char *pChar = new char[100];
	delete[] pChar;

	string name(10, 'a');
	cout << name << endl;
	cout << (char)97 << endl;
}

void show(string words[], int size)
{
	// losts the array size. Get only pointer size
	for (int i = 0; i < size; i++)
	{
		cout << words[i] << endl;
	}
}

void showViaPointer(string *words, int size)
{
	// losts the array size. Get only pointer size
	for (int i = 0; i < size; i++)
	{
		cout << words[i] << endl;
	}
}

void showViaArray(string (&words)[3])
{
	for (int i = 0; i < (sizeof(words) / sizeof(string)); i++)
	{
		cout << words[i] << endl;
	}
}

string *getArray()
{
	string *numbers = new string[3]{"one", "two", "three"};
	// new allocates memory. So, this memory is not going to be diallocated until
	// do it manually
	return numbers;
}

void arraysAndFunctions()
{
	string fruits[] = {"apple", "banana", "pineapple"};
	show(fruits, sizeof(fruits) / sizeof(string));
	cout << "-----" << endl;
	showViaPointer(fruits, sizeof(fruits) / sizeof(string));
	cout << "-----" << endl;
	showViaArray(fruits);
	cout << "-----" << endl;
	string *array = getArray();
	delete[] array;
}

void namespaces()
{
	gmcc::Cat *const pCatGmcc = new gmcc::Cat();
	gcc::Cat *const pCatGcc = new gcc::Cat();
	pCatGmcc->speak();
	pCatGcc->speak();

	cout << gcc::global_something << endl;
	delete pCatGmcc;
	delete pCatGcc;
};

void inheritance()
{
	GoingToInherit *p_rand_class = new GoingToInherit();
	p_rand_class->do_something();
}

void encapsulation()
{
	Machine *const pMachine = new Machine();
	delete pMachine;
}

void constructorInheritance()
{
	// in C++, constructors are not inherited
	// in other words: it is not possible to call a super class constructor when
	// instanciating a subclass but, in the moment of the creation of the
	// instance, c++ will automatically calls super constructors. it is also
	// possible to specify which direct super constructor to call for each
	// subclass
	//

	GoingToInherit *const p_g_inherit1 = new GoingToInherit();
	// all the constructor hierarquy is called
	std::string description = p_g_inherit1->describe();
	cout << description << endl;
	cout << "------------" << endl;
	GoingToInherit *const p_g_inherit2 = new GoingToInherit(10);
	std::string description2 = p_g_inherit2->describe();
	cout << description2 << endl;
	cout << "------------" << endl;
	// it is already deleted
	GoingToInherit *const p_g_inherit6 = new GoingToInherit(11);
	GoingToInherit *const p_g_inherit7 = new GoingToInherit();
	GoingToInherit *const p_g_inherit8 = new GoingToInherit();
	GoingToInherit *const p_g_inherit9 = new GoingToInherit();
	GoingToInherit *const p_g_inherit10 = new GoingToInherit();
	GoingToInherit *const p_g_inherit11 = new GoingToInherit();
	cout << GoingToInherit::get_n_members() << endl;
}

void bit_shifiting()
{
	// 0xFF123456
	unsigned char alpha = 0xff;
	unsigned char _red = 0x12;
	unsigned char _green = 0x34;
	unsigned char _blue = 0x56;
	unsigned int _color = alpha;

	// move 1 byte to the left
	_color <<= 8;
	_color += _red;
	_color <<= 8;
	_color += _green;
	_color <<= 8;
	_color += _blue;
	cout << setfill('0') << setw(8) << hex << _color << endl;
}

void bitwise_and()
{
	int color = 0x123456;
	unsigned char red = (color & 0xFF0000) >> 16;
	unsigned char green = (color & 0x00FF00) >> 8;
	unsigned char blue = (color & 0x0000FF);
	// &: compares each bit of both values
	// color= 000100100011010001010110
	// 0xFF = 111111110000000000000000 (mask)
	// result= 000100100000000000000000
	// 1 && 1 = 1
	// 0 && 0 = 0
	// 1 && 0 = 0

	// gets the red value
	std::cout << hex << (int)red << std::endl;
	std::cout << hex << (int)green << std::endl;
	std::cout << hex << (int)blue << std::endl;
	unsigned char red_again = color >> 16;
	std::cout << hex << (int)red << std::endl;

	// bitwise or: | (if one of them is one, so the result is one)
	// bitwise and: & (if both of them are one, so the result is one)
	// bitwise xor: & (if both are equal, so the result is 0, otherwise, is 1)
}

void preprocessor_statements()
{
#ifdef CHURROS
	const CHURROS number = 7;
	std::cout << "churros symbol representing the number " << number << std::endl;
#endif
}

void receive_pointer(void *ptr_to_int)
{
	// A pointer is just an integer that stores a memory address
	// so, the value of a pointer is a memory address
	// The pointer itself has its own memory address as well
	//
	//
	// pointers and references are basically the same thing
	// semantically speaking they are different
	std::cout << ptr_to_int << std::endl;
}

void receive_reference(int &ref_to_int)
{
	// references are sintax sugar on top of pointers
	// references needs to reference an already existing variable
	std::cout << ref_to_int << std::endl;
	std::cout << &ref_to_int << std::endl;
	ref_to_int++;
}

// enumeration: set of values
void enums()
{
	enum Example
	{
		A = 1,
		B = 2,
		C = 3,
	};

	Example a = Example::A;
}

class A
{
public:
	// generates a vtable for the function
	//
	// runtime costs:
	// -> aditional memory to vtable
	virtual int get_num() { return 1; }
};

class B : public A
{
public:
	int get_num() override { return 2; }
};

void virtual_funcs()
{

	// virtual keyword is SUPER IMPORTANT in the context of polymorphism
	// it enables sublasses to create their own implementation of a base class
	// method, in other words, to override it
	//
	// this make it possible to create an instance of a base class type via a
	// subclass type, and even so have all the behavior of the subclass
	//
	//
	// Vtable: map with all the virtual functions of a base class
	// so it is possbile to match them against the correct overwritten function at
	// runtime
	B b1;
	A *b2 = new B();
	std::cout << b1.get_num() << std::endl;
	std::cout << b2->get_num() << std::endl;
}

class Printable
{
public:
	virtual std::string get_class_name() = 0;
};

class IBaseAbstraction : public Printable
{
public:
	//"=0" makes it a PURE VIRTUAL FUNCTION, in other words, it has to be
	// implemented
	// in the subclasses, if you want to create an instance of the subclass
	// and it has to be virtual
	virtual void show_something() = 0;
};

class Abstraction_Type1 : public IBaseAbstraction
{
	void show_something() override
	{
		std::cout << "showing something" << std::endl;
	}

	std::string get_class_name() override { return "Abstraction_Type1"; }
};

class Abstraction_Type2 : public IBaseAbstraction
{
	void show_something() override
	{
		std::cout << "showing something on abs2" << std::endl;
	}

	std::string get_class_name() override { return "Abstraction_Type2"; }
};

std::string get_class_name(Printable &abs) { return abs.get_class_name(); }

// are just classes. There is no interface keyword
void interfaces()
{

	IBaseAbstraction *abs = new Abstraction_Type1();
	IBaseAbstraction *abs2 = new Abstraction_Type2();
	std::cout << get_class_name(*abs) << std::endl;
	std::cout << get_class_name(*abs2) << std::endl;
}

// creating objects in different ways

class Entity_Class
{
public:
	int x;
	std::string m_name;

	Entity_Class() : m_name("Unkown")
	{
		std::cout << "Entity created" << std::endl;
	};
	Entity_Class(const std::string &name) : m_name(name) {}
	~Entity_Class() { std::cout << "Entity destroyed" << std::endl; }

	const std::string &get_name() const { return m_name; }

	void print() const { std::cout << m_name << std::endl; }
};

int *CreateArray()
{
	int array[50];
	return array;
	// this is going to fail, because it is returning a pointer to a stack-based
	// memory allocation, whose livetime is the scope of the function. Therefore,
	// it is not possible to access after the end of the function
}

// this is a way of declaring a variable on the heap (a pointer) through a
// stack-allocated wrapper and, through the destructor of the stack-allocated
// instance, deallocate the heap-allocated member this is a unique pointer
class Scoped_ptr
{
private:
	Entity_Class *m_ptr;

public:
	Scoped_ptr(Entity_Class *e) : m_ptr(e) {}
	~Scoped_ptr()
	{
		// this destructor is key, because it is what deletes the pointer that was
		// previously allocated on the heap, via the constructor of this wrapper
		delete m_ptr;
	}
};

void heap_stack()
{

	Entity_Class *e;
	// created on the stack
	// a stack frame is created. And the variables as long as that stack frame
	// lives lifetime of the scope where it is created is the fastest way and the
	// most "managable" way
	//
	// every time you enter a scope in c++, a stack frame is created on the
	// callstack every variable, function call, object created, are gone as soon
	// as that stackframe is destroyed
	//
	// stack has less memory. So, need to be careful to alocate large objects on
	// it
	Entity_Class e1;							 // default constructor
	Entity_Class e2("churros 2");				 // default constructor
	Entity_Class e3 = Entity_Class("churros 3"); // default constructor
	{
		Entity_Class e4;
		e = &e4;
		std::cout << e4.get_name() << std::endl;
		std::cout << e->get_name() << std::endl;
		std::cout << (*e).get_name() << std::endl;
	}

	{
		Entity_Class e5;
	}

	std::cout << "----------------------" << std::endl;
	{
		// heap allocates the pointer
		// therefore, heap deallocates the pointer after the scope is gone
		Scoped_ptr e6(new Entity_Class);
	}

	// created on the heap
	// lives after the end of the scope
	// slower, but much more space
	//
	//
	// the "new" keyword makes the operational system find a contiguous block of
	// memory that is enough to store the bytes for the particular type and it
	// returns a pointer to the memory address of the beggining of the contiguous
	// block "new" takes time
	//
	// key points:
	//    -> allocate on the heap takes longer
	//    -> if something is allocated on the heap, you have to manually
	//    deallocate it if it is not deallocated, it will stay at the heap,
	//    blocking other computations to use that space
	//
	//    decide where to create an object is a matter of balance between
	//    perfomance, memory space required and object life time
	Entity_Class *e5 = new Entity_Class(); // heap allocation

	int a1 = 5;		   // on the stack
	int *a2 = new int; // on the heap

	// in this case, it is allocated 50 contiguous blocks of memory with the
	// necessary bytes for each entity given that one entity takes 40 bytes, it
	// will be necessary 200 bytes of memory and, given that a "memory unit" is 1
	// byte, so 200 memory addresses will be allocated for this array of entities

	Entity_Class *entities1 =
		new Entity_Class[50]; // on the heap. This line, calls the constructor for
	// each one
	Entity_Class *entities2 = (Entity_Class *)malloc(
		sizeof(Entity_Class)); // it is equivalent to this. But, is this case, it
	// does not call the constructor

	std::cout << "-----------------" << std::endl;
	std::cout << e1.get_name() << std::endl;
	std::cout << e2.get_name() << std::endl;
	std::cout << e3.get_name() << std::endl;
	std::cout << sizeof(entities1[0]) << std::endl;

	delete e5; // calls the destructor
	delete a2;
	delete[] entities1;
}

struct Vector2
{
	float x, y;

	Vector2(float x, float y) : x(x), y(y) {}

	Vector2 Add(const Vector2 &other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 AddV2(const Vector2 &other) const
	{
		// uses the overloaded "+" operator
		return *this + other;
	}

	Vector2 Multiply(const Vector2 &other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator+(const Vector2 &other) const { return Add(other); }

	Vector2 operator*(const Vector2 &other) const { return Multiply(other); }

	bool operator==(const Vector2 &other) { return x == other.x && y == other.y; }

	bool operator!=(const Vector2 &other) { return !(*this == other); }
};

void operator_overloading()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));
	Vector2 result2 = position + speed * powerup;
	std::cout << "result 1: x" << result1.x << " y: " << result2.y << std::endl;
	std::cout << "result 2: x" << result2.x << " y: " << result2.y << std::endl;
	std::cout << (result1 == result2) << std::endl;
	std::cout << (result1 != result2) << std::endl;
}

// it is a way of "auto manage" heap-allocation memory
// there's different kinds of smart pointers, but they are essencially wrappers
// around raw pointers
//
//
// unique pointer: scoped pointer
//  -> it can only have one reference to the created object
//  because once it's free/deleted/deallocated, it will fail
//  -> delete is called when the scope of the unique reference is gone
//  -> lower overhead
//
//  shared pointer
//   -> it can have multiple references to the created object
//   -> greater overhead
//
//  weak pointer
//   -> it does not increment the ref count
//   -> it can have multiple references to the created object
//
//
//
//
//  try to use them all the time
void smart_pointers()
{
	{
		std::shared_ptr<Entity_Class> e0;
		// this pointer only going to be deleted as soons as all the references to
		// it are gone
		{
			std::unique_ptr<Entity_Class> e1 = std::make_unique<Entity_Class>();
			e1->print();

			// based on reference counting
			// when all references to the pointer are gone, then the pointer is
			// deleted
			std::shared_ptr<Entity_Class> shared_entity =
				std::make_shared<Entity_Class>();
			e0 = shared_entity;

			// event though the scope of "shated_entity" has gone, the e0 reference is
			// still valid, because the ref count is still greater than one
		}
	}

	{
		// does not increase the ref count
		std::shared_ptr<Entity_Class> e0;
		{
			std::shared_ptr<Entity_Class> shared_entity =
				std::make_shared<Entity_Class>();
			e0 = shared_entity;
		}
	}

	int *x = new int;
	int **y = &x;
	*x = 10;
	**y = 15;
	std::cout << *x << std::endl;
}

struct _Vector2
{
	float x, y;
};

class _Vector2_c
{
	float x, y;

public:
	_Vector2_c(float x, float y) : x(x), y(y) {}
	~_Vector2_c() { std::cout << "vector destroyed" << std::endl; }
};

class String
{
	char *m_buffer;
	unsigned char m_size;

public:
	String(const char *string)
	{
		m_size = strlen(string);
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, string, m_size);
		m_buffer[m_size] = 0;
	}

	// performs a deep copy
	// copy all the object contents. Not the memory address
	// create a whole new instance of String
	// it is needed to specify the copy constructor
	String(const String &other) : m_size(other.m_size)
	{
		std::cout << "copied string" << std::endl;
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, other.m_buffer, m_size + 1);
	}

	~String() { delete[] m_buffer; }

	char &operator[](unsigned int idx) { return m_buffer[idx]; }
	friend std::ostream &operator<<(ostream &, const String &string);
};

std::ostream &operator<<(ostream &stream, const String &string)
{
	stream << string.m_buffer;
	return stream;
}

// not passing as reference, is a completelly caos
// the copy constructor is going to be called every time,
// allocating more and more memory
void print_str(const String &string) { std::cout << string << std::endl; }

void copy()
{
	int a = 5;
	int &b = a;
	b = 10;

	{
		_Vector2 v1 = {5, 7};
		_Vector2 v2 = v1; // copying the value of v1 to v2
		_Vector2 *v3 = &v1;
		v3->x = 7;
		std::cout << v1.x << std::endl;
	}

	{
		_Vector2 *v1 = new _Vector2();
		_Vector2 *v3 = v1;

		// affects both v1 and v3
		v3->x = 7;
		std::cout << v1->x << std::endl;
	}

	String dog1 = "Churros";

	// shallow copy
	String dog2 = dog1;
	dog2[2] = 'a';
	// - error: is going to copy the m_buffer pointer
	// but once dog1's "m_buffer" is freed, the dog2's m_buffer can't be freed
	// again
	print_str(dog1);
	print_str(dog2);
}

struct Vertex
{
	float x, y, z;
	Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

	Vertex(const Vertex &other) : x(other.x), y(other.y), z(other.z)
	{
		std::cout << "copied vertex" << std::endl;
	}
};

static ostream &operator<<(ostream &stream, const Vertex &vtx)
{
	stream << vtx.x << ", " << vtx.y << ", " << vtx.z;
	return stream;
}

void vectors()
{
	std::vector<Vertex> vertices;

	// optmization
	// from 6 to 0 copies
	vertices.reserve(
		3); // reserves 3 locations, and does not initialize any of them
	// this prevent copy

	// emplace back: creates the vertex in the actual vector
	vertices.emplace_back(1, 2, 3); // aggregate initializer
	// the vertex pushed is created at the stack frame of the vectors function
	// so, under the hood, it is copied into the array
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);

	// iterate as reference
	// if not, one copy is going to be created for each one in the scope of the
	// for looop
	for (const Vertex &v : vertices)
	{
		std::cout << v << std::endl;
	}

	vertices.erase(vertices.begin() + 1);
	std::cout << "---------" << std::endl;
	for (int i = 0; i < vertices.size(); i++)
	{
		std::cout << vertices[i] << std::endl;
	}

	vertices.clear();
}

static void Function()
{
	// it is going to be initialize once, only at the first call
	// on the subsequent calls, it is going to use that one initialized static variable
	//
	// it is only accessible inside the scope where it is created
	static int i = 0;
	std::cout << i << std::endl;
	i++;
};

class Singleton
{

public:
	static const Singleton &get()
	{
		// it is going to be initialize once, only at the first call of the class
		// on the subsequent calls, it is going to return that one initialized static variable
		//
		// it is only accessible inside the scope where it is created
		static const Singleton instance;
		return instance;
	}
};

void local_static()
{
	Function();
	Function();
	Function();
	Function();

	std::cout << &Singleton::get() << std::endl;
	std::cout << &Singleton::get() << std::endl;
	std::cout << &Singleton::get() << std::endl;
	std::cout << &Singleton::get() << std::endl;
}

// struct way

struct StructWay
{
	std::string string;
	int integer;
};

// return type via struct
// prefer this way
static StructWay get_struct_way()
{
	return {"churros", 5};
}

// basically, no return type. Only change the arguments passed via reference
static void via_reference(std::string &outString, int &outInteger)
{
	outString = "churros";
	outInteger = 5;
}

// basically, no return type. Only change the arguments passed via pointer
static void via_pointer(std::string *outString, int *outInteger)
{
	*outString = "churros";
	*outInteger = 5;
}

// multiple return, but the same type
static std::string *return_array()
{
	return new std::string[2]{"churros", "augusto"};
}

// multiple return types, but the same type
static std::array<std::string, 2> return_std_array()
{
	// allocated on the stack
	std::array<std::string, 2> results;
	results[0] = "churros";
	results[1] = "augusto";
	return results;
}

// multiple return, but the same type
static std::vector<std::string> return_std_vector()
{
	// allocated on the heap
	std::vector<std::string> results;
	results.push_back("churros");
	results.push_back("augusto");
	return results;
}

// return via tuple
static std::tuple<std::string, std::string, int> return_tuple()
{
	return std::make_tuple("churros", "augusto", 5);
}

void multiple_returns()
{
	int x = 0, y = 0;
	StructWay tuple = {"churros", 5};
	std::string string;
	int integer = 0;

	std::string name;
	int *z = new int;
	via_pointer(&name, z);
	std::cout << z << std::endl;

	std::string *string_array = return_array();
	std::cout << string_array[0] << std::endl;

	std::array<std::string, 2> array = return_std_array();
	std::vector<std::string> vector = return_std_vector();
	std::cout << array[1] << std::endl;
	std::cout << vector[1] << std::endl;

	auto tuple_return = return_tuple();
	std::cout << std::get<2>(tuple_return) << std::endl;
}

void cherno_arrays()
{
	// pointer type
	int numbers1[5];

	int numbers2[] = {1, 2, 3, 4, 5};
	int numbers3[5] = {1, 2, 3, 4, 5};

	int *numbers_ptr = numbers1;
	numbers1[2] = 5;
	*(numbers_ptr + 2) = 8;

	std::cout << numbers1[2] << std::endl;
}

void cherno_strings()
{
	char letter1 = 'a';
	char letter2 = 97;

	// it is imutable ( fixed allocated block of memory )
	// if it has be to extended, a whole new allocation needs to be perfomed
	const char *dog = "churros";
	const char dogx[8] = {'c', 'h', 'u', 'r', 'r', 'o', 's', '\0'};
	std::cout << dog << std::endl;
	std::cout << dogx << std::endl;

	std::string name = std::string("churros") + "augusto";
	bool contains_o = name.find("o") != std::string::npos;
	std::cout << contains_o << std::endl;
}

void print(int i)
{
	std::cout << i << std::endl;
}

void print(const char *i)
{
	std::cout << i << std::endl;
}

void print(float i)
{
	std::cout << i << std::endl;
}

// it only gets generated when it is called
// generates code based on the typename
// at compile time
template <typename T>
void TPrint(T _x)
{
	std::cout << _x << std::endl;
}

template <typename T, int N>
class Array
{
private:
	T m_array[N];

public:
	int get_size() const { return N; }
};

void templates()
{
	std::cout << "templates" << std::endl;
	int x = 9;
	float y = 9.0f;
	const char *text = "churros";

	print(x); // this triggers the creation of the typename
	print(y);
	print(text);

	std::cout << "--------" << std::endl;

	TPrint<int>(x);
	TPrint<float>(y);
	TPrint<const char *>(text);

	Array<int, 5> arr1;
	Array<float, 7> arr2;
	std::cout << sizeof(arr1) << std::endl;
	std::cout << sizeof(arr2) << std::endl;
}

/*
	stack vs heap ( both contained inside RAM, both contained inside the same physical memory location)

	when a program boots, a physical amount of ram is reserved to run the program

	-> exists to store and output data
	-> they diff in variable lifecycles and the way the memory is allocated

	stack: pre defined size
		-> every defined variable, is stored on top of each other
		-> the stack pointer just move the necessary amount of bytes to store the next variable, and its address is returned
		-> the allocation is extremally fast
		-> the deallocation is also fast, given that it is the same operation as the allocation,
		but it only moves the stack pointer backwards
		-> one cpu instruction

	heap: it can grow
		-> "new" keyword: heap allocate memory
		-> it is not allocated stacklly
		-> it has to be deallocated mannually with the "delete" keyword ( heavy as well )
		-> freelist: keeps track of which blocks of memory are free to dynamic allocation ( heap memory )
		-> the new keyword checks the freelist via the malloc function and looks for a block of memory that is big enough to store the data
		-> returns a pointer to the beggining of the block
		-> malloc is a heavy function. It is much more slower than allocating on the stack
		-> it is a WHOLE THING. It is pretty more complex than allocate on the stack. More overhead.

	the perfomance difference is the allocation
 */

void stack_vs_heap()
{
	int value = 5;
	int arr[5];
	for (int i = 0; i <= 4; i++)
	{
		arr[i] = i * 2;
	}

	int *x = new int(5); // calls malloc
	delete x;
}

// MACROS
// preprocessor statement

#define DOG "churros"
#define INPUT cin.get()
#define OPEN_CURLY {
#define show(message) std::cout << message << std::endl;
// the symbol DOG is replaced by "churros" every where it is used

class Interface
{
public:
	virtual void show_something(std::string something) = 0;
};

class Impl : public Interface
{
public:
	void show_something(std::string something) override
	{
		std::cout << something << std::endl;
	}
};

struct Equals_Overloading
{
	float x, y, z;
};

// conditional code generation
// it is awsome to filter which code should be include at compilation process
#if DEBUG == 1
#define env "DEBUG"
#else
#define env "RELEASE"
#endif

// multiline macro
#define whole_macro                         \
	void print_message(std::string message) \
	{                                       \
		std::cout << message << std::endl;  \
	}

	whole_macro

	void
	macros()
		OPEN_CURLY
	std::cout
	<< "macros" << std::endl;
show(env);
INPUT; // it is going to replace with "cin.get()"

#ifdef TEST
std::cout << "test flag defined" << std::endl;
#endif

Impl impl;
impl.show_something("churros augusto");
print_message("Hello churros");
}

void auto_keyword()
{
	std::vector<std::string> names;
	names.push_back("churros");
	names.push_back("shoyou");

	for (std::vector<std::string>::iterator it = names.begin();
		 it != names.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	// same with auto
	for (auto it = names.begin();
		 it != names.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

template <typename T, size_t s>
void print_array(std::array<T, s>& array)
{
	for(auto it=array.begin(); it != array.end(); ++it)
	{
		*it = 0;
		std::cout << *it << std::endl;
	}
}

// for static arrays
// just use it. Basically the same, with more features
void std_array()
{
	// stored on the stack
	std::array<int, 5> numbers;
	std::vector<std::string> names = std::vector<std::string>({ "hello" });
	print_array<int, 5>(numbers);
	std::cout << names[0] << std::endl;
};

void _ext_fn(char l)
{
	std::cout << l << std::endl;
};

void fn(std::string x) { std::cout << x << std::endl; }
void for_each(std::vector<std::string>& r_elements, void(*cb)(std::string)) 
{
	for(auto& i : r_elements) cb(i);
}

void func_i(int a) {}

void function_pointers()
{
	// with typedef, it is possible to type a anonymous function
	// to that functions can be stored inside variables with that type
	// alias for the function name
	typedef void(*_fn_type)(char);
	// the variable is actually typed with a anonymous type
	_fn_type func = _ext_fn;

	// with anonymous type
	// it is not a type. It's just a variable so to speak, that can contains others functions
	// with the same signature
	void(*_fn)(char);
	// there is no type
	_fn = _ext_fn;

	auto fn_auto = _ext_fn;

	_fn('x');
	func('y');
	fn_auto('z');


	std::vector<std::string> dogs = std::vector<std::string>({
		"churros", "shoyou", "gui"
	});
	for_each(dogs, fn);

	typedef void(*x_func)(int);
	x_func func_x = [](int a) {
		std::cout << a << std::endl;
	};
}

template<typename _Ty>
void operate(const _Ty e, const std::function<void(_Ty)>& cb)
{
	cb(e);
}

// it is a different way of writing a function pointer
// they are anonymous functions
void lambdas()
{
	std::vector<std::string> dogs = std::vector<std::string>({
		"churros", "shoyou", "gui"
	});

	typedef void(*function)(void);
	function x = []() { return; };
	x();
	
	for_each(dogs, [](std::string _e) {
		std::cout <<  _e << std::endl;
	});


	int a = 5;
	int b = 7;
	std::cout << "addresses outside lambda: " << std::endl;
	std::cout << "a: " << &a << std::endl;
	std::cout << "b: " << &b << std::endl;
	std::cout << "addresses inside lambda: " << std::endl;

	// []: capture
	// [=]: captures all variables by value
	// [&]: captures all variables by reference
	// (): parameters
	// {}: body
	auto lambda = [a, &b](int value) { 
		std::cout << "a: " << &a << std::endl; 
		std::cout << "b: " << &b << std::endl;	
	};
	lambda(5);


	int n = 10;
	// n is passed by reference
	// mutable: makes it possible to change variables passed by value
	operate<typeof(n)>(n, [&](typeof(n) e) mutable {
		n = 5;
		std::cout << e << std::endl;
	});


	std::array<const char*, 5> names = { "chur", "sho", "gui", "churros" };
	auto it = std::find_if(names.begin(), names.end(), [&](const char* name) -> bool { 
		return strlen(name) > 5;
	});
	std::cout << *it << std::endl;
}

namespace apple
{
	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange
{
	void print(const char* text)
	{
		std::string tmp = text;
		std::reverse(tmp.begin(), tmp.end());
		std::cout << tmp << std::endl;
	}
}

// dont use "using namespace" in header files. EVER
void namespace_std()
{
	using std::cout;
	using std::endl;

	using MY_INT = int;
	#define MY_INT2 = int;
	typedef int MY_INT3;

	orange::print("Hello world");
}

void reverse_string()
{
	using std::cout;
	using std::endl;
	char string[] = "churros\0";
	char* begin_ptr = string;
	char* end_ptr = &string[strlen(string) - 1];

	while(begin_ptr < end_ptr)
	{
		auto tmp = *begin_ptr;
		*begin_ptr = *end_ptr;
		*end_ptr = tmp;
		begin_ptr++;
		end_ptr--;
	}
	cout << string << endl;
}

// in C libraries, it is common to see symbols prepended with the library name, given that, in C, there is no namespace 

// it is not like Namespace::symbol, it is like namespace_symbol, in C
// in c++, it is like Namespace::symbol


// their primary purpose is to avoid name collisions between symbols. Only
// it makes it possible to have multiple symbols with the same name, wrapping them inside different namespaces
// warning: try to use them in small scopes

namespace image {
	// without namespace: image_load
	const char* load(const std::string& imagepath) 
	{
		return "loading resource";
	}
}

namespace audio {
	// without namespace: audio_load
	void load(const std::string& audiopath)
	{
		using std::cout; using std::endl;
		cout << "loading audio" << endl;
		return;
	}
}

namespace Namespaces {

void namespaces()
{
	// if no "using namespace x" is declared, 
	// like "using namespace image" or "using namespace audio"
	image::load("image");
	audio::load("audio");


	// using namespace::symbol
	using image::load;
	load("imagepath");

	// namespace alias
	// useful for nested namespaces
	namespace standard = std;

	
}

}

static bool s_finished = false;
// paralallesism
void threads()
{
	using namespace std::literals::chrono_literals;
	// imediatelly invokes a callable(routine) in another thread of execution
	// and the current thread continues running
	std::cout << "started thread id=" << std::this_thread::get_id() << "\n";
	std::thread worker([]() {
		while(!s_finished)
		{
			// risk of 100% cpu usage for the thread
			std::cout << "worker working...\n";

			// sleeps the current thread for a specif time
			std::this_thread::sleep_for(1s);
			std::cout << "started thread id=" << std::this_thread::get_id() << "\n";
		}
	});

	// this line blocks the current thread, which is the main thread, until press enter
	// while the above defined thread is running
	std::cin.get();

	// this line makes the callable return, since it will change the state of the variable that the callable rely on
	s_finished = true;

	// wait for the thread to complete
	// instruction to block the current thread, and then wait for this other thread to complete its job
	// blocks the main thread, and waits for the "worker" thread finish
	worker.join();

	// there is the main thread
	// -> worker thread: does its work
	// join*: stop the main thread worker, and then wait for other worker finish its own job

	// this line will not run until the "worker" thread finish, since it was joined
	std::cin.get();
}

// instrumentation: modify source code to contain profiling tools
struct Timer {
	typedef std::chrono::_V2::system_clock::time_point time;
	time _s, _e;

	Timer(const time& _t1, const time& _t2)
	{
		_s = _t1;
		_e = _t2;
	}
	// implement duration at the destructor

	inline void init() { _s = std::chrono::high_resolution_clock::now(); }
	inline void end() { _e = std::chrono::high_resolution_clock::now(); }

	template<typename _Ty>
	inline _Ty get_duration() 
	{ 
		return std::chrono::duration<_Ty>(_e - _s).count() * 1000.0f;
	}
};

void timing()
{

	using namespace std::literals::chrono_literals;
	Timer::time _start, _end;
	Timer timer(_start, _end);
	timer.init();
	for(int i=0; i<100; i++) 
		std::cout << i << "\n";

	timer.end();
	std::cout << timer.get_duration<float>() << "ms" << std::endl;
}

// buffer in the memory, that contains consecutive pointers, and each pointer points to the beginning of an array in memory
void multidimensional_arrays()
{
	int _1Da[5] = { 1, 2, 3, 4, 5 };
	int _2Da[2][5] = {
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5}
	};
	int _3Da[2][2][2] = {
		{
			{1, 2}, {1, 2}
		},
		{
			{1, 2}, {1, 2}
		}
	};

	// pointer to an integer at the first position of the array
	// allocating 50 4-bytes chunks of memory - 200 bytes allocated here
	int* array = new int[50];

	// 50 pointers to a pointer to a integer
	// each element of "a2d" is a pointer to a integer pointer
	// initially, a2d, or a2d[0] points to the first integer pointer memory location
	int** a2d = new int*[5];
	// this leads to memory fragmentation
	// arrays stored in random places in memory. Waste of perfomance when iterating over them
	// different dimensions leads to different locations in memory

	// so, single dimension array are much faster, because there's no memory fragmentation
	for(int i=0; i<5; i++)
	{ 			// this returns a pointer to a memory address, 
				// with 50 consecutive chunks of integers, which is 200 bytes
		a2d[i] = new int[5];
	}
	a2d[1][0] = 5;
	std::cout << a2d[1][0] << std::endl; // this access the first element from the first pointer to a integer from the total of 5
	std::cout << a2d[0] << std::endl; // this access the first pointer to a integer from the total of 5

	//delete[] a2d; don't do this.
	for(int i=0; i<5; i++)
		delete[] a2d[i];
	delete a2d;

	int** _2Darray = new int*[5];
	for(int i=0; i<5; i++)
		_2Darray[i] = new int[5];

	for(int y=0; y<5; y++)
	{
		for(int x=0; x<5; x++)
		{
			_2Darray[x][y] = 2;
		}
	}

	// same thing, but this is extremelly faster then a multidimensional array
	int* _1Darray = new int[5 * 5];
	for(int y=0; y<5; y++)
	{
		for(int x=0; x<5; x++)
		{
			_1Darray[y*5 + x] = 2;
		}
	}
}

void sorting()
{
	std::vector<int> ns = { 3, 5, 1, 4, 2 };
	std::sort(ns.begin(), ns.end());
	for(auto it=ns.begin(); it < ns.end(); it++)
	{
		std::cout << *it << "\n";
	}

	std::cout << "----------------" << std::endl;

	std::sort(ns.begin(), ns.end(), std::greater<int>());
	for(auto it=ns.begin(); it < ns.end(); it++)
	{
		std::cout << *it << "\n";
	}

	std::cout << "----------------" << std::endl;

	std::sort(ns.begin(), ns.end(), [](int a, int b) {
		return a < b;
	});
	for(auto it=ns.begin(); it < ns.end(); it++)
	{
		std::cout << *it << "\n";
	}

	std::cout << "----------------" << std::endl;

	std::sort(ns.begin(), ns.end(), [](int a, int b) {
		// returns true to order a before b
		// returns false to order b before a
		if(a == 1) return false;
		if(b == 1) return true;

		return a < b;
	});

	for(auto it=ns.begin(); it < ns.end(); it++)
	{
		std::cout << *it << "\n";
	}
}

struct SEntity {
	int x, y;

	// there's no memory copy here
	int* get_positions()
	{
		return &x;
	}
};

// get around the type system
// it is not casting. There is no conversion/casting in type punning 
// It is a reinterpretation of a pointer type to another pointer type
// interpret existing memory as another type ( reintepret cast )
void type_punning()
{
	// it is like, just fuck type system, i have pointer powers
	SEntity e = { 5, 8 };
	int _y_i = *((int*)&e + 1);
	int* _y_c = (int*)((char*)&e + 4);
	std::cout << _y_i << std::endl;
	std::cout << *_y_c << std::endl;

	int* positions = e.get_positions();
	std::cout << "x: " << positions[0] << ", y: " << positions[1] << std::endl;


	std::cout << "----------------" << std::endl;

	// what places a integer pointer at the beggining of the memory that holds this struct instance
	int* position = (int*)&e;


	int a = 50;
	int c = 20;
	// implicit conversion
	// convert a int pointer to a double pointer, and then derefenced it
	double b = *(double*)&a;

	std::cout << position[0] << std::endl;
	std::cout << position[1] << std::endl;
}

// 16 bytes of memory needs to be allocated
struct _16bytes {
	float x, y, a, b;
};

struct _16bytesV2 {
	float x, y, a, b;
	_16bytesV2(float x, float y, float a, float b)
		: x(x), y(y), a(a), b(b) {}
};


// this way, creates a unnamed struct, and already creates a instance of that and assigning it to "teste"
struct
{
	int a;
} teste;

// this way, creates a type named "test_type", that is representation is a struct with integer member
typedef struct
{
	int a;
} test_type;


struct __Vector2 
{
	float x, y;
};

struct Vector4
{
	union {
		struct 
		{
			float x, y, z, w;
		};
		// occupies the same space as the above struct
		struct 
		{
			__Vector2 a, b;
			// a is the same memory as x and y
			// b is the same memory as z and w
		};
	};
};


// this union is at least 32 bytes ( string size )
union test_union
{
	// x, y and s are three different members, but they represent the same memory address
	// changing the value of x, for example, will change the other values as well
	float x;
	int y;
	std::string s;
};

// it is like a class/struct type
// but it can hold only one member of its at a time
// it is very useful when you need multiple ways of addressing the same data
void unions()
{
	// creates a temporary object, and then copies it into "q" variable
	// aggregate initialization. More perfomance
	// it only works because there no explicit default constructor
	_16bytes w = { 1, 2, 3, 4};
	_16bytesV2 w2 = { 1, 2, 3, 4};
	_16bytesV2 w3( 1, 2, 3, 4 );

	struct Union {
		// four different ways to evaluate the same memory address
		union {
			float x;
			int y;
		};
	};

	Union u;
	u.x = 2.0f;
	std::cout << u.x << ", " << u.y << std::endl;
	std::cout << (int)2.0f << std::endl;

	Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
	vector.w = 200; // this will change vector.b.x
	vector.z = 500; // and this will change vector.b.y
	// because they both represent the same memory address
	std::cout << vector.b.x << std::endl;
	std::cout << vector.b.y << std::endl;

	// all of them represent the same memory address
	// changing one, change the other, inside the bytes of the largest data member
	std::cout << &u << std::endl;
	std::cout << &u.x << std::endl;
	std::cout << &u.y << std::endl;
}

class Base_Class
{
public:
	Base_Class()
	{
		std::cout << "instance created base" << std::endl;
	}

	// the "virtual" keyword in base classes destructors, means that
	// in derived classes, the derived class's destructor should also be called


	// always declare a destructor as virtual if you are allowing this class to be extended by other classes
	virtual ~Base_Class()
	{
		std::cout << "instance destroyed base" << std::endl;
	}
};

class Derived : public Base_Class 
{
private:
	int* m_array;
public:
	Derived(): m_array(new int[5])
	{
		std::cout << "instance created derived" << std::endl;
	}

	~Derived()
	{
		std::cout << "instance destroyed derived" << std::endl;
		delete[] m_array;
	}
};



void virtual_destructors()
{
	Base_Class* base = new Base_Class();
	delete base;
	std::cout << "--------------------" << std::endl;

	Derived* derived = new Derived();
	delete derived;
	std::cout << "--------------------" << std::endl;

	// with polymorphism

	// this way, when it is deleted, only call the base class destructor if no virtual destructor is defined
	// not having virtual destructor, can potentially lead to memory leaks,
	// if the derived class had any heap allocation. So, in the case
	// of only call the base destructor, it will not free that memory allocated in the derived class
	Base_Class* poly = new Derived();
	delete poly;
}

// type casting in c++
// c-style casting can achieve the same things
// cast in english words. Easy to search for
void casting()
{
	int a = 5;
	// implicit conversion, with no data loss ( upcasting )
	double b = a;

	// implicit conversion, with data loss ( downcasting )
	double y = 7.5045;
	int z = y;
	std::cout << z << std::endl;

	double x = 7.25;
	// explicit casting ( c-style casting )
	int p = (int)x;

	// for primitive type casting mostly. No runtime check
	double q = static_cast<double>(p);

	// for user-defined type casting mostly. Runtime check. returns null if the conversion was not possible
	Base_Class* base = new Base_Class();
	Derived* derived = dynamic_cast<Derived*>(base);
	// will return a nullptr, because of the dynamic cast check
	std::cout << "conversion from base class to derived class: " << derived << std::endl;

	Derived* derived2 = new Derived();
	Base_Class* base2 = dynamic_cast<Base_Class*>(derived2);
	// will return a valid pointer, because of the dynamic cast check
	std::cout << "conversion from derived class to base class " << base2 << std::endl;
}

// safety in c++
// -> reduces memory leaks, crashes, access violations

// two problems with heap allocation:
// 1. memory leaks
// 2. ownership. Who is the owner of that memory?
//	-> a lot of different routines requiring access to a pointer. Who, at the end of the day, manages the memory which that pointer holds?

// it is a matter of just automating a single line of code: "delete" pointer
// forgetting to write this line down, can lead to several problems related to security 
// use smart pointers. They solve the problem of memory leaks and ownership automatically

// -----------------------------------------------------------------------------------------------------------------------------------------

// PCH: pre compiled header
// -> it is a binary version of a header file that includes a bunch of other header files
// cons:
	// -> should mostly include headers that are not potentially changing, because if not, it will probably slows down the compilation time instead
	//  -> can lead to less readble code, by not being clear about which header files are being used in a cpp file
// -> should include header files that are included in multiple cpp files
// it is vitally used for code that is not mine. windows.h for example, vector for example

// convert header file in a compiled format
// on include statements, the compiler reads all the header file and then copies it into the cpp file.
// -> for this to happen, there's a whole process of parse and tokenizing the content of the header file. This takes time
// -> doing this at every compilation, depending on the size of the project, can become very unproductive and a time consuming task
// optmization to avoid multiple recompilation of header files after changes in cpp files

// the solution is: tell the compiler about a bunch of header files, and ask for it to compile them once and store the result in a binary file
// the result is: way faster compilation times
void precompiled_headers() { }

// it is evaluted at runtime 
// it is used for casts along the inheritance hierarchy
// cast base type to derived type is tricky
// so, dynamic_casting is pretty useful to valite if a casting is valid, because it will return a nullptr if it is not valid

class _Entity {
public:
	// creates vtable, so dynamic cast is possible
	virtual void print() {}
};
class _Player: public _Entity {};
class Enemy: public _Entity {};

// RTTI: runtime type information
// adds overhead of course
// this is how dynamic cast knows if the casting can be perfomerd or not
// dynamic cast takes time as well, at runtime
// works because metainformation about the type at runtime
void dynamic_casting()
{
	_Player* p1 = new _Player(); // no conversion
	_Entity* e1 = p1; // implicit and safe conversion
	// player has everything the a entity has, and can have even more

	// e1 could be an enemy. So the conversion will no work
	// but, with dynamic cast, it will return a invalid pointer if the casting was not successfull
	// if the cast is successfull, than it will return a valid pointer
	_Player* p2 = dynamic_cast<_Player*>(e1);
	Enemy* enemy2 = dynamic_cast<Enemy*>(e1);
	if(!enemy2) std::cout << "invalid cast" << std::endl;
	std::cout << p2 << std::endl;
	std::cout << enemy2 << std::endl;
}

// never measure code perfomance in debug mode
// always in release mode
// debug mode does a whole lot of extra safety stuff
void benchmarking()
{
	int value = 0;
	for(int i=0; i<100000; i++)
		value += 2;

	std::cout << value << std::endl;
	__debugbreak();
}

std::tuple<int, bool> get_tuple()
{
	return std::make_tuple<int, bool>(5, true);
	// or return { 5, true }
}

std::tuple<std::string, int> make_person()
{
	return { "churros", 9 };
}
//  deal with multiple return values
void structured_bindings()
{
	int number = std::get<0>(get_tuple());
	std::cout << number << std::endl;

	std::string n; int a;
	// kind of destructures the tuple returned by make person
	std::tie(n, a) = make_person();
	// only c++ 17>
	auto[name, age] = make_person();
	std::cout << name << " " << std::endl;
}
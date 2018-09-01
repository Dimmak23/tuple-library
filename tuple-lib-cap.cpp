#include <iostream>
// Class template std::tuple is a fixed-size collection
// of heterogeneous values.
#include <tuple>

// Function for wrapping given elements into tuple
// and also printing them
void print_pack(std::tuple<std::string&&,int&&> pack)
{
	std::cout<<'\n'<<' '<<' '<<' '<<std::get<0>(pack)<<','<<' ';
	std::cout<<std::get<1>(pack)<<'\n';
}

// Main function starts here
int main()
{
	
	// Load data into tuple foo by naming type of every
	// element
	std::tuple<int,char> foo (10,'x');

	int myint; char mychar;

	// Unpack elements
	// basically release contain of foo into vars myint, mychar
	std::tie(myint, mychar) = foo;

	std::cout<<"\n1. print after simple std::tie(...) to variables: ";
	std::cout<<"\n\n   myint="<<myint<<"; mychar="<<mychar<<';';
	// std::get is the only way of accessing element from tuple
	std::cout<<"\n\n   foo containts: ";
	std::cout<<std::get<0>(foo)<<' ';
	std::cout<<std::get<1>(foo)<<'\n';

	// Reload vars content:
	myint=11; mychar='r';
	
	// Basically load contain of variables myint,
	// mychar into tuple foo
	std::get<0>(foo)=myint;
	std::get<1>(foo)=mychar;

	std::cout<<"\n2. Using std::get<index>(x)=y:\n";
	std::cout<<"\n   variables containts: ";
	std::cout<<"myint="<<myint;
	std::cout<<"; mychar="<<mychar<<';';

	std::cout<<"\n\n   foo containts: ";
	std::cout<<std::get<0>(foo)<<' ';
	std::cout<<std::get<1>(foo)<<'\n';

	// Reload vars content:
	myint=23; mychar='v';
	
	// Load data into tuples bar and pub without
	// naming type of every element
	auto bar = std::make_tuple("sense",65,72.6);
	auto pub = std::make_tuple(mychar,myint);

	std::cout<<"\n3. Using std::make_tuple(...):\n";
	std::cout<<"\n   bar contain: ";
	std::cout<<std::get<0>(bar)<<' ';
	std::cout<<std::get<1>(bar)<<' ';
	std::cout<<std::get<2>(bar)<<'\n';	

	std::cout<<"\n   pub contain: ";
	std::cout<<std::get<0>(pub)<<' ';
	std::cout<<std::get<1>(pub)<<'\n';	

	// std::tuple_size<decltype>(...) get quatity
	// of elements in the tuple
	std::cout<<"\n4. Using std::tuple_size<decltype>(...):\n";
	std::cout<<"\n   foo has ";
	std::cout<<std::tuple_size<decltype(foo)>::value;
	std::cout<<" elements."<<'\n';

	std::cout<<"\n   bar has ";
	std::cout<<std::tuple_size<decltype(bar)>::value;
	std::cout<<" elements."<<'\n';

	std::cout<<"\n   pub has ";
	std::cout<<std::tuple_size<decltype(pub)>::value;
	std::cout<<" elements."<<'\n';

	// Initialization of string someth,
	// it will be usefull next
	std::string someth = "any";

	// Releasing contain of bar into vars mychar, myint
	// respectively, but string content of tuple bar
	// is ignored
	std::tie(std::ignore,mychar,myint) = bar;	

	std::cout<<"\n5. print after std::tie(...) variables containts ";
	std::cout<<"\n   by using std::ignore:\n\n";
	std::cout<<' '<<' '<<' '<<"someth="<<someth<<';'<<' ';
	std::cout<<"myint="<<myint;
	std::cout<<"; mychar="<<mychar<<';'<<'\n';	

	// Releasing contain of bar into vars mychar, myint
	// respectively, but now string content of tuple bar
	// is not ignored and releasing into string someth	
	std::tie(someth,mychar,myint) = bar;	

	std::cout<<"\n6. print after std::tie(...) variables containts ";
	std::cout<<"\n   without using std::ignore:\n\n";
	std::cout<<' '<<' '<<' '<<"someth="<<someth<<';'<<' ';
	std::cout<<"myint="<<myint;
	std::cout<<"; mychar="<<mychar<<';'<<'\n';

	// Initilizing new tuple with content
	auto caffe = std::make_tuple("of humor",12,132.6);
	
	// Combine tuples bar and caffe into new tuple bistro
	auto bistro = std::tuple_cat (bar, caffe);

	std::cout<<"\n7. print bistro after std::tuple_cat: \n\n";
	std::cout<<' '<<' '<<' '<<std::get<0>(bistro)<<' ';
	std::cout<<std::get<1>(bistro)<<' ';
	std::cout<<std::get<2>(bistro)<<' ';
	std::cout<<std::get<3>(bistro)<<' ';
	std::cout<<std::get<4>(bistro)<<' ';
	std::cout<<std::get<5>(bistro)<<'\n';			

	std::string name ("Dmytro");
	std::string surname1 ("Smith");
	std::string surname2 ("Doe");	

	std::cout<<"\n8. print using std::forward_as_tuple: "<<'\n';
	// Calling function print_pack(...) for printing names
	// with some numbers.
	print_pack(std::forward_as_tuple(name+' '+surname1,23));
	print_pack(std::forward_as_tuple(name+' '+surname2,27));	
	// std::forward_as_tuple - is designed to forward arguments,
	// not to store its result in a named variable, since
	// the returned object may contain references
	// to temporary variables.
	// Tuple pack not accessible in the main function,
	// because it produce outside main function.

	// a.swap(b) is exchanges the content of the tuple object a
	// by the content of object b, which is another tuple
	// of the same type.
	// Priviously, was declared a tuples bar and caffe
	// and they are the same type.
	bar.swap(caffe);
	std::cout<<"\n9. Using a.swap(b):\n";
	std::cout<<"\n   bar contain: ";
	std::cout<<std::get<0>(bar)<<' ';
	std::cout<<std::get<1>(bar)<<' ';
	std::cout<<std::get<2>(bar)<<'\n';

	std::cout<<"\n   caffe contain: ";
	std::cout<<std::get<0>(caffe)<<' ';
	std::cout<<std::get<1>(caffe)<<' ';
	std::cout<<std::get<2>(caffe)<<'\n';

	// template <size_t I, class... Types>
	// class tuple_element< I, tuple<Types...> >;

	// std::tuple_element is a class designed to access
	// the type of the Ith element in a tuple.
	// It is a simple class with a single member type,
	// tuple_element::type, defined as an alias of the
	// type of the Ith element in a tuple of type T.

	std::tuple_element<0,decltype(caffe)>::type caffe0 = std::get<0>(caffe);
	// it is basically the same that next:
	auto autocaffe0 = std::get<0>(caffe);

	std::cout<<"\n10. Using std::tuple_element<index,decltype(tuple_name)>::type :\n";
	std::cout<<"\n    caffe0 contain: "<<caffe0<<'\n'<<'\n';
	std::cout<<"    autocaffe0 contain: "<<autocaffe0<<'\n';

	// Relational operators of tuple.
	// Operators == and != operate comparing the elements one by one
	// (using operator==), stopping at the first mismatch, if any.
	// Making new tuple copycaffe with every parameter is copy
	// of caffe element exept last one
	auto copycaffe = std::make_tuple(std::get<0>(caffe),std::get<1>(caffe),23.4);

	std::cout<<"\n11. copycaffe contain: ";
	std::cout<<std::get<0>(copycaffe)<<' ';
	std::cout<<std::get<1>(copycaffe)<<' ';
	std::cout<<std::get<2>(copycaffe)<<'\n';

	std::cout<<"\n    Caffe and copycaffe";
	std::cout<<" are not equal - ";
	// std::boolalpha - is element from <ios> library
	// it help print exact word true or false
	std::cout<<std::boolalpha<<(caffe!=copycaffe)<<'.'<<'\n';
	std::cout<<"    Because last elements are not equal."<<'\n';

	std::cout<<"\n    At least one element of caffe is";
	std::cout<<"\n    bigger than cooresponding of copycaffe - ";
	std::cout<<std::boolalpha<<(caffe>copycaffe)<<'.'<<'\n';	

	// And that's all folks
	return 0;
	
}
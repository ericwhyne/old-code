// Example code for how to overload operators as member functions and as non member functions
//    of classes in c++
// Eric Whyne
// License:
// I give you permission to copy, hack, modify, and make a profit from this code.
// Completely free.  
#include <iostream.h>

class Box
	{
	private:
		int length;
		int width;
		int height;
	public:
		Box(); //This is the default constructor function that is ran when an object is declared.
		Box(int l, int w, int h); //This overloads the constructor function.
		int Volume(); //Just a member function to calculate volume.
		//I'm declaring the prototypes for these overloads inside the class so that they will
		// become member functions of this class.
		Box operator+(Box rightbox);
		void operator=(Box b);
		//For instructional purposes I have not made the operator<< function a member function
		//of this class, but have given it friend priviledges to access the private data members.
		friend void operator<<(ostream &output, Box abox);
	};

Box::Box(){length = 1; width = 1; height = 1;} //Definition of the default constructor.
Box::Box(int l, int w, int h){length = l; width = w; height = h;} //The overloaded constructor...
int Box::Volume(){return length * width * height;} //Just a function I added.

//These next to functions overload the operators + and =  
//They are member functions of the class Box and thus have access to the data members.
//the operator<< function is NOT a member function of the class, and thus needs to be
//declared as a friend inside the class to have access.
Box Box::operator+(Box rightbox)
{
	Box buffer;
	buffer.length = length + rightbox.length;
	buffer.width = width + rightbox.width;
	buffer.height = height + rightbox.height;
return buffer;	
}
void Box::operator=(Box b)
	{
		length = b.length;
		width = b.width;
		height = b.height;
	}
//I overloaded this operator as a friend, just to show how to do access the data members
// from a function that is outside of the class.
void operator<<(ostream &output, Box abox)
	{
	output<<"\nThe length is: "<<abox.length<<"\n"
		  <<"The width is: "<<abox.width<<"\n"
		  <<"The height is: "<<abox.height<<"\n"
		  <<"The volume is: "<<abox.Volume()<<"\n";
	}


int main()
{
Box box0; //The default constructor is ran.
Box box1(2, 3, 4); //The overloaded constructor is ran.
Box box2;

cout<<box1; //The overloaded output is ran.

cout<<box1 + box0;

box2 = box1;

cout<<box1;

Box abigbox = box0 + box1 + box2;

cout<<abigbox;

return 0;
}

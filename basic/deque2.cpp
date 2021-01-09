/*
#include <string>
#include <iostream>
#include <iterator>
#include <deque>
#include <vector>

typedef struct{
    //char buf[100];
    const char * buf;
    int type;
    int size;
} data_t;

int main() {
 
	// uses explicit deduction guide to deduce std::deque<int>
	std::vector<data_t> v={{"hello1",1,6},{"hello2",2,6},{"hello3",3,6}};

	std::deque x(v.begin(), v.end()); 

	data_t d4;
	d4.type = 4;
	d4.buf = "hello4";

	data_t d5;
	d5.type = 5;
	d5.buf = "hello5";

	data_t d6;
	d6.type = 6;
	d6.buf = "hello6";

	x.push_front(d4);
	x.push_back(d5);
	x.push_back(d6);

	for(data_t n : x)
		std::cout << n.type << n.buf << '\n';
	
	return 0;
}
*/



#include <iostream>
#include <deque>

typedef struct{
    //char buf[100];
	const char * buf;
    int type;
    int size;
} data_t;
 
int main()
{
	// Create a deque containing integers
	std::deque<data_t> x(32);

	data_t d4;
	d4.type = 4;
	d4.buf = "hello4";

	data_t d5;
	d5.type = 5;
	d5.buf = "hello5";

	data_t d6;
	d6.type = 6;
	d6.buf = "hello6";

	x.push_front(d4);
	x.push_back(d5);
	x.push_back(d6);

	// Iterate and print values of deque
	for(data_t n : x) {
		std::cout << n.type << '\n';
	}

    for(const auto& n: x)
        std::cout << n.type << std::endl;

}


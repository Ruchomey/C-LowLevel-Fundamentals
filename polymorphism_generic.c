#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

/* * Topic: Polymorphism in C using function pointers and void*
* Description: Simulation of a driver architecture.
* The 'operation' function accepts a generic data pointer, * allowing for different configurations to be handled through the same interface.
*/

struct Config {
	int id;
	int speed;
};

struct Driver {
	char name[20];
	void (*operator)(void* ptr);
};


void opendata(void* ptr) {


	struct Config* g = (struct Config*)ptr;
	printf("id: %d | speed: %d", g->id, g->speed);

}

void closedata(void* ptr) {


	struct Config* g = (struct Config*)ptr;
	printf("id: %d | speed: %d", g->id, g->speed);

}


int main() {

	struct Config mydata = { 67, 61 };

	struct Driver d1;
	struct Driver d2;
		 
	strcpy(d1.name, "D1 name");
	strcpy(d2.name, "D2 Name");

	d1.operator = opendata;
	d2.operator = closedata;

	d1.operator(&mydata);
	return 0;
}
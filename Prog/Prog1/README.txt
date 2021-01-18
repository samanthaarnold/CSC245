1. The attributes of the DList class and why templates are being used
	The attributes of the DList class are head and length. Head 
	is a pointer variable that points to the address of the first
 	item in a linked list. Lenght is an integer variable created
	to keep track of the size of the linked list.
	
	Templates allow you to write a generic program that can be 
	used to work with differnt data types. The templates are 
	being used on functions in the DList class. 

2. A description of each of the operations of the DList class
	- void makeEmpty(): deallocates memory used by list,
	sets head pointer to null 

	- void deleteItem(): deletes the item from the list 
	sent in as a parameter from the list after finding it 
	via inList and then deletes the location of that item
	using the function deleteLocation.  

	- bool inList(): returns a bool indicating whether or 
	not a given item sent in as a parameter is in the list.

	- bool isEmpty(): returns a bool indicating whether or
	not the list is empty. 

	- void print(): prints the info stored in each node of
	of the list.

	- void insertHead(): inserts an item sent in as a 
	parameter onto the head of the list.

	- void appendTail(): inserts an item sent in as a 
	parameter onto the tail of the list.

	- int lenghtIs(): retruns the current length of the list.
	
3. The role of the Move to the Front Algorithm
	The Move to the Front algorithm uses the deleteItem 
	function from the specification file to delete an item
	sent in via a paramter. Then, the item is added to the
	front of the list using the insertHead function from 
	the specification file. The move to Front Algorithm is 
	used within the void function AccessFile in the client
	file. 
	

4. A description of the main algorithm followed by the client program
	The main algorithm is a switch that calls void functions
	within the client file. The switch prints a menu and runs 
	until the user wants to quit the program. The menu options 
	allows the user to create a linked list of integers and 
	insert items at the front or back, access an item in the 
	list and move them to the front, delete items in the list, 
	print the list and the length of the list, and quit the 
	program. These options are void functions in the client 
	file and are described below:
		- void PrintMenu(): prints the menu and takes in 
		the selection sent in as a char.
	
		- void HeadInsert():takes in an integer and  calls 
		the insertHead function	from the specification file
		 and adds an integer to	the front of the list. Does 
		not allow the user to add a duplicate item to the list.
		
		- void TailInsert(): takes in the integer and 
		calls the appendTail function from the specification
		file and adds an integer to the end of the list. 
		Does not allow the user to add a duplicate item to 
		the list.  

		- void AccessItem(): checks to see if the list is 
		is empty using the isEmpty function from the 
		specification file and prints an error message if so.
		If the list is not empty, takes in an integer from the
		and moves it to the front of the list using the 
		FindAndMove function.

		- void Delete(): checks to see if the list is empty 
		using the isEmpty function from the specification 
		file and prints an error message if so. Then, it 
		checks to see if the item is in the list via 
		inList from the specification and if the item is 
		not in the list, it prints an error message. If the
		list is not empty and in the list, it takes in an
		integer and uses the deleteItem function from the 
		specification file and removes the item from the 
		list. 

		- void PrintList(): checks to see if the list is 
		empty using the isEmpty function and prints an error
		if so. If the list is not empty, it calls the print
		function from the specification file and prints the 
		info stored in each node of the list. 

		- void PrintLenght(): calls the lengthIs function 
		from the specification file and prints the length 
		of the list. 


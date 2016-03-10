#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int x = 25;
//global data
		string north;
		string south;
		string east;
		string west;
		string current;
		string action;
		string nothing = "There is nothing here";
		string discover;
	
	//clue

string clue [8];
string map [100];
	//map

	
	int endgame = 0;
	int loc = 2;
	int opencave=0;
	int getmap = 0; 
	string suroundtype [5] = { " there are tree's."		," there are more tree's."	," there is a house."," there is a lake."	, " there is a open field." };
	string currenttype [5] = { " among alot of tree's."	," you are lost!"			,"near a house."		,"near a lake."		, " in a open field." };


//calling funtions

void clearchart ()
{

	for (int x=0; x<100; x++)
	{
		map [x] = "X\t";
	}

	for (int x=90; x<100; x++)
	{
		map [x] = "X\n";
	}
}

void chart ()
{
	if (getmap == 0)
	{
		for (int x=0; x<100; x=x+10)
		{
		
			cout << map[x];
			if ((x >= 90) && (x != 99))
			{
				x=x-99;
			}
			
		}
	}
	
	cout << endl << "legend: T = Tree's, C = Cave, W = Water, M = Mountain(not accesible)\nX = unvisited\n" << endl;
}

void erea_0 ()
{
	north = suroundtype [1];
	south = suroundtype [0];
	east = suroundtype [0];
	west = suroundtype [1];
	current = currenttype [0];
	discover = nothing;
	map [0] = "T\t";
}

void erea_1 ()
{
	north = suroundtype [0];
	south = suroundtype [0];
	east = suroundtype [0];
	west = suroundtype [1];
	current = currenttype [0];
	discover = nothing;
	map [1] = "T\t";	
}

void erea_2 ()
{
	north = suroundtype [0];
	south = suroundtype [0];
	east = suroundtype [0];
	west = suroundtype [1];
	current = currenttype [0];
	discover = nothing;
	map [2] = "T\t";
}

void erea_3 ()
{
	north = suroundtype [0];
	south = suroundtype [0];
	east = suroundtype [0];
	west = suroundtype [1];
	current = currenttype [0];
	discover =  "You found a cave!" ;
	if (opencave = 1)
	{
		map [3] = "C\t";
	}
	else
	{
		map [3] = "T\t";
	}

	
}

void erea_24 ()
{
	north = suroundtype [0];
	south = suroundtype [0];
	east = suroundtype [0];
	west = suroundtype [0];
	current = currenttype [2];
	discover =  "There is a house nearby." ;
	map [24] = "House\t";
}

void erea_103 ()
{
	cout << "You are standing in a cave\n";
	
	if (action == "examine")
	{
 		discover =  "You found a map" ;
 	
	}

}

void erea_124 ()
{
	cout << "You are standing in the living room" ;
	
	if (action == "examine")
	{
 		discover =  "You are safe now";
 		endgame = 1;
	}

}

void intro ()
{
string intro ;
cout << "This is a text based adventure" << endl;
cout << "These are the basic controls type clue for more options" << endl;
cout << "Type north, east, south or west to head in a certain direction" << endl;
cout << "typ \"clue\" to check a list with available actions" << endl;
cout << "No capitol letters!!!" << endl;
cout << "type \"start\" to start the game" << endl << endl << endl;
do {
getline (cin, intro);
} while (intro != "start");
}

void ereasorter()
{
	if (loc == 0)
	{
		erea_0();
	}

	if (loc == 1)
	{
		erea_1();
	}
	
		if (loc == 2)
	{
		erea_2();
	}
	
		if (loc == 3)
	{
		erea_3();
	}
		
		if (loc == 24)
	{
		erea_24();
	}

	if (loc == 103)
	{
		erea_103();
	}
	
	if (loc == 124)
	{
		erea_124();
	}
}


 
void printdata()
{
	if ((loc <= 99) && (loc >=0))
	{
	
	if (action == "map")
	{
		chart ();
	}

	cout << "To the north" << north << endl;
	cout << "To the south" << south << endl;
	cout << "To the east" << east << endl;
	cout << "To the west" << west << endl;
	cout << "you are currently standing " << current << endl;
	}
	
	if (action == "examine")
	{
		cout << endl << discover << endl; 
	}
	
	if (action == "clue")
	{
		for (int x=0; x<8 ; ++x)
		{
			cout << clue [x];
		}
	}
	
	

}

//commands
void whatdo()
{
// ckearbg clue
	for (int x=0; x<8; x++)
	{
		clue [x] = "";
	}

	//movement
	//north
	//general restrictions
	if ((loc <= 99) && (loc >=0))
	{
		//border restriction
		if ((loc != 0) && (loc != 10) && (loc != 20) && (loc != 30) && (loc != 40) && (loc != 50) && (loc != 60) && (loc != 70) && (loc != 80) && (loc != 90))
		{
			//additional restrictions
			if (loc !=26)
			{
				if (action == "north")
				{
					loc = loc - 1;
				}
				if (action == "clue")
				{
					clue [0] = " \"north\"";
				}
			}
		}
	}

	//south
	//general restrictions
	if ((loc <= 99) && (loc >=0))
	{
		//border restriction
		if ((loc != 9) && (loc != 19) && (loc != 29) && (loc != 39) && (loc != 49) && (loc != 59) && (loc != 69) && (loc != 79) && (loc != 89) && (loc != 99))
		{
			//additional restrictions
			if (loc !=24)
			{
				if (action == "south")
				{
					loc = loc + 1;
				}
				
				if (action == "clue")
				{
					clue [1] = ", \"south\"";
				}
			}
		}
	}

	//east
	//general restrictions
	if ((loc <= 99) && (loc >=0))
	{
		//border restriction
		if ((loc != 90) && (loc != 91) && (loc != 92) && (loc != 93) && (loc != 94) && (loc != 95) && (loc != 96) && (loc != 97) && (loc != 98) && (loc != 99))
		{
			//additional restrictions
			if (loc !=25)
			{
				if (action == "east")
				{
					loc = loc + 10;
				}
				
				if (action == "clue")
				{
					clue [2]= ", \"east\"";
				}
			}
		}
	}

	//west
	//general restrictions
	if ((loc <= 99) && (loc >=0))
	{
		//border restriction
		if ((loc != 0) && (loc != 1) && (loc != 2) && (loc != 3) && (loc != 4) && (loc != 5) && (loc != 6) && (loc != 7) && (loc != 8) && (loc != 9))
		{
			//additional restrictions
			if (loc !=35)
			{
				if (action == "west")
				{
					loc = loc - 10;
				}
				
				if (action == "clue")
				{
					clue [3] = ", \"west\"";
				}
			}
		}
	}

	//clue

	if (action == "clue")
	{
	clue [4] = ", \"clue\"";
	}
	
	//examine

	if (action == "examine")
	{
		cout << discover << endl;
		
		if (loc == 3)
		{
			opencave = 1;
		}
	}
	

	if (action == "clue")
	{
		clue [5] = ", \"examine\"";
	}
	

	//enter
	//house
	if (loc == 24)
	{
		if (action == "enter")
		{
		loc = loc + 100;	
		}
		clue [6] = ", \"enter\"";
	}
	
	//cave
	if ((loc == 3) && (opencave == 1))
	{
		if (action == "enter")
		{
		loc = loc + 100;
		}

		clue [6] = ", \"enter\"";
	} 

	//map
	if ((loc >=0) && (loc <=99))
	{
		if (action == "map")
		{
			// in printdata() due to order
		}
		
		
	clue [7] = ", \"map\"" ;

	}

	//exit
	if (loc <=99)
	{
		if (action == "exit")
		{
			// in printdata() due to order
		}
		
		
	clue [7] = ", \"exit\"\n" ;

	}
}
	

void game ()
{
string go;
clearchart ();
do 
{
	system("cls");
	cout << loc << endl;
	ereasorter();
	printdata();
	getline (cin, action);
	whatdo();
}
while (endgame !=1);

}


int main ()
{
//intro ();
game ();
cout << "you finished the game" << endl;
return 0;
}


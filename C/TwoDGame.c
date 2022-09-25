#include <stdio.h>

int main(int argc, char *args[]) {

    //Create the array to represent the map
    char map[20][100] = {0};

    //Set the player's location to the 'middle' of the map
    //I only want to edit start position in one place so I declare ints to hold them
    int startX = 10, startY = 50;
    int currentPosition[] = {startX, startY};
    map[startX][startY] = 'P';

    //Variables to help run the game
    int proceed = 1, argscheck = 0;
    int argsRunIndex = 0;

    //Define the directions as well as their x/y implications
    const char *directions[4] = {"NORTH", "EAST", "SOUTH", "WEST"};
    const int directionX[4] = {0, 1, 0, -1};
    const int directionY[4] = {-1, 0, 1, 0};
    //Having the player direction represented in the player char makes keeping track easier
    const char playerDirection[4] = {'^', '>', 'v', '<'};
    //Statically declare what the path looks like
    const char PATH = '#';

    //Begin the game facing east
    int currentDirection = 0;

    // Check if any args were passed
    if(argc > 0) {
        argscheck = 1;
    }

    while(proceed == 1) {
        //Declare something to hold the input
        char input[1];

        //Print out the map
        for(int y = 0; y < 20; y++) {
            for(int x = 0; x < 100; x++) {
                //If the space is unexplored print ░
                if(map[y][x] == 0) {
                    printf("%c", 9904);
                }
                //If the space is the player print the player
                else if(map[y][x] == 'P') {
                    printf("%c", playerDirection[currentDirection]);
                }
                //If the space is anything else, print the other thing
                else printf("%c", map[y][x]);
            }
            printf("\n");
        }

        //Give instructions on how to traverse the world.
        printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game\n");

        //If no arguments were given scan input
        if(argscheck == 0) {
            scanf("%s", input);
        } //If arguments were given, use them
        else {
            //If all arguments have been read then return control
            if(argsRunIndex == argc) {
                argscheck = 0;
                *input = *"e";
            }
            //Otherwise do that argument
            else {
                *input = *args[argsRunIndex];
                argsRunIndex++;
            }
        }
        switch(input[0]) {
            case 'w':
                //Mark the current square as explored
                map[currentPosition[0]][currentPosition[1]] = PATH;
                //Make sure not going over the wall boundaries
                if(currentPosition[0] + directionY[currentDirection] >= 0 &&
                   currentPosition[0] + directionY[currentDirection] < 20 &&
                   currentPosition[1] + directionX[currentDirection] >= 0 &&
                   currentPosition[1] + directionX[currentDirection] < 100) {
                        currentPosition[0] += directionY[currentDirection];
                        currentPosition[1] += directionX[currentDirection];
                }
                else printf("Bonk!\n");
                map[currentPosition[0]][currentPosition[1]] = 'P';
                break;
            case 'a':
                //Adding 3 then modulo 4 is the same as subtracting one without the need to check bounds
                currentDirection = (currentDirection + 3) % 4;
                break;
            case 'd':
                currentDirection = (currentDirection + 1) % 4;
                break;
            case 'e':
                printf("Current direction: %s\n", directions[currentDirection]);
                break;
            case 'q':
                proceed = 0;
                break;
            default:
                printf("Please enter a valid command!\n");
        }
    }

    return 0;
}
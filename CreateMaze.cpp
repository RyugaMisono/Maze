// Maze Program
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime>

int main(){
// Preparation
    // Time as Seed for Random Num
    srand ( time(NULL) );
    // The Size of Table
    int box_size = 9;
    // Make Table
    int maze[9][9];
    for(int i=0;i<box_size;i++){
        for(int j=0;j<box_size;j++){
            maze[i][j]=0;
        };
    };

// 1.Randomly Choose the Start Point As '2'
    //--------------------------
    // 0  => Untouched
    // 1  => Path
    // 2  => Start
    // 3  => Goal
    //--------------------------
    int rand1 = rand()%9;
    int rand2 = rand()%9;
    maze[rand1][rand2]=2;
    // Memorize Current Position
    int current_position1=rand1;
    int current_position2=rand2;
    // Keep Caving Loop
    bool on_mazing = true;
    while(on_mazing){
        // Assess Each Direction
        //-------------------------------------------------
        // '0' => Can Cave: Wall at two block further
        // '1' => Can't Cave: No wall at two block further
        //-------------------------------------------------
        char arrows[]={'0','0','0','0'};  // [0]: above, [1]: right, [2]: below, [3]: left
        // -Above
        if(maze[current_position1-2][current_position2]==0){
            arrows[0]='0';
        } else {
            arrows[0]='1';
        };
        // -Right
        if(maze[current_position1][current_position2+2]==0){
            arrows[1]='0';
        } else {
            arrows[1]='1';
        };
        // -Below
        if(maze[current_position1+2][current_position2]==0){
            arrows[2]='0';
        } else {
            arrows[2]='1';
        };
        // -Left
        if(maze[current_position1][current_position2-2]==0){
            arrows[3]='0';
        } else {
            arrows[3]='1';
        };
        // Finish Maze
        if(maze[current_position1-2][current_position2]!=0 && maze[current_position1][current_position2+2]!=0 && maze[current_position1+2][current_position2]!=0 && maze[current_position1][current_position2]-2!=0){
            on_mazing = false;
            maze[current_position1][current_position2] = 3;
            break;
        }
        
    // 2. Cave Path
        // Randomly choose a direction to cave out of assesesed black arrows
        bool on_caving = true;
        while(on_caving){
            int rand_direction = rand()%4;
            if(arrows[rand_direction]=='0'){
                // Caving into Path as 1
                switch(rand_direction)
                {
                // Above
                case 0:
                    // Update to Path
                    maze[current_position1-1][current_position2]=1;
                    maze[current_position1-2][current_position2]=1;
                    // Fix Current Position
                    current_position1=current_position1-2;
                    // Break While Loop
                    on_caving=false;
                    break;
                // Right
                case 1:
                    // Update to Path
                    maze[current_position1][current_position2+1]=1;
                    maze[current_position1][current_position2+2]=1;
                    // Fix Current Position
                    current_position2=current_position2+2;
                    // Break While Loop
                    on_caving=false;
                    break;
                // Below
                case 2:
                    // Update to Path
                    maze[current_position1+1][current_position2]=1;
                    maze[current_position1+2][current_position2]=1;
                    // Fix Current Position
                    current_position1=current_position1+2;
                    // Break While Loop
                    on_caving=false;
                    break;
                // Left
                case 3:
                    // Update to Path
                    maze[current_position1][current_position2-1]=1;
                    maze[current_position1][current_position2-2]=1;
                    // Fix Current Position
                    current_position2=current_position2-2;
                    // Break While Loop
                    on_caving=false;
                    break;
                default:
                    break;
                }
            }
        }
    }

    // Test Output
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}

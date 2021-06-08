#include <iostream>
#include <cstdlib>
#include "Hockey_table.h"
#include "ExplodingDisc.h"
#include "ShrinkingDisc.h"

using namespace std;
int main() {
    string cmd; // for command input
    double x,y,vx,vy,radius; // for "Disc" creation
    double x1,x2,y1,y2; // for "Wall" creation
    double t,dt; //for simulate cmd
    WallLinkedList wallLinkedlist; //wall linked list to store walls
    DiscLinkedList discLinkedlist; //disc linked list to store disc
    Hockey_table hockeyTable(discLinkedlist,wallLinkedlist); //hockey table init.
    while (cin>>cmd || !cin.eof()){
        if (cmd=="disc"){
            cin>>x>>y>>vx>>vy>>radius;
            if(cin.fail()){
                cerr<<"Error: illegal input."<<endl;
                exit(0);
            }
            hockeyTable.check_stepover(Disc(x, y, vx, vy, radius));
            hockeyTable.discLinkedlist.add_disc(Disc(x, y, vx, vy, radius));
        } else if (cmd == "wall"){
            cin>>x1>>y1>>x2>>y2;
            if(cin.fail()){
                cerr<<"Error: illegal input."<<endl;
                exit(0);
            }
            hockeyTable.check_stepover(Wall(x1,y1,x2,y2));
            hockeyTable.wallLinkedlist.add_wall(Wall(x1,y1,x2,y2));
        } else if (cmd == "simulate"){
            cin>>t>>dt;
            if(hockeyTable.discLinkedlist.getCount() == 0){
                cerr<<"Error: illegal input."<<endl;
                return 0;
            }
            hockeyTable.simulate(t,dt);
            return 0;
        }
        else if (cmd == "exploding_disc"){
            cin>>x>>y>>vx>>vy>>radius;
            if(cin.fail()){
                cerr<<"Error: illegal input."<<endl;
                exit(0);
            }
            hockeyTable.check_stepover(Disc(x, y, vx, vy, radius));
            hockeyTable.discLinkedlist.add_disc(ExplodingDisc(x,y,vx,vy,radius,radius*radius,0));
        }
        else if (cmd == "shrinking_disc"){
            cin>>x>>y>>vx>>vy>>radius;
            if(cin.fail()){
                cerr<<"Error: illegal input."<<endl;
                exit(0);
            }
            hockeyTable.check_stepover(Disc(x, y, vx, vy, radius));
            hockeyTable.discLinkedlist.add_disc(ShrinkingDisc(x,y,vx,vy,radius,0));
        }
        else{
            cerr<<"Error: illegal input."<<endl;
            return 0;
        }
    }
    cerr<<"Error: illegal input."<<endl;
    return 0 ;
}

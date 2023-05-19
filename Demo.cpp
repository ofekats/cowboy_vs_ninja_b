/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;

int main()
{
   Point a(32.3, 44), b(1.3, 3.5);
   assert(a.distance(b) == b.distance(a));
   Cowboy *tom = new Cowboy("Tom", a);
   OldNinja *sushi = new OldNinja("sushi", b);
   tom->shoot(sushi);
   cout << tom->print() << endl;

   sushi->move(tom);
   sushi->slash(tom);

   Team team_A(tom);
   team_A.add(new YoungNinja("Yogi", Point(64, 57)));

   // Team b(tom); should throw tom is already in team a

   Team team_B(sushi);
   team_B.add(new TrainedNinja("Hikari", Point(12, 81)));

   while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
   {
      team_A.attack(&team_B);
      team_B.attack(&team_A);
      team_A.print();
      team_B.print();
   }

   if (team_A.stillAlive() > 0)
      cout << "winner is team_A" << endl;
   else
      cout << "winner is team_B" << endl;
   // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

   cout << "===========================" << endl;
   cout << "         my demo:" << endl;
   cout << "===========================" << endl;

   Point a1(0,6);
   Point b1(12.5, 30);
   cout << a1.distance(b1) << endl;

   Cowboy *cowboy = new Cowboy("Cowboy", a1);
   cout << cowboy->print() << endl;

   YoungNinja * young = new YoungNinja ("Young", b1);
   cout << young->print() << endl;
   young->move(cowboy);
   cout << "relocate "<< young->getName() <<": "<< endl;
   cout << young->print() << endl;

   Point c1(25,70);
   TrainedNinja * train = new TrainedNinja("Train", c1);
   cout << train->print() << endl;

   OldNinja * old = new OldNinja("Old", c1);
   cout << old->print() << endl;
   cout << "distance between "<< old->getName() << " and " << train->getName() << ": " <<old->distance(train) << endl;

   Team team1 (old);
   Team2 team2 (young);

   team1.add(train);
   team2.add(cowboy);
   cout << "\nTeam VS Team2 : "<< endl;
   cout << "\nteam1: "<< endl;
   team1.print();
   cout << "team2: "<< endl;
   team2.print();
   cout << "\nstart to attack! "<< endl;
   int i=1;
   while (team1.stillAlive() > 0 && team2.stillAlive() > 0)
   {
      team1.attack(&team2);
      team2.attack(&team1);
      cout << "after round "<< i <<": "<< endl;
      cout << "team1: "<< endl;
      team1.print();
      cout << "team2: "<< endl;
      team2.print();
      i++;
   }
   cout << "end of attack! \n"<< endl;
   if (team1.stillAlive() > 0)
      cout << "winner is team1!" << endl;
   else
      cout << "winner is team2!" << endl;



   cout << "\n Team VS SmartTeam :" << endl;
   Point a2(0,6);
   Point b2(12.5, 30);
   Point c2(25,70);
   Cowboy *cowboy2 = new Cowboy("Cowboy", a2);

   YoungNinja * young2 = new YoungNinja ("Young", b2);
   young2->move(cowboy2);
   TrainedNinja * train2 = new TrainedNinja("Train", c2);

   OldNinja * old2 = new OldNinja("Old", c2);
   Team team_1 (old2);
   SmartTeam team_2 (young2);

   team_1.add(train2);
   team_2.add(cowboy2);

   cout << "\nteam_1: "<< endl;
   team1.print();
   cout << "team_2: "<< endl;
   team2.print();
   cout << "\nstart to attack! "<< endl;
   i=1;
   while (team_1.stillAlive() > 0 && team_2.stillAlive() > 0)
   {
      team_1.attack(&team_2);
      team_2.attack(&team_1);
      cout << "after round "<< i <<": "<< endl;
      cout << "team_1: "<< endl;
      team_1.print();
      cout << "team_2: "<< endl;
      team_2.print();
      i++;
   }
   cout << "end of attack! \n"<< endl;

   if (team_1.stillAlive() > 0)
      cout << "winner is team_1!" << endl;
   else
      cout << "winner is team_2!" << endl;   

   return 0;
}

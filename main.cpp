/*
 * This file is the main file of our project it will allows to
 * test the functionalities of our project
 * Author:Edgard Zafack 
 */

/* 
 * File:   main.cpp
 * Author: abcd
 *
 * Created on February 10, 2016, 12:34 PM
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cctype>
#include<vector>
#include "headFileEdgard.h"
using namespace std;

int main() {
fstream myDicoFile;
myDicoFile.open("MyDictionnaryFile.txt",ios::in|ios::out|ios::app);
//myDicoFile.open("MyDictionnaryFi.txt",ios::in);
int selec;
vector<words> german(2),french(2),latin(2),hebrew(2);
    for (;;) {
        int choice = menue();
        cin.ignore();
        switch (choice) {
            case 1:
                system("clear");
                cout<<"1-Create German list\n";
                cout<<"2-Create French list\n";
                cout<<"3-Create Latin list\n";
                cout<<"4-Create Hebrew list\n";
                cout<<"your selection:";
                cin>>selec;
                if(selec ==1)
                    createWordlist(myDicoFile,selec);
                if(selec ==2)
                    createWordlist(myDicoFile,selec);
                if(selec ==3)
                    createWordlist(myDicoFile,selec);
                if(selec ==4) 
                    createWordlist(myDicoFile,selec);
                break;
            case 2:
                system("clear");
                gerFrLatHebToEngNouns(myDicoFile,1,"noun");
                gerFrLatHebToEngNouns(myDicoFile,2,"noun");
                gerFrLatHebToEngNouns(myDicoFile,3,"noun");
                gerFrLatHebToEngNouns(myDicoFile,4,"noun");
                cin.get();
                break;
            case 3:
                system("clear");
                gerFrLatHebToEngNouns(myDicoFile,1,"verb");
                gerFrLatHebToEngNouns(myDicoFile,2,"verb");
                gerFrLatHebToEngNouns(myDicoFile,3,"verb");
                gerFrLatHebToEngNouns(myDicoFile,4,"verb");
                cin.get();
                break;
            case 4:
                system("clear");
                gerFrLatHebToEngNouns(myDicoFile,1,"preposition");
                gerFrLatHebToEngNouns(myDicoFile,2,"preposition");
                gerFrLatHebToEngNouns(myDicoFile,3,"preposition");
                gerFrLatHebToEngNouns(myDicoFile,4,"preposition");
                cin.get();
                break;
            case 5:
                system("clear");
                gerFrLatHebToEngNouns(myDicoFile,1,"adjective");
                gerFrLatHebToEngNouns(myDicoFile,2,"adjective");
                gerFrLatHebToEngNouns(myDicoFile,3,"adjective");
                gerFrLatHebToEngNouns(myDicoFile,4,"adjective");
                cin.get();
                break;
            case 6:
                system("clear");
                gerFrLatHebToEngNouns(myDicoFile,1,"adverb");
                gerFrLatHebToEngNouns(myDicoFile,2,"adverb");
                gerFrLatHebToEngNouns(myDicoFile,3,"adverb");
                gerFrLatHebToEngNouns(myDicoFile,4,"adverb");
                cin.get();
                break;
            case 7:
                system("clear");
                gerFrLatHebToEngNouns(myDicoFile,1,"cardinal number");
                gerFrLatHebToEngNouns(myDicoFile,2,"cardinal number");
                gerFrLatHebToEngNouns(myDicoFile,3,"cardinal number");
                gerFrLatHebToEngNouns(myDicoFile,4,"cardinal number");
                cin.get();
                break;
            case 8:
                system("clear");
                gerFrLatHebToEngAll(myDicoFile,german,french,latin,hebrew);
                cin.get();
                break;
            case 9:
                system("clear");
                entoGermFrLatHebPart(myDicoFile,1,"noun");
                entoGermFrLatHebPart(myDicoFile,2,"noun");
                entoGermFrLatHebPart(myDicoFile,3,"noun");
                entoGermFrLatHebPart(myDicoFile,4,"noun");
                cin.get();
                break;
            case 10:
                system("clear");
                entoGermFrLatHebPart(myDicoFile,1,"verb");
                entoGermFrLatHebPart(myDicoFile,2,"verb");
                entoGermFrLatHebPart(myDicoFile,3,"verb");
                entoGermFrLatHebPart(myDicoFile,4,"verb");
                cin.get();
                break;
            case 11:
                system("clear");
                entoGermFrLatHebPart(myDicoFile,1,"preposition");
                entoGermFrLatHebPart(myDicoFile,2,"preposition");
                entoGermFrLatHebPart(myDicoFile,3,"preposition");
                entoGermFrLatHebPart(myDicoFile,4,"preposition");
                cin.get();
                break;
            case 12:
                system("clear");
                entoGermFrLatHebPart(myDicoFile,1,"adjective");
                entoGermFrLatHebPart(myDicoFile,2,"adjective");
                entoGermFrLatHebPart(myDicoFile,3,"adjective");
                entoGermFrLatHebPart(myDicoFile,4,"adjective");
                cin.get();
                break;
            case 13:
                system("clear");
                entoGermFrLatHebPart(myDicoFile,1,"adverb");
                entoGermFrLatHebPart(myDicoFile,2,"adverb");
                entoGermFrLatHebPart(myDicoFile,3,"adverb");
                entoGermFrLatHebPart(myDicoFile,4,"adverb");
                cin.get();
                break;
            case 14:
                system("clear");
                entoGermFrLatHebPart(myDicoFile,1,"cardinal number");
                entoGermFrLatHebPart(myDicoFile,2,"cardinal number");
                entoGermFrLatHebPart(myDicoFile,3,"cardinal number");
                entoGermFrLatHebPart(myDicoFile,4,"cardinal number");
                cin.get();
                break;
            case 15:
                cout<<"case2";
                break;
            case 16:
                cout<<"case2";
                break;
            case 17:
                return 0;
                break;
            default:
                cout << "\n\nInvalid choice--reenter" << endl;
                cout << "hit a key...";
                getchar();

        }
    }
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EdgardheadFile.h
 * Author:Edgard Zafack
 *
 * Created on February 10, 2016, 12:39 PM
 */
using namespace std;
#include <cstdlib>
#include<fstream>
#include<vector>
#ifndef EDGARDHEADFILE_H
#define EDGARDHEADFILE_H
//prototype of my structure word
struct words{
    string word;
    string part;
    string meaning;
};

//prototype of my function menu that displays the different functionalities
int menue();
void createWordlist(fstream &,int &);
void loadVectors(fstream &,vector<words> &,vector<words> &,vector<words> &,vector<words> &);
void gerFrLatHebToEngAll(fstream &,vector<words> &,vector<words> &,vector<words> &,vector<words> &);
void engToGermFrLatHebNouns(fstream &,int);
void entoGermFrLatHebPart(fstream &,int,string);
void gerFrLatHebToEngNouns(fstream &,int,string);
void engToGermFrLatHebAll();
void transformTolowCase(string &,string &);
void sortFunction(vector<words> &);
void searchUniversal();
void quit();
#endif /* EDGARDHEADFILE_H */


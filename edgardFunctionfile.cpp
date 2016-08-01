/*
 * This file contains the implementation of functions
 * i declared in my head file
 */
#include <iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<vector>
#include<fstream>
#include<algorithm>
#include "headFileEdgard.h"
using std::cin;
using std::cout;
using std::endl;

int menue() {
    int choice;
    system("clear");
    cout << "1-Create the word list" << endl;
    cout << "2-German,French,Latin,Hebrew to English nouns" << endl;
    cout << "3-German,French,Latin,Hebrew to English verbs" << endl;
    cout << "4-German,French,Latin,Hebrew to English preposition" << endl;
    cout << "5-German,French,Latin,Hebrew to English adjectives" << endl;
    cout << "6-German,French,Latin,Hebrew to English adverbs" << endl;
    cout << "7-German,French,Latin,Hebrew to English cardinal numbers" << endl;
    cout << "8-German,French,Latin,Hebrew to English all" << endl;
    cout << "9-English to German,French,Latin,Hebrew nouns" << endl;
    cout << "10-English to German,French,Latin,Hebrew verbs" << endl;
    cout << "11-English to German,French,Latin,Hebrew prepositions" << endl;
    cout << "12-English to German,French,Latin,Hebrew adjectives" << endl;
    cout << "13-English to German,French,Latin,Hebrew adverbs" << endl;
    cout << "14-English to German,French,Latin,Hebrew cardinal numbers" << endl;
    cout << "15-English to German,French,Latin,Hebrew all" << endl;
    cout << "16-Search for a word in one language and return other languages" << endl;
    cout << "17-Quit" << endl;
    cout << "Enter your choice:";
    cin>>choice;
    return choice;

}

void createWordlist(fstream &file, int &s) {
    words word;
    int i = 1;
    if (s == 1) {
        if (file) {
            while (i <= 25) {
                cin.ignore();
                cout << "word:";
                getline(cin, word.word);
                file << word.word << "G";
                cin.ignore();
                cout << "\npart of speech:";
                getline(cin, word.part);
                cin.ignore();
                cout << "\nmeaning:";
                getline(cin, word.meaning);
                file << word.meaning << "G" << endl;
                i++;
            }
            file << "german";
            file.close();
        } else
            cout << "file doesn't exist or the memory is full";

    }
    if (s == 2) {
        if (file) {
            while (i <= 25) {
                cin.ignore();
                cout << "word:";
                getline(cin, word.word);
                file << word.word << "F";
                cin.ignore();
                cout << "\npart of speech:";
                getline(cin, word.part);
                file << word.part << "F";
                cin.ignore();
                cout << "\nmeaning:";
                getline(cin, word.meaning);
                file << word.meaning << "F" << endl;
                i++;
            }
            file << "german";
            file.close();
        } else
            cout << "file doesn't exist or the memory is full";

    }
    if (s == 3) {
        if (file) {
            while (i <= 25) {
                cin.ignore();
                cout << "word:";
                getline(cin, word.word);
                file << word.word << "L";
                cin.ignore();
                cout << "\npart of speech:";
                getline(cin, word.part);
                file << word.part << "L";
                cin.ignore();
                cout << "\nmeaning:";
                getline(cin, word.meaning);
                file << word.meaning << "L" << endl;
                i++;
            }
            file << "german";
            file.close();
        } else
            cout << "file doesn't exist or the memory is full";

    }
    if (s == 4) {
        if (file) {
            while (i <= 25) {
                cin.ignore();
                cout << "word:";
                getline(cin, word.word);
                file << word.word << "H";
                cin.ignore();
                cout << "\npart of speech:";
                getline(cin, word.part);
                file << word.part << "H";
                cin.ignore();
                cout << "\nmeaning:";
                getline(cin, word.meaning);
                file << word.meaning << "H" << endl;

                i++;
            }
            file.close();
        } else
            cout << "file doesn't exist or the memory is full";

    }
}
void transformTolowCase(string &source, string &dest){


  // Allocate the destination space
  dest.resize(source.size());

  // Convert the source string to lower case
  // storing the result in destination string
  std::transform(source.begin(),source.end(),dest.begin(),::tolower);

  
}
bool sortByword(const words &lhs, const words &rhs) 
{ 
    return lhs.word < rhs.word;
}
bool sortByMeaning(const words &lhs, const words &rhs) 
{ 
    return lhs.meaning < rhs.meaning;
}
void loadVectors(fstream &file, vector<words> &ger, vector<words> &fr, vector<words> &lat, vector<words> &heb) {
    words german, latin, hebrew, french;
    string destination;
    int i = 0;
    string germ; 
    if (file.is_open()) {

        file.seekp(0L, ios::beg);
        while ((!file.eof())&&(i++ <= 100)) {

            if (i <= 25) {
                getline(file, germ, 'G');
                transformTolowCase(germ,destination);
                german.word = destination;
                getline(file, germ, 'G');
                german.part = germ;
                getline(file, germ, 'G');
                german.meaning = germ;
                ger.push_back(german);
            }



            if (i > 25 && i <= 50) {

                getline(file, germ, 'F');
                french.word = germ;
                getline(file, germ, 'F');
                french.part = germ;
                getline(file, germ, 'F');
                french.meaning = germ;
                fr.push_back(french);

            }
            if (i >= 51 && i <= 75) {
                getline(file, germ, 'H');
                hebrew.word = germ;
                getline(file, germ, 'H');
                hebrew.part = germ;
                getline(file, germ, 'H');
                hebrew.meaning = germ;
                heb.push_back(hebrew);

            }
            if (i >= 76 && i <= 100) {
                getline(file, germ, 'L');
                latin.word = germ;
                getline(file, germ, 'L');
                latin.part = germ;
                getline(file, germ, 'L');
                latin.meaning = germ;
                lat.push_back(latin);


            }
        }

    } else
        cout << "the file cannot open";
}

void gerFrLatHebToEngAll(fstream &file, vector<words> &ger, vector<words> &fr, vector<words> &lat, vector<words> &heb) {
    words german, latin, hebrew, french;
    int i = 0;
    string germ;
    if (file.is_open()) {
        cout << "Words              Part of speech              Meanings" << endl;
        cout << "________________________________________________________" << endl;
        file.seekp(0L, ios::beg);
        while ((!file.eof())&&(i++ <= 100)) {

            if (i <= 25) {
                getline(file, germ, 'G');
                german.word = germ;
                cout << setw(12) << german.word;
                getline(file, germ, 'G');
                german.part = germ;
                cout << setw(20) << german.part;
                getline(file, germ, 'G');
                german.meaning = germ;
                cout << setw(20) << german.meaning;
                ger.push_back(german);
            }



            if (i > 25 && i <= 50) {

                getline(file, germ, 'F');
                french.word = germ;
                cout << setw(12) << french.word;
                getline(file, germ, 'F');
                french.part = germ;
                cout << setw(20) << french.part;
                getline(file, germ, 'F');
                french.meaning = germ;
                cout << setw(20) << french.meaning;
                fr.push_back(french);

            }
            if (i >= 51 && i <= 75) {
                getline(file, germ, 'H');
                hebrew.word = germ;
                cout << setw(12) << hebrew.word;
                getline(file, germ, 'H');
                hebrew.part = germ;
                cout << setw(12) << hebrew.part;
                getline(file, germ, 'H');
                hebrew.meaning = germ;
                cout << setw(20) << hebrew.meaning;
                heb.push_back(hebrew);

            }
            if (i >= 76 && i <= 100) {
                getline(file, germ, 'L');
                latin.word = germ;
                cout << setw(12) << latin.word;
                getline(file, germ, 'L');
                latin.part = germ;
                cout << setw(15) << latin.part;
                getline(file, germ, 'L');
                latin.meaning = germ;
                cout << setw(20) << latin.meaning;
                lat.push_back(latin);


            }
        }

        file.close();
    } else
        cout << "the file cannot open";
}
void gerFrLatHebToEngNouns(fstream &file,int num,string str){
vector<words> german, french, latin, hebrew;
    loadVectors(file, german, french, latin, hebrew);
    sort(german.begin(),german.end(),sortByword);
    sort(french.begin(),french.end(),sortByword);
    sort(latin.begin(),latin.end(),sortByword);
    sort(hebrew.begin(),hebrew.end(),sortByword);
    if (num == 1) {
        cout << "\german to english list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < german.size(); i++) {
            if (german[i].part == str) {
                cout << i + 1 << "-" << german[i].word << "  " << german[i].meaning << "  " << german[i].part << endl;
            }
            if ((german[i].part == "pronoun") || (german[i].part == "conjunction"))
                cout << i+1 << "-" << german[i].word << "  " << german[i].meaning << "  " << german[i].part << endl;


        }
    }
    if (num == 2) {
        cout << "\french to english list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < french.size(); i++) {
            if (french[i].part == str) {
                cout << i+1 << "-" << french[i].word << "  " << french[i].meaning << "  " << french[i].part << endl;
            }
            if ((french[i].part == "pronoun") || (french[i].part == "conjunction"))
                cout << i+1 << "-" << french[i].word << "  " << french[i].meaning << "  " << french[i].part << endl;

        }
    }
    if (num == 3) {
        cout << "\nenglish to latin list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < latin.size(); i++) {
            if (latin[i].part == str) {
                cout << i+1 << "-" << latin[i].word << "  " << latin[i].meaning << "  " << latin[i].part << endl;
            }
            if ((latin[i].part == "pronoun") || (latin[i].part == "conjunction"))
                cout << i+1 << "-" << latin[i].word << "  " << latin[i].meaning << "  " << latin[i].part << endl;

        }
    }
    if (num == 4) {
        cout << "\nenglish to hebrew list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < hebrew.size(); i++) {
            if (hebrew[i].part == str) {
                cout << i+1 << "-" << hebrew[i].word << "  " << hebrew[i].meaning << "  " << hebrew[i].part << endl;
            }
            if ((hebrew[i].part == "pronoun") || (hebrew[i].part == "conjunction"))
                cout << i+1 << "-" << hebrew[i].word << "  " << hebrew[i].meaning << "  " << hebrew[i].part << endl;

        }
    }


}

void entoGermFrLatHebPart(fstream &file, int num, string str) {
    vector<words> german, french, latin, hebrew;
    loadVectors(file, german, french, latin, hebrew);
    sort(german.begin(),german.end(),sortByMeaning);
    sort(french.begin(),french.end(),sortByMeaning);
    sort(latin.begin(),latin.end(),sortByMeaning);
    sort(hebrew.begin(),hebrew.end(),sortByMeaning);
    if (num == 1) {
        cout << "\nenglish to German list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < german.size(); i++) {
            if (german[i].part == str) {
                cout << i + 1 << "-" << german[i].meaning << "  " << german[i].word << "  " << german[i].part << endl;
            }
            if ((german[i].part == "pronoun") || (german[i].part == "conjunction"))
                cout << i+1 << "-" << german[i].meaning << "  " << german[i].word << "  " << german[i].part << endl;


        }
    }
    if (num == 2) {
        cout << "\nenglish to French list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < french.size(); i++) {
            if (french[i].part == str) {
                cout << i+1 << "-" << french[i].meaning << "  " << french[i].word << "  " << french[i].part << endl;
            }
            if ((french[i].part == "pronoun") || (french[i].part == "conjunction"))
                cout << i+1 << "-" << french[i].meaning << "  " << french[i].word << "  " << french[i].part << endl;

        }
    }
    if (num == 3) {
        cout << "\nenglish to latin list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < latin.size(); i++) {
            if (latin[i].part == str) {
                cout << i+1 << "-" << latin[i].meaning << "  " << latin[i].word << "  " << latin[i].part << endl;
            }
            if ((latin[i].part == "pronoun") || (latin[i].part == "conjunction"))
                cout << i+1 << "-" << latin[i].meaning << "  " << latin[i].word << "  " << latin[i].part << endl;

        }
    }
    if (num == 4) {
        cout << "\nenglish to hebrew list with " << str << " only" << endl;
        cout << "______________________________________" << endl;
        for (int i = 0; i < hebrew.size(); i++) {
            if (hebrew[i].part == str) {
                cout << i+1 << "-" << hebrew[i].meaning << "  " << hebrew[i].word << "  " << hebrew[i].part << endl;
            }
            if ((hebrew[i].part == "pronoun") || (hebrew[i].part == "conjunction"))
                cout << i+1 << "-" << hebrew[i].meaning << "  " << hebrew[i].word << "  " << hebrew[i].part << endl;

        }
    }


}

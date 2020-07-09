#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <regex>

using namespace std;

string _random(){
    // This functions generates a random number between 1-36665(Thats the limit of the index of wordlist) and returns a string.
    int i ;
    srand(time(0));
    i = rand() % 36665 + 1;
    // Use string stream to convert a number to string or vice versa
    stringstream ss;
    ss<<i;
    string index;
    ss>>index;
    //cout<<index<<endl;
    return index;
}
void _wordoftheday(){
    //this function generates a random english word
    string index = _random();
    string line;
    //Opening two files
    ifstream file_object("example_2.txt");
    ofstream file_2("collection.txt",ios::app);

    regex b("^"+index + "\\) ([a-zA-Z0-9- ]*)  (.*)");
    smatch match;
    if(file_object.is_open()){
        
        while(getline(file_object,line))
        {
            if(regex_search(line,match,b) == true){
                cout<<"The word of the day is: \n"<<match.str(1)<<endl;
                cout<<"Various meanings of "<<match.str(1)<<" in the English language are: \n";
                cout<<match.str(2)<<endl<<endl;
                cout<<"Enter 1-to add this word to your collection, 0-to pass."<<endl;
                int i;
                cin>>i;
                switch(i){
                    case 1:{
                        file_2<<"------------------------------------------------\n";
                        file_2<<"Word: "<<match.str(1)<<endl;
                        file_2<<"Meanings:\n"<<match.str(2)<<endl<<endl;
                        cout<<match.str(1)<<" was successfully added to your collection ≧◠‿◠≦ \n\n";
                        break;
                    }
                    case 0:{
                        cout<<"The word was skipped (◔◡◔)"<<endl<<endl;
                        break;
                    }
                    default:{
                        cout<<"The word was skipped due to wrong input. ( ˘︹˘ )"<<endl<<endl;
                    }
                }
            }
        }
        file_object.close();
        file_2.close();
    }
    else{
        cout<<"file not open";
        exit(0);
    }
}
void _search(){
    int temp=0;
    string to_search,line;
    cout<<"Enter a word to search(first letter uppercase, rest lowercase)"<<endl;
    cin>>to_search;

    regex b("[0-9]*\\) " + to_search + "-?  (.*)");
    smatch match;

    //Opening two files
    ifstream file_object("example_2.txt");
    ofstream file_2("collection.txt",ios::app);

    if(file_object.is_open())
        {
            while(getline(file_object,line))
            {
                if(regex_search(line,match,b) == true)
                {
                    temp++;
                    cout<<"The word you entered is: \n "<<to_search<<endl;
                    cout<<"Various meanings of "<<to_search<<" in the English language are: \n";
                    cout<<match.str(1)<<endl;
                    cout<<"Enter 1-to add this word to your collection, 0-to pass."<<endl;
                int i;
                cin>>i;
                switch(i){
                    case 1:{
                        file_2<<"------------------------------------------------\n";
                        file_2<<"Word: "<<to_search<<endl;
                        file_2<<"Meanings:\n"<<match.str(1)<<endl<<endl;
                        cout<<to_search<<" was successfully added to your collection ≧◠‿◠≦ \n\n";
                        break;
                    }
                    case 0:{
                        cout<<"The word was skipped (◔◡◔)"<<endl<<endl;
                        break;
                    }
                    default:{
                        cout<<"The word was skipped due to wrong input. ( ˘︹˘ ) "<<endl<<endl;
                    }
                }
                }
            }
            file_object.close();
            file_2.close();
            if(temp==0)
            {
                cout<<"Sorry! Could not find any such word in the database. (ㆆ_ㆆ)"<<endl;
            }
        }
    else
    {
        cout<<"file not open";
        exit(0);
    }

}
void _collection(){
    cout<<"------------WELCOME TO YOUR PERSONAL COLLECTION-------------"<<endl<<endl<<endl;
    ifstream file_object("collection.txt");
    string line;
    while(getline(file_object,line)){
        cout<<line<<endl;
    }
}
int main(){
    cout<<"--------------------- Welcome to Wordplay (͡• ͜ʖ ͡•) ---------------------------"<<endl<<endl;
    while(1){
        cout<<"Enter choice"<<endl<<"1 -to generate the Word of the day. \n2 -to search for a word.\n3 -to display your collection of words.\n4 -to quit WordPlay"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:{
                _wordoftheday();
                break;
            }
            case 2:{
                _search();
                break;
            }
            case 3:{
                _collection();
                break;
            }
            case 4:{
                cout<<"Thanks for using WordPlay !";
                exit(3);
            }
            default:{
                cout<<"Wrong input!\n\n";
            }
        }
    }
}
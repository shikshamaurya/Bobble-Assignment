#include <bits/stdc++.h>
using namespace std;

struct trie{
    struct trie *child[26];
    int value;
    bool isEndOfWord;

    trie(){
        memset(child,0,sizeof(child));
        isEndOfWord=false;
        value=0;
    }
    trie(int valueue){
      memset(child,0,sizeof(child));
      value=valueue;
        isEndOfWord=false;
    }
};
struct trie *root=NULL;
int findFrequency(string str){
    struct trie *current=root;
    int index;
    for(char ch :str){  //for each loop taking each character in ch from string str
         index=ch-'a';
        current = current->child[index];
    }
    return current->value;
}
bool search(string str){

    struct trie *current=root;
    int index;
    for(char ch :str){
        if(ch >=65 && ch<=90)
          index=ch-'A';
        else
          index=ch-'a';
        if(current->child[index]==NULL)
            return false;
        current = current->child[index];
    }
    return current->isEndOfWord;
}
void insert(string str,int key){

    struct trie *current=root,*temp=root;
    int index;
    for(char ch : str){
        if(ch >=65 && ch<=90)
          index=ch-'A';
        else
          index=ch-'a';
        if(current->child[index]==NULL){
            current->child[index] = new trie;
        }
        current=current->child[index];
    }
    current->value=key;
    current->isEndOfWord=true;
}

void readCsvFileAndInsert() {
   string filename="EnglishDictionary.csv"; //The file name should be in same directory
   ifstream fp(filename);// fp is a file pointer
   string word;
   string frequency;
    if(!fp.is_open())//if file not found
            cout<<"file not open";
   while(fp.good()){  // if file exist
    getline(fp,word,',');
    getline(fp,frequency,'\n');

    insert(word,stoi(frequency));//it will insert the word in trie data structure
   }
   fp.close();//closing the file
}

int main(){

    root = new trie;
    readCsvFileAndInsert();
    int t;
    cin>>t;
    while(t--){
        string word_to_search;
        cin>>word_to_search;

        if(search(word_to_search)){
            cout<<"YES, "<<findFrequency(word_to_search)<<endl;

        }
        else
            cout<<"NO"<<endl;
    }
}

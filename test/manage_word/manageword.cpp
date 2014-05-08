#include"manageword.h"
using namespace std;

ManageWord::ManageWord():_word_vector(),_word_map(),_q(){}

ManageWord::~ManageWord()
{
}

static std::ifstream &open_file(std::ifstream &is, const std::string &filename)
{
  is.close();
  is.clear();
  is.open(filename.c_str());
  return is;
}

void ManageWord::read_word(const std::string &filename)
{
  std::ifstream infile;
  int num1=0,num2=0;
  if(!open_file(infile, filename))
  {
   std::cout<<"open file failed!"<<std::endl;
  }
  std::string word;
  std::string line;
  while(getline(infile, line)){
   for(int ix=0;ix!=line.size();++ix){
     if(line[ix]>='a'&&line[ix]<='z') {}
     else if(line[ix]>='A'&&line[ix]<='Z') {}
     else line[ix]=' '; 
    }
   istringstream stream(line);
    while(stream>>word)
    {
  // _word_vector.push_back(word);
   num1++;
   ++_word_map[word];
    }
 }
 map<string, int>::iterator map_it=_word_map.begin();
 for(;map_it!=_word_map.end();++map_it){
  _word_vector.push_back(map_it->first);
 num2++; 
}
  std::cout<<"repeated words have:  "<<num1<<std::endl;
  std::cout<<"unrepeated words have:  "<<num2<<std::endl;
}

void ManageWord::show_vec()
{
  std::vector<std::string>::size_type ix=0;
  for(;ix!=_word_vector.size();++ix)
  {
    cout<<_word_vector[ix]<<endl; 
  }

}
std::vector<std::string> &ManageWord::get_vector(){
   return _word_vector;
}

std::map<std::string, int> &ManageWord::get_map(){
   return _word_map;
}

void ManageWord::frequency(std::string &query){
   std::map<std::string, int>::iterator map_it=_word_map.find(query);
   if(map_it!=_word_map.end()){
    std::cout<<"frequency: "<<map_it->second<<std::endl;
   } 
   else{
    std::cout<<"no match for query"<<std::endl;
   }
}  

static int min(int a, int b, int c){
   int t= a<b?a:b;
   return t<c?t:c;
}

static int ED(const string &a, const string &b){
    int len1=a.size();
    int len2=b.size();
    int d[len1+1][len2+1];
    int i,j;
    for(i=0;i<=len1;i++)
       d[i][0]=i;
    for(j=0;j<=len2;j++)
       d[0][j]=j;
    for(i=1;i<=len1;i++){
      for(j=1;j<=len2;j++){
        int cost=(a[i-1]==b[j-1]?0:1);
        int del=d[i-1][j-1]+1;
        int inc=d[i][j-1]+1;
        int sub=d[i-1][j-1]+cost;
        d[i][j]=min(del, inc, sub);
      }
    }
     return d[len1][len2];
}
void ManageWord::find_similar_word(std::string &query)
{
   vector<string>::size_type ix=0;
   int min=ED(query, _word_vector[ix]);
   int result;
   string correct_word;
   for(ix=1;ix!=_word_vector.size();++ix){
    int num=ED(query, _word_vector[ix]);
    if(min>num){
       min=num;
       result=ix;
      }
    }
   std::cout<<"the most similar word: "<<_word_vector[result]<<std::endl;
}

void ManageWord::find_top3_similar_word(std::string &query){
  int ix=0;
  map<string , int>::iterator map_it=_word_map.begin();
  for(;map_it!=_word_map.end();++map_it){
  _q.push(Word_fre(ix, ED(query, map_it->first), map_it->second));
  ++ix; 
  }  
  Word_fre a=_q.top();
  _q.pop();
  Word_fre b=_q.top();
  _q.pop();
  Word_fre c=_q.top();
  std::cout<<_word_vector[a._ix]<<" "<<_word_vector[b._ix];
  std::cout<<" "<<_word_vector[c._ix]<<std::endl; 

}

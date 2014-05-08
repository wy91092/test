#ifndef _MANAGEWORD_H_
#define _MANAGEWORD_H_
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<queue>
#include<algorithm>
struct Word_fre
{
   int _ix;         //对应的vector的下标
   int _edit;       //每一个词的编辑距离
   int _fre;        //词频
   Word_fre(int ix, int edit, int fre):_ix(ix),_edit(edit),_fre(fre){

  }
};

struct compare{
   bool operator()(const Word_fre &a, const Word_fre &b){
      if(a._edit!=b._edit){
         return a._edit>b._edit;
     }else return a._fre<b._fre;
   }
};

class ManageWord
{
private:
  std::vector<std::string> _word_vector;
  std::map<std::string, int> _word_map;
  std::priority_queue<Word_fre,std::vector<Word_fre>,compare> _q;
public:
  ManageWord();
  ~ManageWord();
  void read_word(const std::string &filename);
  std::vector<std::string> &get_vector();  
  void show_vec();
  std::map<std::string, int> &get_map();
  void frequency(std::string &query);  //全局词频  
  void find_similar_word(std::string &query);
  void find_top3_similar_word(std::string &query);
};
#endif

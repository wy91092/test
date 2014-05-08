#include"manageword.h"
using namespace std;
int main(int argc, char **argv)
{
  std::string filename=argv[1];
  ManageWord test;
  test.read_word(filename);
//  test.show();
  while(true){
  std::string query;
  std::cin>>query;
  test.frequency(query);
  test.find_similar_word(query);
  test.find_top3_similar_word(query);
  }
  return 0;

}

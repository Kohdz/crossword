#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Grid {

  Grid(string n){
    name = n;
  }

  // Call these on loaded grid!
  int rows() const { 
    if (lines.empty()) {
      return 0;
    } else {
      return lines[0].size();
    }
  }

  int cols() const { 
    assert(!lines.empty());
    return lines[0].size();
  }
	
  void Load() {
    lines.push_back("DOG....");
    lines.push_back("---....");
    lines.push_back("----...");
    lines.push_back("-------");
    lines.push_back("...----");
    lines.push_back("....---");
    lines.push_back("....CAT");
  }

  void Check() const {
    for (int i = 0; i < lines.size(); i ++){
      assert(lines[i].size() == cols());
    }  
  }
  
  void Print(){

    cout << "Grid: " << name
        << "(rows=" << rows()
        << ", cols=" << cols() << ")\n";	
    for (string s: lines){
      cout << " " << s << "\n";
    }
  }
  string name; 
  vector<string> lines;
};

int main(){
  Grid grid("MY GRID");
  
  //grid.name = "MY GRID";

  grid.Load();
  grid.Check(); 
  grid.Print();

  return 0;
};

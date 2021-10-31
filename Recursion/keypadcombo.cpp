#include<iostream>
#include<vector>
#include<string>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};



vector<string> getallcombos(string keycom){

    if(keycom.length()==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    string ch_at_0_keycom = keycom.substr(0,1);
    int fkeynum = stoi(ch_at_0_keycom);
    string keysub = keycom.substr(1);
    vector<string> res = getallcombos(keysub);
    vector<string> mres;

    string stringatfkeynum = codes[fkeynum];
    for(int i=0; i<stringatfkeynum.length(); i++){
        string ch = stringatfkeynum.substr(i, i+1);
        for(int j=0; j<res.size(); j++){
            mres.push_back(ch + res[j]);
        }

    }

    return mres;

}

int main(){
    string keycom = "678";
    vector<string> result = getallcombos(keycom);
    cout<<result.size()<<endl;
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<", ";
    }
    return 0;
}


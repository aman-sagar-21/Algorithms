#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if (n <= 1)
        return false;
  
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

int main(){

    int n; cin>>n;
    vector<long int> q(n);
    vector<string> ele(n);

    for(int i=0; i<n; i++){
        cin>>ele[i];
    }

    for(int i=0; i<n; i++){
        string s = ele[i];
        int j = 0;
        string num = "";
        while(isdigit(s[j])){
            num += s[j];
            j++;
        }

        q[i] = stoi(num);
    }

    vector<string> emo(n);
    for(int i=0; i<n; i++){
        cin>>emo[i];
    }

    unordered_map<string, int> emotions;
    emotions["Happy"] = 10;
    emotions["Sad"] = 5;
    emotions["Neutral"] = 2;
    emotions["None"] = 1;

    int score = 0;
    for(int i=0; i<n; i++){
        score += q[i]*emotions[emo[i]];
    }

    int vowels = 0;
    for(int i=0; i<n; i++){
        string s = ele[i];
        int n = 0;
        for(long unsigned int i=0; i<s.size(); i++){
            if(
                s[i]=='A' || s[i]=='a' ||
                s[i]=='E' || s[i]=='e' ||
                s[i]=='I' || s[i]=='i' ||
                s[i]=='O' || s[i]=='o' ||
                s[i]=='U' || s[i]=='u'
            ) n++;
        }
        vowels += n*q[i];
    }

  	score/=vowels;
    
    if(isPrime(score)) cout<<"Yes"<<" ";
    else cout<<"No ";

    vector<string> number(10);
    number[0] = "Zero";
    number[1] = "One";
    number[2] = "Two";
    number[3] = "Three";
    number[4] = "Four";
    number[5] = "Five";
    number[6] = "Six";
    number[7] = "Seven";
    number[8] = "Eight";
    number[9] = "Nine";

    cout<<number[score];

    return 0;

}
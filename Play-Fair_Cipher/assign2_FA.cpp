// Color Codes
// [0;31m	Red
// [1;31m	Bold Red
// [0;32m	Green
// [1;32m	Bold Green
// [0;33m	Yellow
// [01;33m	Bold Yellow
// [0;34m	Blue
// [1;34m	Bold Blue
// [0;35m	Magenta
// [1;35m	Bold Magenta
// [0;36m	Cyan
// [1;36m	Bold Cyan
// [0m	Reset

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// string cipher = "B MH AFC MUVY EOHPTCS, AFCSS TE QCSI NTYIMS TNA AFCSC. EMRBH XAA VAFR MIUCQPUH \"LMRL_CCETOT\" FN HM AKUXAHK. OTA WANA OTXT FFU EISCWNAF HME BFU MCVA UGTOTRE. BM HYLF IFU UVTY ANE HBSEI QYOQM OUVSF AM EAFTE PYHYS XNSKE IFUSC.";
// string cipher = "J IF GOU TWDU CUQHAEA, WDIBK AG YYQO WLFKUO RTJ SMEAY. CSATO ZIW TGOJ TKCYOVDZ \"SOZH_AINLVV\" NJ FS JCBZIDI. UCS DCVW MZGL MHC AGYLOUCN DKK KXB OKRY APLVVZA. ZS QQSH QBS AELF CVA FHBWP SGKOS XMCUN WK KJXAG XUFEB PUUSA GLDKJ.";
string cipher = "Be wary of the next chamber, there is very little joy there. Speak out the password \"the cave man be pleased\" to go through. May you have the strength for the next chamber. To find the exit you first will need to utter magic words there.";
unordered_map<char,char> sbstn; //substitution hash map

void show_message(){
    char k;
    for(int i=0; i<cipher.length();i++){
        char c = tolower(cipher[i]);
        if(sbstn.find(c)!=sbstn.end()){
            printf("\033[1;31m");
            if(cipher[i]<'a' and cipher[i]>='A') {
                k = sbstn[c];
                k = toupper(k);
                cout<<k;
            }
            else printf("%c",sbstn[c]);
            printf("\033[0m");
        }
        else {
            if(cipher[i]<'a' and cipher[i]>='A') {
                k = toupper(c);
                cout<<k;
            }
            cout<<c;
        }
    }
    cout<<endl;
}


int main(){
    unordered_map<char,double> hash;
    multimap<double,char,greater<double>> freq; //stores frequency
    int totl_letters=0;
    for(int i=0; i<cipher.length();i++){
        char c = tolower(cipher[i]);
        if(isalpha(c)){
            totl_letters++;
            if(hash.find(c)==hash.end()) hash[c] = 1;
            else hash[c]++;
        }
    }
    for(auto it=hash.begin();it!=hash.end();it++){
        it->second = (it->second/totl_letters)*100;
        // freq[it->second] = it->first;
        freq.insert({it->second,it->first});
    }
    cout<<"Frequency Analysis:\n";
    for(auto it=freq.begin();it!=freq.end();it++){
        cout<<it->second<<" - "<<it->first<<"%"<<endl;
    }
    cout<<endl;

    #define BLK_LEN 5
    vector<string> str;
    string temp="";
    int block =BLK_LEN;
    cout<<"(";
    for(int i =0; i<cipher.length();i++){
        if(isalpha(cipher[i])){
            temp = temp+cipher[i];
            block--;
        }
        cout<<cipher[i];
        if(!block){
            block =BLK_LEN;
            str.push_back(temp);
            temp="";
            cout<<")(";
        }
    }

    for(int i =0; i<str.size();i++) cout<<i<<" : "<<str[i]<<endl;

	return 0;
}
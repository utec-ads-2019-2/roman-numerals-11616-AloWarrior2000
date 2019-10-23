#include <iostream>
#include <vector>

using namespace std;

bool rom_verifier(const string& number){
    for (char i : number){
        if (!(i=='I' || i=='V' || i=='X' || i=='L' || i=='C' || i=='D' || i=='M')) return false;
    }
    return true;
}

bool ara_verifier(const string& number){
    for (char i : number){
        if (!isdigit(i)) return false;
    }
    return true;
}

string ara_to_rom(int ara){
    int n;
    string ans;
    n = ara%10;
    switch (n){
         case 1: ans = "I"; break;
         case 2: ans = "II"; break;
         case 3: ans = "III"; break;
         case 4: ans = "IV"; break;
         case 5: ans = "V"; break;
         case 6: ans = "VI"; break;
         case 7: ans = "VII"; break;
         case 8: ans = "VIII"; break;
         case 9: ans = "IX"; break;
         case 0: ans = ""; break;
    }
    ara/=10;
    if (ara > 0){
        n = ara%10;
        switch (n) {
            case 1: ans = "X" + ans; break;
            case 2: ans = "XX" + ans; break;
            case 3: ans = "XXX" + ans; break;
            case 4: ans = "XL" + ans; break;
            case 5: ans = "L" + ans; break;
            case 6: ans = "LX" + ans; break;
            case 7: ans = "LXX" + ans; break;
            case 8: ans = "LXXX" + ans; break;
            case 9: ans = "XC" + ans; break;
            case 0: ans = "" + ans; break;
        }
        ara/=10;
        if (ara > 0){
            n = ara%10;
            switch (n) {
                case 1: ans = "C" + ans; break;
                case 2: ans = "CC" + ans; break;
                case 3: ans = "CCC" + ans; break;
                case 4: ans = "CD" + ans; break;
                case 5: ans = "D" + ans; break;
                case 6: ans = "DC" + ans; break;
                case 7: ans = "DCC" + ans; break;
                case 8: ans = "DCCC" + ans; break;
                case 9: ans = "CM" + ans; break;
                case 0: ans = "" + ans; break;
            }
            ara/=10;
            if (ara > 0){
                switch (ara){
                    case 1: ans = "M" + ans; break;
                    case 2: ans = "MM" + ans; break;
                    case 3: ans = "MMM" + ans; break;
                }
            }
        }
     }
    return ans;
}


int rom_to_ara(string rom){
    int ans = 0;
    int size = rom.size();
    for(unsigned int i = 0; i < size; ++i) {
        if (rom[0] == 'M') {
            ans += 1000;
            rom.erase(rom.begin());
        } else if (rom[0] == 'D'){
            ans+=500;
            rom.erase(rom.begin());
        } else if (rom[0] == 'C'){
            if (rom[1] == 'D'){
                ans+=400;
                rom.erase(rom.begin());
            } else if (rom[1] == 'M'){
                ans+=900;
                rom.erase(rom.begin());
            } else {
                ans+=100;
            }
            rom.erase(rom.begin());
        } else if (rom[0] == 'L'){
            ans+=50;
            rom.erase(rom.begin());
        } else if (rom[0] == 'X'){
            if (rom[1] == 'L'){
                ans+=40;
                rom.erase(rom.begin());
            } else if (rom[1] == 'C'){
                ans+=90;
                rom.erase(rom.begin());
            } else {
                ans+=10;
            }
            rom.erase(rom.begin());
        } else if (rom[0] == 'V'){
            ans+=5;
            rom.erase(rom.begin());
        } else if (rom[0] == 'I'){
            if (rom[1] == 'V'){
                ans+=4;
                rom.erase(rom.begin());
            } else if (rom[1] == 'X'){
                ans+=9;
                rom.erase(rom.begin());
            } else {
                ans+=1;
            }
            rom.erase(rom.begin());
        }
    }
    return ans;

}



int main() {
    string number;
    while (cin >> number) {
        if (ara_verifier(number)){
            cout << ara_to_rom(stoi(number));
        }
        else if (rom_verifier(number)){
            cout << rom_to_ara(number);
        }
        else{ cout << "ERROR";}
        cout << endl;
    }
        return 0;
}

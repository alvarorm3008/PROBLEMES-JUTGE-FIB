 #include <iostream>
 #include <map>
 using namespace std;
 
 
 struct Info {
   string code;
   int price;
 };
 
 
 int main() {
   map<int, Info> M; //int es el length
   char c;
   while (cin >> c) {
     if (c == 'n') {
       cout << "num: " << M.size() << endl;
     }
     else if (c == 'u') {
       string code;
       int length, price;
       cin >> code >> length >> price;
       auto it = M.find(length);
       if (it != M.end()) {
        it->second.code = code;
        it->second.price = price;
       }
       else M.insert({length, {code, price}});
       
     }
     else if (c == 'q') {
       int length;
       cin >> length;
       auto it = M.find(length);
       if (it != M.end()) cout << it->second.price << endl;
       else cout << -1 << endl;

     }
     else if (c == 'p') {
       cout << string(10, '-') << endl;
        for (auto it = M.begin(); it != M.end(); ++it) {
            cout << it->second.code << ' ' << it->second.price << ' ' << it->first << endl;
        }
       cout << string(10, '*') << endl;
     }
     else { // c == ’s’
        auto it = M.begin();
        ++it;
        if (it != M.end()) cout << it->second.code << ' ' << it->first << ' ' << it->second.price << endl;
        else cout << "no" << endl;
     }
   }
 }
// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    std::string s = "";
    TStack<char, 100> st;
    int len = inf.length();
    for (int i = 0; i < len; i++) {
        std::string var;
        int pr = 0;
        if (inf[i] > '0' && inf[i] < '9') s += inf[i];
        else {
            switch (inf[i]) {
            case '(': pr = 0; break;
            case ')': pr = 1; break;
            case '+': pr = 2; break;
            case '-': pr = 2; break;
            case '*': pr = 3; break;
            case '/': pr = 3; break;
            }

            if (pr == 0 || st.getTop() == 0) {
                st.push(inf[i]);
            }
            else if(pr == 1){
                while ((var = st.pop()) != "(") s += var;
            }
            else if (pr > st.getPriority()) {
                st.push(inf[i]);
            }
            else {
                while (pr <= st.getPriority()) {
                    s += st.pop();
                }
                st.push(inf[i]);
            }
        }
    }
    while (st.getTop() != 0) {
        s += st.pop();
    }
    return s;

}

int eval(std::string pref) {
    TStack<char, 100> st;
    int len = pref.length();
    int var1, var2, res;
    for (int i = 0; i < len; i++) {
        if (pref[i] > '0' && pref[i] < '9') {
            st.push(pref[i]);
        }
        else {
            var1 = st.pop() - '0';
            var2 = st.pop() - '0';
            switch (pref[i]) {
            case '+': res = var2 + var1; break;
            case '-': res = var2 - var1; break;
            case '*': res = var2 * var1; break;
            case '/': res = var2 / var1; break;
            }
            st.push((char)(res + 48));
        }
    }
    return st.pop() - '0';
}

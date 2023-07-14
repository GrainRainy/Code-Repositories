#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define DEBUG(x) cout << #x << ' ' << x << '\n';
#define endl '\n'

const int N = 12;
const int M = 2e3 + 10;
int n, m; 
string totCard[M]; int totCardTop = 1; // iterator for card top 
string guessingIdentity[N]; 
int nxt[N], pre[N], chainLenth;

bool checkDead(int u);
bool askForJ(int originPos);
void ProcessingN(int pos);
void printResult();
void processingF(int ori, int target);
void processingN(int originPos);
void processingW(int originPos);

struct Pig {
	int sitPos;
	string identity, card[M]; 
	int cardTop; bool used[M]; // iterator for personal card top 
	int resBlood, maxBlood;
	bool equipment, dead;
	void init(int i) { sitPos = i; resBlood = maxBlood = 4; equipment = false; }
	int findBeProtectTarget();
	int findAttackTarget(int distanceLimit);
    int findCardAs(string a);
    void processingRound();
}pig[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> pig[i].identity;
		for (int j = 1; j <= 4; ++ j)
			cin >> pig[i].card[j];
		pig[i].init(i);
        nxt[i] = i + 1, pre[i] = i - 1;
	} 
    pre[1] = n, nxt[n] = 1, chainLenth = n;
	guessingIdentity[1] = "MP";
	for (int i = 1; i <= m; ++ i) cin >> totCard[i];
	for (int i = 1; chainLenth; i = nxt[i]) pig[i].processingRound();
	return 0;
}

void printResult() {
	bool beFP = false;
	for (int i = 1; i <= n; ++ i) {
		if (pig[i].identity == "MP" and pig[i].dead) { 
			cout << "FP" << endl;
			break; 
		}
		beFP |= (pig[i].identity == "FP" and pig[i].dead);
	}
	if (!beFP) cout << "MP" << endl;
	for (int i = 1; i <= n; ++ i) {
		if (pig[i].dead) cout << "DEAD" << endl;
		else for (int j = 1; j <= pig[i].cardTop; ++ j) 
			if (!pig[i].used[i]) cout << pig[i].card[i] << " \n"[j == pig[i].cardTop];
	}
}

bool checkDead(int u) {
    if (pig[u].resBlood) return false;
    int pos;
    if (pos = pig[u].findCardAs("P")) {
        pig[u].used[pos] = true;
        pig[u].resBlood ++;
        return false;
        nxt[pre[u]] = nxt[u];
        pre[nxt[u]] = pre[u];
        chainLenth --;
    } else return pig[u].dead = true;
}

bool checkEnd() {

}

bool askForJ(int originPos) {

}

void processingF(int ori, int target) {
    if (pig[ori].identity == "MP" and pig[target].identity == "ZP") {
        pig[target].resBlood --;
        if (checkDead(target)) { printResult(); exit(0); }
        return;
    }
    int posa = 1, posb = 1;
    while (posa <= pig[ori].cardTop and posb <= pig[target].cardTop) {
        while (posb <= pig[target].cardTop and pig[target].card[posb] != "K") posb ++;
        if (posb > pig[target].cardTop) {
            pig[target].resBlood --;
            if (checkDead(target)) { printResult(); exit(0); }
            return;
        }
        while (posa <= pig[ori].cardTop and pig[ori].card[posa] != "K") posa ++;
        if (posa > pig[ori].cardTop) {
            pig[ori].resBlood --;
            if (checkDead(pig[ori].sitPos)) { printResult(); exit(0); }
            return;
        }
    }
}

void processingN(int originPos) {
    for (int i = originPos + 1, cnt = 1; cnt < chainLenth; i = nxt[i]) {
        if (askForJ(originPos)) continue;
        int pos = 0;
        if (pos = pig[i].findCardAs("K")) { pig[i].used[pos] = true; continue; }
        pig[i].resBlood --;
        if (checkDead(i)) { printResult(); exit(0); } 
    }
}

void processingW(int originPos) {
    for (int i = originPos + 1, cnt = 1; cnt < chainLenth; i = nxt[i]) {
        if (askForJ(originPos)) continue;
        int pos = 0;
        if (pos = pig[i].findCardAs("K")) { pig[i].used[pos] = true; continue; }
        pig[i].resBlood --;
        if (checkDead(i)) { printResult(); exit(0); }
    }
}

int Pig::findBeProtectTarget() {
    for (int i = sitPos + 1, cnt = 1; cnt < chainLenth; i = nxt[i]) {
        if (pig[i].dead) continue;
        bool f = false;
        f |= (guessingIdentity[sitPos] == "MP" and pig[i].identity == "ZP");
        f |= (guessingIdentity[sitPos] == "ZP" and pig[i].identity == "ZP");
        f |= (guessingIdentity[sitPos] == "FP" and pig[i].identity == "FP");
        if (f) return i;
    }
    return 0;
}

int Pig::findAttackTarget(int distanceLimit) {
    if (identity == "FP") {
        for (int i = sitPos + 1, cnt = 1; cnt < chainLenth and cnt <= distanceLimit; i = nxt[i]) {
            if (pig[i].dead) continue;
            if (pig[i].identity == "MP") return i;
            cnt ++;
        }
        for (int i = sitPos + 1, cnt = 1; cnt < chainLenth and cnt <= distanceLimit; i = nxt[i]) {
            if (pig[i].dead) continue;
            if (pig[i].identity == "ZP") return i;
            cnt ++;
        }
        return 0;
    } 
    for (int i = sitPos + 1, cnt = 1; cnt < chainLenth and cnt <= distanceLimit; i = nxt[i]) {
        bool f = false;
        f |= (identity == "MP" and guessingIdentity[i] == "SFP");
        f |= (guessingIdentity[i] == "FP");
        if (f) return i;
        cnt ++;
    }
    return 0;
}

int Pig::findCardAs(string a) {
    for (int i = 1; i <= cardTop; ++ i)
        if (!used[i] and card[i] == a) return i;
    return 0;
}

void Pig::processingRound() {
    card[++ cardTop] = totCard[totCardTop ++];
    card[++ cardTop] = totCard[totCardTop ++];
    bool beenUsedK = false;
    bool usedCard = true;
    while (usedCard) {
        usedCard = false;
        for (int i = 1; i <= cardTop; ++ i) {
            if (used[i]) continue;
            else {
                if (card[i] == "P" and resBlood < maxBlood) {
                    used[i] = true; resBlood ++;
                } else if (card[i] == "K" and (!beenUsedK or equipment)) {
                    int target = findAttackTarget(1);
                    if (!target) continue;
                    beenUsedK = true;
                    int pos = pig[target].findCardAs("D");
                    if (pos) { pig[target].used[pos] = true; continue; }
                    pig[target].resBlood --;
                    if (checkDead(target)) { printResult(); exit(0); } 
                } else if (card[i] == "F") {
                    int target = findAttackTarget(n);
                    if (!target) continue;
                    processingF(sitPos, target);
                } 
                else if (card[i] == "N") processingN(sitPos);
                else if (card[i] == "W") processingW(sitPos);
                else equipment = true;
                usedCard = true;
                break;
            }
        }
    }
}


#include <iostream>
#include <string>

#define MAX_N 150000

using namespace std;

// 변수 선언
int n;

int p2[31] = {1, };
int a[MAX_N];

// 숫자를 31자리 2진수 문자열로 변환해줍니다.
string convert_to_string(int x) {
    string ret = "";
    for(int i = 30; i >= 0; i--) {
        if(x >= p2[i]) {
            x -= p2[i];

            ret += "1";
        }
        else
            ret += "0";
    }

    return ret;
}

// Trie에 사용되는 노드를 정의합니다.
class TrieNode {
    public:
        // 각 노드에는 '0'부터 '1'까지의 문자에 대응되는 2개의 노드 정보가 관리됩니다.
        TrieNode *children[2];

        // 생성자입니다.
        TrieNode() {
            // 각 문자에 대응되는 노드 정보는 처음에 nullptr이 됩니다.
            for(int i = 0; i < 2; i++)
                children[i] = nullptr;
        }
};

// 루트 노드에 해당하는 TrieNode를 처음 만들어줍니다.
TrieNode *root = new TrieNode();

// 단어 s를 Trie에 넣어줍니다.
void InsertWord(string s) {
    // root에서 시작합니다.
    TrieNode *t = root;
    for(int i = 0; i < (int) s.size(); i++) {
        // 문자 순서대로 따라가면 됩니다.
        // '0'부터 '1'까지 사용되므로
        // 각각을 0부터 1까지의 index로 매핑시켜줍니다.
        int index = s[i] - '0';
        // 해당하는 노드가 아직 없다면 새로운 노드를 만들어줍니다.
        if(t->children[index] == nullptr)
            t->children[index] = new TrieNode();
        
        // index에 해당하는 노드로 옮겨갑니다.
        t = t->children[index];
    }
}

// Trie에서 각 단어들을 xor한 최댓값을 탐색합니다.
// 각 자릿수에서 xor했을 때 1이 될 수 있도록 탐색하며 내려갑니다.
int SearchWord(string s) {
    string ret = "";

    // root에서 시작합니다.
    TrieNode *t = root;
    for(int i = 0; i < (int) s.size(); i++) {
        int index = s[i] - '0';

        // 만약 1 - index가 있다면, 그쪽으로 따라갑니다.
        if(t->children[1 - index] != nullptr) {
            t = t->children[1 - index];

            ret += "1";
        }
        // 없다면 반대쪽으로 따라갑니다.
        else {
            t = t->children[index];

            ret += "0";
        }
    }

    // ret 문자열을 십진수로 표현해서 출력합니다.
    int return_value = 0;
    for(int i = 0; i < ret.length(); i++) {
        return_value *= 2;
        return_value += (ret[i] - '0');
    }

    return return_value;
}

int main() {
    // p2[i] = 2의 i제곱. 값들을 계산하기에 앞서 미리 전처리합니다.
    for(int i = 1; i <= 30; i++)
        p2[i] = p2[i - 1] * 2;

    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // Trie에 단어들을 넣어줍니다.
    for(int i = 0; i < n; i++)
        InsertWord(convert_to_string(a[i]));
    
    // Trie에서 각 단어들을 xor한 최댓값을 탐색합니다.
    // 각 자릿수에서 xor했을 때 1이 될 수 있도록 탐색하며 내려갑니다.
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int num = SearchWord(convert_to_string(a[i]));

        ans = max(ans, num);
    }
    
    // 답을 출력합니다.
    cout << ans;

    return 0;
}
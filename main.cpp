#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    string name;
    vector<Node*> children;
    Node(string n) : name(n) {}
};

bool getPath(Node* root, string target, vector<string>& path) {
    if (root == nullptr) return false;
    path.push_back(root->name);
    if (root->name == target) return true;
    for (Node* child : root->children) {
        if (getPath(child, target, path)) return true;
    }
    path.pop_back();
    return false;
}

string findCommonAncestor(Node* root, string lang1, string lang2) {
    vector<string> path1, path2;
    if (!getPath(root, lang1, path1) || !getPath(root, lang2, path2)) {
        return "Error";
    }
    string common = "";
    int minLen = min(path1.size(), path2.size());
    for (int i = 0; i < minLen; i++) {
        if (path1[i] == path2[i]) {
            common = path1[i];
        } else {
            break;
        }
    }
    return common;
}

int main() {
    // Create language tree
    Node* root = new Node("Indo-European");
    Node* arabic = new Node("Arabic");
    Node* english = new Node("English");

    root->children.push_back(arabic);
    root->children.push_back(english);

    // Arabic dialects
    Node* egyptian = new Node("Egyptian");
    Node* levantine = new Node("Levantine");
    Node* gulf = new Node("Gulf");
    arabic->children.push_back(egyptian);
    arabic->children.push_back(levantine);
    arabic->children.push_back(gulf);

    // English dialects
    Node* british = new Node("British");
    Node* american = new Node("American");
    Node* australian = new Node("Australian");
    english->children.push_back(british);
    english->children.push_back(american);
    english->children.push_back(australian);

    map<int, string> languages;
    languages[1] = "Arabic";
    languages[2] = "English";

    map<string, vector<string>> dialects;
    dialects["Arabic"] = {"Egyptian", "Levantine", "Gulf"};
    dialects["English"] = {"British", "American", "Australian"};

    // First selection
    cout << "\n===== LANGUAGE TREE FINDER =====\n";
    cout << "\nChoose first language:\n";
    cout << "1. Arabic\n";
    cout << "2. English\n";
    cout << "Your choice: ";
    int langChoice1;
    cin >> langChoice1;

    if (langChoice1 < 1 || langChoice1 > 2) {
        cout << "Invalid choice!\n";
        return 1;
    }

    string selectedLang1 = languages[langChoice1];
    vector<string>& dia1 = dialects[selectedLang1];

    cout << "\nChoose first dialect from " << selectedLang1 << ":\n";
    for (int i = 0; i < dia1.size(); i++) {
        cout << (i+1) << ". " << dia1[i] << "\n";
    }
    cout << "Your choice: ";
    int diaChoice1;
    cin >> diaChoice1;

    if (diaChoice1 < 1 || diaChoice1 > dia1.size()) {
        cout << "Invalid choice!\n";
        return 1;
    }

    string selected1 = dia1[diaChoice1 - 1];

    // Second selection
    cout << "\nChoose second language:\n";
    cout << "1. Arabic\n";
    cout << "2. English\n";
    cout << "Your choice: ";
    int langChoice2;
    cin >> langChoice2;

    if (langChoice2 < 1 || langChoice2 > 2) {
        cout << "Invalid choice!\n";
        return 1;
    }

    string selectedLang2 = languages[langChoice2];
    vector<string>& dia2 = dialects[selectedLang2];

    cout << "\nChoose second dialect from " << selectedLang2 << ":\n";
    for (int i = 0; i < dia2.size(); i++) {
        cout << (i+1) << ". " << dia2[i] << "\n";
    }
    cout << "Your choice: ";
    int diaChoice2;
    cin >> diaChoice2;

    if (diaChoice2 < 1 || diaChoice2 > dia2.size()) {
        cout << "Invalid choice!\n";
        return 1;
    }

    string selected2 = dia2[diaChoice2 - 1];

    // Show result
    cout << "\n===== RESULT =====\n";
    cout << "First dialect:  " << selected1 << "\n";
    cout << "Second dialect: " << selected2 << "\n";
    cout << "Common ancestor: " << findCommonAncestor(root, selected1, selected2) << "\n";
    cout << "==================\n";

    cout << "\nPress Enter to exit...";
    cin.get();
    cin.get();

    return 0;
}

#include"trie.cpp"

int main(){

    Trie *T = new Trie();
    ifstream input;
    input.open("input.txt");

    while(!input.eof()){
        string s;
        input>>s;
        T->insert(s);
        //cout<<"Inserted "<<s<<"\n";
    }
    cout<<"Search------------------------"<<"\n";
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        cout<<T->search(s)<<" matched\n";
    }
    return 0;
}
#include "FonctionCode.h"


bool verifPonct(string expr)
{
    int i(0);
    bool trouve=false;
    string ponctuation[6]={".",",",";",":","?","!"};

    while(i<6 && trouve == false)
    {
        if(strcmp(expr.c_str(),ponctuation[i].c_str()) == 0)
            trouve=true;
        else
            i++;
    }
    return trouve;

}

int verif(string expr,vector<occurrence> tab)
{
    int trouve=0;
    int i=0;
    int n=tab.size();
   while((trouve==0) && (i<n))
    {
        if(strcmp(expr.c_str(),(tab[i].getMot()).c_str()) == 0)
            trouve=1;
        else
            i++;
    }
    return trouve;
}

string minuscule(string ch)
{
    for(int k=0;k<ch.size();k++)
                ch[k]=tolower(ch[k]);

               return ch;


}

int verif(string expr,map<string,int> dict) //renvoie 1 si l'expression existe dans la map et 0 sinon
{
    int trouve=0;
    map<string,int>::iterator it=dict.begin();
   while((trouve==0) && (it!=dict.end()))
    {
        if(strcmp(expr.c_str(),(it->first).c_str()) == 0)
            trouve=1;
        else
            ++it;
    }
    return trouve;
}

vector<string> elimStopWords(string cheminstopWords,vector<string> req){

    vector<string> reqSansStopWords;
    bool isStopWord;

    for(int i=0;i<req.size();i++){
        ifstream fichStopWords(cheminstopWords.c_str());

        if(fichStopWords){
            string ligne;
            isStopWord = false;

            while(getline(fichStopWords,ligne)){
                if(strcmp(ligne.c_str(),req[i].c_str()) == 0)
                    isStopWord = true;
            }

            if(!isStopWord)
                reqSansStopWords.push_back(req[i]);
        }
        else
            cout<<"operation impossible"<<endl;
        }

    return reqSansStopWords;

}
